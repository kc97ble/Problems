{$A+,B-,D+,E+,F-,G+,I+,L+,N+,O-,P+,Q+,R+,S+,T-,V-,X+,Y+}
{$M 65520,0,655360}

program circles_draw;

uses
  symbols, graph, crt;

var
  fx, fy, lb, rb, m, xr, yr: real;
  x, y, r: array [0..100] of real;
  i, n: longint;
  gm, gd: integer;
  scale: double;

function dist(x1, y1, x2, y2: real): real;
begin
  dist := sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
end;

function check(x1, y1, x2, y2: real): boolean;
var
  i: longint;
begin
  if (abs(x1 - x2) < 1e-3) and (abs(y1-y2) < 1e-3) then
  begin
    fx := (x1 + x2) / 2;
    fy := (y1 + y2) / 2;

    check := false;
    exit;
  end;

  check := true;
  for i := 1 to n do
  begin
    if (dist(x1, y1, x[i], y[i]) <= r[i] + m) and
       (dist(x1, y2, x[i], y[i]) <= r[i] + m) and
       (dist(x2, y1, x[i], y[i]) <= r[i] + m) and
       (dist(x2, y2, x[i], y[i]) <= r[i] + m) then
    begin
      exit;
    end;
  end;

  check := check(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2) and
           check((x1 + x2) / 2, y1, x2, (y1 + y2) / 2) and
           check(x1, (y1 + y2) / 2, (x1 + x2) / 2, y2) and
           check((x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
end;

function px(x: real): longint;
begin
  px := round(20 + x * scale);
end;

begin
  assign(input, 'input.txt');
  reset(input);
  assign(output, 'output.txt');
  rewrite(output);

  read(xr, yr);
  read(n);

  for i := 1 to n do
    read(x[i], y[i], r[i]);

  lb := 0;

  if (xr < yr) then rb := xr / 2 else rb := yr / 2;

  gd := vga;
  gm := vgahi;
  initgraph(gd, gm, '');

  scale := 600 / xr;
  if 440 / yr < scale then scale := 440 / yr;

  while abs(lb - rb) > 1e-4 do
  begin
    m := (lb + rb) / 2;

    if check(m, m, xr - m, yr - m) then
    begin
      rb := m;
    end
    else
    begin
      lb := m;
    end;
  end;

  m := (lb + rb) / 2;
  check(m, m, xr - m, yr - m);
  writeln(fx :0 :3, ' ', fy :0 :3, ' ', m :0 :3);

  close(input);
  close(output);

  cleardevice;

  setcolor(white);
  outtextxy(0, 0, realstr(lb, 0, 4) + ' ' + realstr(rb, 0, 4));

  rectangle(px(0), px(0), px(xr), px(yr));

  setcolor(yellow);
  for i := 1 to n do
  begin
    circle(px(x[i]), px(y[i]), round((r[i]) * scale));
  end;

  setcolor(lightcyan);
  circle(px(fx), px(fy), round(m * scale));

  readkey;

  closegraph;
end.