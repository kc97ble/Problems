program gather;
type int=longint;
     link=^node;
     node=record
       value,len:int;
       next:link;
     end;
const max=100000+10;
var A:array[1..max]of link;
    C,Sc:array[1..max]of int64;
    free:array[1..max]of boolean;
    F:array[1..max]of int64;
    n:int;
    f1,f2:text;

procedure Add(const u,v,l:int);
var p:link;
begin
  new(p);
  p^.value:=v;
  p^.len:=l;
  p^.next:=A[u];
  A[u]:=p;
end;

procedure ReadData;
var i,u,v,l:int;
begin
  assign(f1,'');reset(f1);
  assign(f2,'');rewrite(f2);
  readln(f1,n);
  for i:=1 to n do readln(f1,C[i]);
  for i:=1 to n-1 do
    begin
      readln(f1,u,v,l);
      Add(u,v,l);
      Add(v,u,l);
    end;
end;

procedure DFS_(u,x:int);
var v,l:int;
    p:link;
begin
  free[u]:=false;
  p:=A[u];
  while p<>nil do
    begin
      v:=p^.value;
      l:=p^.len;
      if free[v] then
        begin
          DFS_(v,x+l);
          F[1]:=F[1]+C[v]*(x+l);
          Sc[u]:=Sc[u]+Sc[v];
        end;
      p:=p^.next;
    end;
  inc(Sc[u],C[u]);
end;

procedure DFS(u:int);
var l,v:int;
    p:link;
begin
  free[u]:=false;
  p:=A[u];
  while p<>nil do
    begin
      v:=p^.value;
      l:=p^.len;
      if free[v] then
        begin
          F[v]:=F[u]-Sc[v]*l+(Sc[1]-Sc[v])*l;
          DFS(v);
        end;
      p:=p^.next;
    end;
end;

procedure Process;
var i,j,min:int;
begin
  fillchar(free,sizeof(free),true);
  DFS_(1,0);
  fillchar(free,sizeof(free),true);
  DFS(1);
  min:=F[1];
  for i:=2 to n do
    if min>F[i] then min:=F[i];
  writeln(f2,min);
end;

procedure Run;
begin
  ReadData;
  Process;
end;

begin
  Run;
  close(f1);
  close(f2);
end.