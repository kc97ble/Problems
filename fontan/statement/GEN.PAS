{$A+,B-,D+,E+,F-,G+,I+,L+,N+,O-,P+,Q+,R+,S+,T-,V-,X+,Y+}
{$M 65520,0,655360}

uses
  symbols;

label
  1;

var
  xx, yy: double;
  i, j, k, l, m, n: longint;
  x, y, r: array [0..100] of double;

function min(x, y: double): double;
begin
  if x < y then min := x else min := y;
end;

function outside(zx, zy: double; k: longint): boolean;
var
  i: longint;
begin
  outside := false;
  for i := 1 to k do
    if sqrt(sqr(x[i] - zx) + sqr(y[i] - zy)) < r[i] + 1e-2 then
      exit;
  outside := true;
end;

begin
  assign(output, paramstr(1));
  rewrite(output);
  randomize;

  xx := random(1000) * random + 1;
  yy := random(1000) * random + 1;
  writeln(xx :0 :4, ' ', yy :0 :4);

  n := longintval(paramstr(2));
  writeln(n);
  for i := 1 to n do
  begin
   1:
    repeat
      x[i] := random * xx;
      y[i] := random * yy;
    until outside(x[i], y[i], i-1);
    r[i] := random * min(xx, yy);
    if r[i] > x[i] then r[i] := x[i];
    if r[i] > xx - x[i] then r[i] := xx - x[i];
    if r[i] > y[i] then r[i] := y[i];
    if r[i] > yy - y[i] then r[i] := yy - y[i];
    if r[i] < 0.2 then goto 1;
    for j := 1 to i-1 do
      if sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])) < r[j] + r[i] then
        r[i] := sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])) - r[j];
    writeln(x[i] :0 :4, ' ', y[i] :0 :4, ' ', r[i] :0 :4);
  end;
end.