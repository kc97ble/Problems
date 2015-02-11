program elephant;
const
  fin = '';
  fout = '';
  nmax = 50;
  oo = trunc(1e9);
var
  s, a, b, p, w: array[0..nmax] of longint;
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
  for i := 0 to n - 1 do
    read(w[i]);
  for i := 0 to n - 1 do
    read(p[i]);
end;

procedure solve;
var
  i, j, c: longint;
begin
  c := oo;
  for i := 0 to n - 1 do
    if w[i] > 0 then
      begin
        j := i;
        inc(m);
        a[m] := oo;
        repeat
          inc(s[m], w[j]);
          if w[j] < a[m] then
            a[m] := w[j];
          w[j] := -1;
          inc(b[m]);
          j := p[j];
        until j = i;
        if a[m] < c then c := a[m];
      end;
  for i := 1 to m do
    begin
      if b[i] = 1 then
        continue;
      if s[i] + (b[i] - 2) * a[i] < s[i] + a[i] + b[i] * c then
        res := res + s[i] + (b[i] - 2) * a[i]
      else
        res := res + s[i] + a[i] + (b[i] + 1) * c
    end;
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