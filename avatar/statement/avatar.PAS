uses math;
const
    fi = 'avatar.INP';
    fo = 'avatar.OUT';
    maxN = 50000;

type larr = array[0..maxN] of int64;
var d, p, //luu day d, p
    idd, idp, //luu chi so cua day d, p
    sd, sp: larr; //luu tong cac phan tu cua day d, p
    b, k, n, m, nd, np: longint; //nd, np: so phan tu duoc chon trong d, p

procedure swap(var a, b: int64);
var c: int64;
begin
    c := a;
    a := b;
    b := c;
end;

procedure sort(var a, id: larr; l, r: longint);
var i, j, x: longint;
begin
    i := l; j := r; x := a[l + random(r-l+1)];
    while (i < j) do
    begin
        while (a[i] > x) do inc(i);
        while (a[j] < x) do dec(j);
        if (i <= j) then
        begin
            swap(a[i], a[j]);
            swap(id[i], id[j]);
            inc(i); dec(j);
        end;
    end;
    if (i < r) then sort(a, id, i, r);
    if (l < j) then sort(a, id, l, j);
end;

procedure ReadData;
var f: text;
    i: longint;
begin
    assign(f, fi);
    reset(f);
    readln(f, b, k, n, m);
    for i := 1 to n do
    begin
        read(f, d[i]);
        idd[i] := i;
    end;
    for i := 1 to m do
    begin
        read(f, p[i]);
        idp[i] := i;
    end;
    close(f);
end;

procedure Init;
var i: longint;
begin
    sort(d, idd, 1, n);
    sort(p, idp, 1, m);
    sd[0] := 0; sp[0] := 0;
    nd := n; np := m; //gia su chon het
    for i := 1 to n do
        sd[i] := sd[i-1] + d[i];
    for i := 1 to m do
        sp[i] := sp[i-1] + p[i];
end;

procedure solve;
var s, maxv: real;
    x, y: longint;
begin
    Init;
    maxv := 0;
    for x := 0 to min(k, n) do
    begin
        y := min(k - x, m);
        s := (b + sd[x])*(100 + sp[y])/100;
        if (s > maxv) then
        begin
            maxv := s;
            nd := x;
            np := y;
        end;
    end
end;

procedure WriteANS;
var f: text;
    i: longint;
begin
    assign(f, fo);
    rewrite(f);
    writeln(f, nd, ' ', np);
    for i := 1 to nd do write(f, idd[i], ' ');
    writeln(f);
    for i := 1 to np do write(f, idp[i], ' ');
    writeln(f);
    close(f);
end;

begin
    ReadData;
    Solve;
    WriteANS;
end.
