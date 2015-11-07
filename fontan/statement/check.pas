{$n+}
program check_c;

uses
  testlib, symbols;

const
  eps = 1e-2;

var
  xs, ys, xf, yf, rf, jrf: double;
  i, n: longint;
  x, y, r: array [0..100] of double;

begin
  xs := inf.readreal;
  ys := inf.readreal;
  n := inf.readlongint;
  for i := 1 to n do
  begin
    x[i] := inf.readreal;
    y[i] := inf.readreal;
    r[i] := inf.readreal;
  end;

  xf := ouf.readreal;
  yf := ouf.readreal;
  rf := ouf.readreal;

  ans.readreal;
  ans.readreal;
  jrf := ans.readreal;

  if rf < jrf - eps then
    quit(_wa, 'radius is wrong - expected: ' + realstr(jrf, 0, 3) +
      ', found: ' + realstr(rf, 0, 3));

  if xf < rf - eps then quit(_wa, 'fountain intersects left wall');
  if xf > xs - rf + eps then quit(_wa, 'fountain intersects right wall');
  if yf < rf - eps then quit(_wa, 'fountain intersects bottom wall');
  if yf > ys - rf + eps then quit(_wa, 'fountain intersects top wall');

  for i := 1 to n do
    if sqrt((x[i] - xf) * (x[i] - xf) + (y[i] - yf) * (y[i] - yf)) <
        r[i] + rf - eps then
      quit(_wa, 'fountain intersects column ' + str(i, 0));

  if rf > jrf + eps then
    quit(_fail, 'solution better then jury''s one !!! expected: ' +
      realstr(jrf, 0, 3) + ', found: ' + realstr(rf, 0, 3));

  quit(_ok, '');
end.