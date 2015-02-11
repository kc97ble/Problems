program EMBROIDERY;
uses math;
const fi='';
      fo='';
      md=60001;
type node=record
     x,y:real;
     end;
     re=record
     x,y:longint;
     end;
     tlist=array[1..md] of node;
var f1,f2:text;
    bit:array[1..md] of longint;
    a,b,c:array[1..md] of longint;
    n,r,d,dem,w:longint;
    u:array[1..2] of node;
    res:int64;
    e,g:tlist;
    q:array[1..md,1..2] of node;
    root:node;
    f:array[1..md] of re;
procedure mo;
begin
assign(f1,fi);
reset(f1);
assign(F2,fo);
rewrite(f2);
end;

procedure dong;
begin
close(F1);
close(f2);
end;

function sum(x:longint):longint;
begin
 if x<1 then
  begin
   sum:=0;
   exit;
  end;
  sum:=bit[x]+sum(x and (X-1));
end;

procedure up(x:longint);
var i:longint;
begin
i:=x;
 while i <=w do
 begin
  inc(bit[i]);
  i:=i+i and(1+ not i);
 end;
end;

operator > (a,b:node)c:boolean;
begin
if (A.x>b.x) or ((a.x=b.x) and(a.y>b.y)) then exit(True);
exit(False);
end;

procedure sort(l,h:longint; var s:tlist);
procedure quicksort(l,h:longint);
var i,j:longint;
    tg,p:node;
begin
if l>=h then exit;
i:=l; j:=h; p:=s[(l+h) div 2];
 repeat
  while p > s[i] do inc(i);
  while s[j] > p do dec(j);
  if i <= j then
  begin
  tg:=s[i];
  s[i]:=s[j];
  s[j]:=tg;
  inc(i); dec(j);
  end;
  until i>j;
quicksort(l,j);
quicksort(i,h);
end;
begin
quicksort(l,h);
end;

function giao(a,b,c:longint):boolean;
var del,k:real;
begin
if a=0 then
  begin
    del:=-c/b;
    k:=sqr(r)-sqr(del);
    if k<0 then exit(FalsE);
    u[1].x:=sqrt(k);
    u[2].x:=-sqrt(k);
    u[1].y:=(-c-a*u[1].x)/b;
    u[2].y:=(-c-a*u[2].x)/b;
  end
else
begin
  del:=(sqr(r)-sqr(c/a))/ (sqr(b/a)+1);
  if del <0 then exit(false);
  u[1].y:=sqrt(del);
  u[2].y:=-sqrt(del);
  u[1].x:=(-c-b*u[1].y)/a;
  u[2].x:=(-c-b*u[2].y)/a;
end;
end;

function goc(a,b:node):real;
begin
if a.x=b.x then goc:=pi/2
else
begin
  goc:=(a.y-b.y) / (a.x-b.x);
  goc:=arctan(goc);
end;
if (b.y <a.y) or ((b.y=a.y) and (b.x<a.x)) then goc:=goc+pi;
end;

function search(x:real):longint;
var l,r,m:longint;
begin
l:=1;
r:=w;
repeat
  m:=(l+r) div 2;
  if g[m].x>=x then begin search:=m; r:=m-1; end
  else l:=m+1;
until l>r;
end;

procedure solve;
var i,j,k:longint;
    t:array[1..2] of real;
begin
for i:=1 to n do
  begin
    if giao(a[i],b[i],c[i])=false then continue;
    inc(d);
    q[d]:=u;
  end;
root.x:=0;
root.y:=0;
for i:=1 to d do
  begin
    t[1]:=goc(root,q[i,1]);
    t[2]:=goc(root,q[i,2]);
    e[i].x:=min(t[1],t[2]);
    e[i].y:=max(t[1],t[2]);
    inc(dem);
    g[dem].x:=e[i].x;
    inc(dem);
    g[dem].x:=e[i].y;
  end;
sort(1,dem,g);
sorT(1,d,e);
w:=0;
for i:=1 to dem do
  if (i=1) or (g[i].x<>g[i-1].x) then begin inc(w); g[w].x:=g[i].x; end;
for i:=1 to dem do
begin
  f[i].x:=search(e[i].x);
  f[i].y:=search(e[i].y);
end;
i:=1;
repeat
  j:=i;
  up(f[i].y);
  while (j+1<=n) and (f[j+1].x=f[i].x) do
    begin
      inc(j);
      up(f[j].y);
      if e[j].y<0 then up(search(e[j].y+2*pi));
    end;
  for k:=i to j do
    inc(res,sum(f[k].y)-sum(f[k].x-1)-1);
  i:=j+1;
until i>d;
writeln(F2,reS);
end;

procedure nhap;
var i,j:longint;
begin
readln(F1,n,r);
for i:=1 to n do
  readln(F1,a[i],b[i],c[i]);
solve;
end;

BEGIN
mo;
nhap;
Dong;
END.