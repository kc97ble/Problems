program growth;
const
  fin = '';
  fout = '';
  nmax = 50;
type
  tvec = record
    x, y: longint;
    end;
var
  a, s: array[1..nmax + 1] of tvec;
  n, m: longint;
  res: longint;

procedure open;
begin
  assign(input, fin); reset(input);
  assign(output, fout); rewrite(output);
end;

procedure enter;
var
  i: longint;
begin
  read(n);
  for i := 1 to n do
    read(a[i].x);
  for i := 1 to n do
    read(a[i].y);
end;

procedure swap(var a, b: tvec);
var
  c: tvec;
begin
  c := a; a := b; b := c;
end;

function ccw(a, b: tvec): longint;
begin
  exit(a.x * b.y - a.y * b.x);
end;

function less(a, b, c: tvec): boolean;
begin
  with a do
    begin
      x := x - c.x;
      y := y - c.y;
    end;
  with b do
    begin
      x := x - c.x;
      y := y - c.y;
    end;
  exit(ccw(a, b) < 0);
end;

procedure sort(i, j: longint);
var
  l, r: longint;
  x: tvec;
begin
  if i >= j then
    exit;
  l := i; r := j;
  x := a[random(r - l + 1) + l];
  repeat
    while less(a[l], x, a[1]) do inc(l);
    while less(x, a[r], a[1]) do dec(r);
    if l <= r then
      begin
        if l < r then
          swap(a[l], a[r]);
        inc(l); dec(r);
      end;
  until l > r;
  sort(i, r); sort(l, j);
end;

procedure solve;
var
  i, j: longint;
begin
  j := 1;
  for i := 1 to n do
    if (a[j].x < a[i].x) or ((a[j].x = a[i].x) and (a[j].y < a[j].x)) then
      j := i;
  swap(a[1], a[j]);
  sort(2, n);
  a[n + 1] := a[1];
  m := 1;
  s[1] := a[1];
  for i := 2 to n + 1 do
    begin
      while (m > 1) and less(a[i], s[m], s[m - 1]) do
        dec(m);
      inc(m);
      s[m] := a[i];
    end;
  for i := 1 to m - 1 do
    res := res + (s[i].x - s[i + 1].x) * (s[i].y + s[i + 1].y);
end;

procedure print;
begin
  write(abs(res) / 2 : 0 : 1);
end;

procedure save;
begin
  close(input); close(output);
end;

begin
  open;
  enter;
  solve;
  print;
  save;
end.

4 
0 3 6 10 
0 3 6 10 

0.0 

4 
10 15 3 37 
49 49 12 8 

745.5 