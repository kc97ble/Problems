uses math;
const
    fi = 'AVATAR.INP';
    fo = 'AVATAR.OUT';
    fa = 'AVATAR.ANS';
    maxN = 50000;
    eps = 0.000001;

type larr = array[0..maxN] of int64;
var d, p: larr; //luu day d, p
    b, k, n, m, n1, n2, m1, m2: longint; //nd, np: so phan tu duoc chon trong d, p
    finp, fout, fans: text;
    ans, res: real;
    TestDir, WorkDir: string;

procedure OpenFiles;
begin
    Readln(TestDir);
    Readln(WorkDir);
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

Procedure ReadData;
var i: longint;
begin
    readln(finp, b, k, n, m);
    for i := 1 to n do
        read(finp, d[i]);
    for i := 1 to m do
        read(finp, p[i]);
end;

procedure TestOut;
var i, id: longint;
    x, y: int64;
begin
    Readln(fout, n1, m1);
    x := b; y := 100;
    for i := 1 to n1 do
    begin
        Read(fout, id);
        x := x + d[id];
    end;
    for i := 1 to m1 do
    begin
        Read(fout, id);
        y := y + p[id];
    end;
    ans := x*y;
end;

procedure Answer;
var i, id: longint;
    x, y: int64;
begin
    Readln(fans, n2, m2);
    x := b; y := 100;
    for i := 1 to n2 do
    begin
        Read(fans, id);
        x := x + d[id];
    end;
    for i := 1 to m2 do
    begin
        Read(fans, id);
        y := y + p[id];
    end;
    res := x*y;
end;

Procedure Marking;
begin
    ReadData;
    TestOut;
    Answer;
    Writeln('So vat pham toi da su dung: ', k);
    Writeln('So vat pham su dung:');
    writeln('- Tra loi: ', n1+m1);
    writeln('- Dap an: ', n2+m2);
    Writeln('Suc manh tang len:');
    writeln('- Tra loi: ', ans/100.0: 0:3);
    Writeln('- Dap an: ', res/100.0: 0: 3);
    if (res = ans) and (n1 + m1 <= k) then
    begin
        Writeln('Ket qua dung!');
        Writeln('1.0');
    end
    else
    begin
        Writeln('Ket qua sai!');
        Writeln('0.0');
    end;
end;

begin
    OpenFiles;
    Marking;
    CloseFiles;
end.
