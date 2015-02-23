CONST
        Fi = '';//'horror.inp';
        Fo = '';//'horror.out';
VAR
        F : text;
        n,t,sl,kq1 : longint;
        l,s : array[1..7] of longint;
        kq: array[0..8] of longint;
        d : array[0..8] of boolean;
        ok,co : boolean;

procedure doc;
var i,j : longint;
begin
    assign(F,Fi); reset(F);
    t := 74;
    readLn(F,n);
    for i:=1 to n do readLn(F,l[i],s[i]);
    close(F);
end;

procedure dq(i : longint);
var j : longint;
begin
    if co then exit;
    if i > n then
    begin
        co := true;
        for j:=1 to n do writeLn(F,kq[j]-1);
        exit;
    end;

    for j:=1 to n do
    begin
        ok := true;
        if not d[j] then
        begin
            if (t >= s[j])
            and ( t + 47 >= l[j]) then
            begin
                ok := false;
                inc(sl);
                t := t + 47 - l[j];
                d[j] := true;
                kq[i] := j;
                dq(i+1);
                d[j] := false;
                t := t + l[j] - 47;
                dec(sl);
            end;
        end;
    end;
    if ok then
        begin
            co := true;
            fillchar(d,sizeof(d),false);
            for i:= 1 to sl do
            begin
                writeLn(F,kq[i]-1);
                d[kq[i]] := true;
            end;
            for i:=1 to n do if not d[i] then writeLn(F,i-1);
            exit;
        end;
end;

procedure ghi;
var i,j : longint;
begin
    assign(F,Fo); rewrite(F);
    dq(1);
    close(F);
end;

BEGIN
    doc;
    ghi;
END.

