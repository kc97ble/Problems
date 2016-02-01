uses math;
const
    fi = 'TEAM.INP';
    fo = 'TEAM.OUT';

var f: text;
    m, n, k: int64;

function solve: int64;
var p, q: int64;
begin
    p := m div 2;
    k := k - m mod 2;
    if (p < n) then
    begin
        k := k - (n - p);
        n := p;
    end
    else
    begin
        k := k - (p - n)*2;
        p := n;
    end;
    if (k <= 0) then exit(n);
    q := 2*k div 3;
    solve := min(n - (k - q), (2*p - q) div 2); //x + y = k
end;

begin
    assign(f, fi); reset(f);
    readln(f, m, n, k);
    close(f);
    assign(f, fo); rewrite(f);
    write(f, solve);
    close(f);
end.
