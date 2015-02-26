program knight;
const
  fin = '';
  fout = '';
  nmax = 200;
  pmax = 13;
  smax = 1 shl pmax - 1;
  hmax = nmax * (smax + 1);
  mmax = 6000;
type
  tpair = array[1..2] of longint;
  tlink = record
    v, n, c, x: longint;
    end;
var
  d, p: array[1..nmax, 0..smax] of longint;
  h: array[1..hmax] of tpair;
  a: array[1..mmax] of tlink;
  q, b: array[1..nmax] of longint;
  n, m: longint;
  nh, res: longint;

procedure open;
begin
  assign(input, fin); reset(input);
  assign(output, fout); rewrite(output);
end;

procedure push(u, v, c, x, i: longint);
begin
  a[i].v := v;
  a[i].c := c;
  a[i].x := x;
  a[i].n := b[u];
  b[u] := i;
end;

procedure enter;
var
  i, j: longint;
  u, v: longint;
  x, y: longint;
  c, t: longint;
begin
  read(n, m, i, t);
  for i := 1 to t do
    begin
      read(u, v);
      for j := 1 to v do
        begin
          read(x);
          q[u] := q[u] or (1 shl (x - 1));
        end;
    end;
  for i := 1 to m do
    begin
      read(u, v, c, y);
      x := 0;
      for j := 1 to y do
        begin
          read(t);
          x := x or (1 shl (t - 1));
        end;
      push(u, v, c, x, i);
      push(v, u, c, x, i + m);
    end;
end;

procedure push(u, s: longint);
var
  i, j: longint;
begin
  if p[u, s] = 0 then
    begin
      inc(nh);
      i := nh;
    end
  else
    i := p[u, s];
  while i > 1 do
    begin
      j := i shr 1;
      if d[u, s] >= d[h[j, 1], h[j, 2]] then
        break;
      h[i] := h[j];
      p[h[i, 1], h[i, 2]] := i;
      i := j;
    end;
  h[i, 1] := u;
  h[i, 2] := s;
  p[u, s] := i;
end;

procedure pop(var u, s: longint);
var
  i, j: longint;
  t: tpair;
begin
  u := h[1, 1];
  s := h[1, 2];
  t := h[nh];
  dec(nh);
  if nh = 0 then exit;
  i := 1;
  while i shl 1 <= nh do
    begin
      j := i shl 1;
      if (j < nh) and (d[h[j + 1, 1], h[j + 1, 2]] <= d[h[j, 1], h[j, 2]]) then
        inc(j);
      if d[t[1], t[2]] <= d[h[j, 1], h[j, 2]] then
        break;
      h[i] := h[j];
      p[h[i, 1], h[i, 2]] := i;
      i := j;
    end;
  h[i] := t;
  p[t[1], t[2]] := i;
end;

procedure solve;
var
  u, s, v, x, i, c: longint;
begin
  res := -1;
  push(1, q[1]);
  repeat
    pop(u, s);
    if u = n then
      begin
        res := d[u, s];
        exit;
      end;
    i := b[u];
    while i > 0 do
      begin
        v := a[i].v;
        c := a[i].c;
        x := a[i].x;
        i := a[i].n;
        if x and (not s) > 0 then
          continue;
        x := q[v] or s;
        if (p[v, x] = 0) or (d[v, x] > d[u, s] + c) then
          begin
            d[v, x] := d[u, s] + c;
            push(v, x);
          end;
      end;
  until nh = 0;
end;

procedure print;
begin
  write(res);
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