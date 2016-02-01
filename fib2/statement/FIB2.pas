const
    fi = 'FIB2.INP';
    fo = 'FIB2.OUT';

var len, count: array[0..45] of qword;

procedure Init;
var i: longint;
begin
    count[0] := 1; count[1] := 0;
    len[0] := 1; len[1] := 1;
    for i := 2 to 45 do
    begin
        count[i] := count[i-1] + count[i-2];
        len[i] := len[i-1] + len[i-2];
    end;
end;

function Fib(n, k: qword): qword;
begin
    if (n <= 1) then exit(count[n]);
    if (k > len[n-2]) then
        exit(count[n-2] + Fib(n-1, k - len[n-2]));
    exit(Fib(n-2, k));
end;

procedure Solve;
var f, g: text;
    i, T: longint;
    n, k: int64;
begin
    Init;
    assign(f, fi); reset(f);
    assign(g, fo); rewrite(g);
    readln(f, T);
    for i := 1 to T do
    begin
        readln(f, n, k);
        writeln(g, Fib(n,k));
    end;
    close(f); close(g);
end;

begin
    Solve;
end.
