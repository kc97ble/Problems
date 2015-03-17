CONST
        Fi = '';//'seating.inp';
        Fo = '';//'seating.out';
TYPE
        TT = record x,y : int64;
        end;
VAR
        F : text;
        n,m,k : longint;
        a : array[0..50] of TT;

procedure doc;
var i,j : longint;
begin
    assign(F,Fi); reset(F);
    readLn(F,n,m,k);
    for i:=1 to k do
        readLn(F,a[i].x,a[i].y);
    close(F);
end;

procedure hv(var x,y : TT);
var z : TT;
begin
    z := x;
    x := y;
    y := z;
end;

function ss (a,b : TT):boolean;
begin
    if a.x < b.x then exit(true);
    if a.x > b.x then exit(false);
    if a.y < b.y then exit(true);
    exit(False);
end;

procedure QS(Csd,csc : longint);
var l,r : longint;
    p : TT;
begin
    if csd >= csc then exit;
    l := csd; r := csc;
    p := a[(l+r) div 2];
    repeat
        while ss(a[l],p) do inc(l);
        while ss(p,a[r]) do dec(r);
        if l <= r then
        begin
            hv(a[l],a[r]);
            inc(l);
            dec(r);
        end;
    until l > r;
    QS(csd,r);
    QS(l,csc);
end;

procedure ghi;
var i,j: longint;
    kq,dd,dc : int64;
begin
    assign(F,Fo); rewrite(F);
    QS(1,k);
    kq := 0;
    for i:=1 to k do
    begin
        if a[i].x = a[i-1].x then
        begin
           dc := a[i].y - a[i-1].y - 1;
           kq := kq + dc-1;
        end
        else
        begin
            if(a[i-1].y < m) and (a[i-1].x > 0) then
                 kq := kq + m - a[i-1].y - 1;
            if a[i].y > 1 then kq := kq + a[i].y - 1 - 1 ;
            kq := kq + (a[i].x - a[i-1].x - 1)*(m-1);
        end;
    end;
    if a[k].y < m then kq := kq + m - a[k].y - 1;
    if a[k].x < n then kq := kq + (n - a[k].x)*(m-1);
    writeLn(F,kq);
    close(F);
end;

BEGIN
    doc;
    ghi;
END.

