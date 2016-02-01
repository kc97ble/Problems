const
    fi = 'DELIVERY.INP';
    fo = 'DELIVERY.OUT';
    fa = 'DELIVERY.ANS';
    errMsg: array[0..7] of string =
        ('Ket qua dung!',
         'Bai toan co loi giai nhung tra loi khong co!',
         'So buoc lat thung hang qua lon!',
         'Thao tac lat chua ki tu khong hop le!',
         'Mat canh bao nam o day!',
         'Thung hang bi lan ra khoi phong!',
         'Bai toan khong co loi giai nhung tim ra ket qua!',
         'O ket thuc khong phai o mong doi!');

var m,n,b,c,d:longint;
    sp: char;
    s: ansistring;
    aa: ansistring;
    x,y: longint;
    p: char;
    i: longint;
    finp, fans, fout: text;
    TestDir, WorkDir: string;

procedure OpenFiles;
begin
    Readln(TestDir);
    Readln(WorkDir);
    //testDir := 'd:\Data\GiangDay\ChuyenTin\BaiTapDayChuyen\DoiTuyen\2015\DT_12092015\DELIVERY\';
    //workDir := 'd:\Data\GiangDay\ChuyenTin\BaiTapDayChuyen\DoiTuyen\2015\DT_12092015\DELIVERY\';
    Assign(finp, TestDir + '\' + fi); Reset(finp);
    Assign(fans, TestDir + '\' + fa); Reset(fans);
    Assign(fout, WorkDir + '\' + fo); Reset(fout);
end;

procedure CloseFiles;
begin
    Close(finp);
    Close(fout);
    Close(fans);
end;

procedure RollLeft(var x, y: longint; var p: char);
begin
    dec(y);
    case p of
        'L': p:='!';
        'T': p:='L';
        'F': p:='F';
        'R': p:='T';
        'B': p:='B';
    end;
end;

procedure RollRight(var x, y: longint; var p: char);
begin
    inc(y);
    case p of
        'L':p:='T';
        'T':p:='R';
        'F':p:='F';
        'R':p:='!';
        'B':p:='B';
    end;
end;

procedure RollForward(var x, y: longint; var p: char);
begin
    inc(x);
    case p of
        'L':p:='L';
        'T':p:='F';
        'F':p:='!';
        'R':p:='R';
        'B':p:='T';
    end;
end;

procedure RollBackward(var x, y: longint; var p: char);
begin
    dec(x);
    case p of
        'L':p:='L';
        'T':p:='B';
        'F':p:='T';
        'R':p:='R';
        'B':p:='!';
    end;
end;


function Check: longint;
begin
    readln(finp, m, n, b, c, d);
    read(finp, sp);

    x:=1;
    y:=b;
    p:=sp;

    readln(fout, s);
    readln(fans, aa);

    if (s = 'IMPOSSIBLE') then
        if (aa = 'IMPOSSIBLE') then exit(0)
        else exit(1);

    if length(s) > 4*(m+n) then
        exit(2);

    for i:=1 to length(s) do
    begin
        if not (s[i] in ['L','R','F','B']) then
            exit(3);
        case s[i] of
            'L': RollLeft(x, y, p);
            'R': RollRight(x, y, p);
            'F': RollForward(x, y, p);
            'B': RollBackward(x, y, p);
        end;
        if p = '!' then
            exit(4);
        if (x<1) or (y<1) or (x>m) or (y>n) then
            exit(5);
    end;
    if (x=c) and (y=d) then
        if aa <> 'IMPOSSIBLE' then exit(0)
        else exit(6);
    exit(7);
end;

procedure marking;
var errCode: longint;
begin
    errCode := check;
    writeln('Tra loi: ', s);
    writeln('Dap an: ', aa);
    writeln(errMsg[errCode]);
    if (errCode = 0) then
        writeln('1.0')
    else writeln('0.0');
end;

begin
    OpenFiles;
    Marking;
    CloseFiles;
end.