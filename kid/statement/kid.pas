program kid;
const
  fin = '';
  fout = '';
  nmax = 100044;
var
  k, n, q: longint;
  a, b, f: array[1..nmax shl 1] of longint;
  u, v: array[1..nmax] of longint;
  w: longint;

procedure open;
begin
  assign(input, fin); reset(input);
  assign(output, fout); rewrite(output);
end;

procedure enter;
begin
  read(k, q);
end;

procedure swap(var u, v: longint);
var
  x: longint;
begin
  x := u; u := v; v := x;
end;

procedure sort_(i, j: longint);
var
  l, r: longint;
  x, y: longint;
begin
  if i >= j then
    exit;
  l := random(j - i + 1) + i;
  x := u[l]; y := v[l];
  l := i; r := j;
  repeat
    while (u[l] < x) or ((u[l] = x) and (v[l] < y)) do inc(l);
    while (x < u[r]) or ((x = u[r]) and (y < v[r])) do dec(r);
    if l <= r then
      begin
        if l < r then
          begin
            swap(u[l], u[r]); swap(v[l], v[r]);
          end;
        inc(l); dec(r);
      end;
  until l > r;
  sort_(i, r); sort_(l, j);
end;

procedure enter_;
var
  i, j: longint;
begin
  for i := 1 to q do
    begin
      read(u[i], v[i]);
      if u[i] > v[i] then swap(u[i], v[i]);
    end;
  sort_(1, q);
  j := 1;
  for i := 2 to q do
    if (u[i] > u[j]) or ((u[i] = u[j]) and (v[i] > v[j])) then
      begin
        inc(j);
        u[j] := u[i];
        v[j] := v[i];
      end;
  q := j;
  for i := 1 to q do
    begin
      a[i] := u[i];
      a[i + q] := v[i];
    end;
end;

procedure sort(i, j: longint);
var
  l, r: longint;
  x, y: longint;
begin
  if i >= j then
    exit;
  l := i; r := j;
  x := a[random(r - l + 1) + l];
  repeat
    while a[l] < x do inc(l);
    while x < a[r] do dec(r);
    if l <= r then
      begin
        if l < r then
          begin
            y := a[l]; a[l] := a[r]; a[r] := y;
          end;
        inc(l); dec(r);
      end;
  until l > r;
  sort(l, j); sort(i, r);
end;

function find(x: longint): longint;
var
  l, m, r: longint;
begin
  l := 1; r := n;
  repeat
    m := (l + r) shr 1;
    if a[m] = x then
      exit(m);
    if a[m] < x then
      l := m + 1
    else
      r := m - 1;
  until false;
end;

procedure init_;
var
  i: longint;
begin
  sort(1, q + q);
  n := 1;
  b[n] := 1;
  f[n] := -1;
  for i := 2 to q + q do
    if a[i] > a[n] then
      begin
        inc(n);
        a[n] := a[i];
        b[n] := 1;
        f[n] := -1;
      end
    else
      inc(b[n]);
  for i := 1 to q do
    begin
      u[i] := find(u[i]);
      v[i] := find(v[i]);
    end;
end;

function root(u: longint): longint;
begin
  if f[u] < 0 then
    exit(u);
  f[u] := root(f[u]);
  exit(f[u]);
end;

procedure union(u, v: longint);
begin
  if f[u] < f[v] then
    begin
      f[u] := f[u] + f[v];
      f[v] := u;
    end
  else
    begin
      f[v] := f[v] + f[u];
      f[u] := v;
    end;
end;

procedure print_;
var
  i: longint;
begin
  if q > k then
    begin
      writeln('N');
      exit;
    end;
  for i := 1 to q do
    begin
      if (b[u[i]] > 2) or (b[v[i]] > 2) then
        begin
          writeln('N');
          exit;
        end;
      u[i] := root(u[i]);
      v[i] := root(v[i]);
      if (not (f[u[i]] = -k)) and (u[i] = v[i]) then
        begin
          writeln('N');
          exit;
        end;
      union(u[i], v[i]);
    end;
  writeln('Y');
end;

procedure printInput;
var 
  i: longint;
begin
  if w < 696 then exit;
  if w = 696 then writeln(k, ' ', q);
  if w = 696 then for i := 1 to q do writeln(u[i],' ', v[i]);
end;

procedure solve;
begin
  enter_;
  init_;
  print_;
end;

procedure save;
begin
  close(input); close(output);
end;

begin
  w := 0;
  open;
  repeat
    inc(w);
    enter;
{    printInput;}
    if (k = 0) and (q = 0) then
      break;
    solve;
  until false;
  save;
end.

4 3 
2 3 
1 3 
2 1 
1000000000 0 
3 6 
3 2 
2 1 
1 2 
1 3 
2 3 
3 1 
0 0 
