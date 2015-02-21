program foxbomb;
type int=longint;
     link=^node;
     node=record
       value:int;
       next:link;
     end;
const max=50+10;
var S:array[1..max]of string;
    n:int;
    A:array[1..max*max]of link;
    f1,f2:text;
    free:array[1..max*max]of boolean;
    Num,dd,Low,Dad:array[1..max*max]of int;
    Count:int;


procedure ReadData;
var i:int;
begin
  assign(f1,'');reset(f1);
  assign(f2,'');rewrite(f2);
  readln(f1,n);
  for i:=1 to n do readln(f1,S[i]);
//  for i:=1 to n do writeln(length(S[i]));
end;

function Code(i,j:int):int;
begin
  Exit(length(S[i])*(i-1)+j);
end;

procedure Add(const u,v:int);
var p:link;
begin
//  writeln(u,' ',v);
  new(p);
  p^.value:=v;
  p^.next:=A[u];
  A[u]:=p;
end;

procedure Graph;
var i,j,i1,j1:int;
begin
  for i:=1 to n do
    for j:=1 to length(S[i]) do
      if S[i][j]<>'#' then
        begin
          Add(Code(i,j),Code(i,j));
          i1:=i+1;
          j1:=j;
          while (i1<=n)and (S[i1][j1]<>'#') do
            begin
              Add(Code(i,j),Code(i1,j1));
              Add(Code(i1,j1),Code(i,j));
              inc(i1);
            end;
          i1:=i;
          j1:=j+1;
          while (j1<=length(S[i]))and (S[i1][j1]<>'#') do
            begin
              Add(Code(i,j),Code(i1,j1));
              Add(Code(i1,j1),Code(i,j));
              inc(j1);
            end;
        end;
end;

procedure DFSK(u:int);
var p:link;
    t,v:int;
begin
  inc(Count);
  Low[u]:=n*length(S[1])+1;
  Num[u]:=Count;
  p:=A[u];
  t:=0;
  while p<>nil do
    begin
      v:=p^.value;
      if Num[v]=0 then
        begin
          Dad[v]:=u;
          DFSK(v);
          if Dad[u]=0 then
            begin
              inc(t);
              if t>1 then free[u]:=true;
            end
          else
            begin
              if Low[v]>=Num[u] then free[u]:=true;
            end;
          if Low[v]<Low[u] then Low[u]:=Low[v];
        end
      else
        begin
          if Dad[u]<>v  then
            if Num[v]<Low[u] then Low[u]:=Num[v];
        end;
      p:=p^.next;
    end;
end;

function Check(u:int):boolean;
var v:int;
    p:link;
begin
  p:=A[u];
  while p<>nil do
    begin
      v:=p^.value;
      if dd[v]<2 then Exit(false);
      p:=p^.next;
    end;
  Exit(true);
end;

procedure Decr(u:int);
var v:int;
    p:link;
begin
  p:=A[u];
  while p<>nil do
    begin
      v:=p^.value;
      dec(dd[v]);
      p:=p^.next;
    end;
end;

procedure Run;
var i,cnt,u,v:int;
    p:link;
begin
  ReadData;
  Graph;
  for i:=1 to n*length(S[1]) do
    if Num[i]=0 then DFSK(i);
  cnt:=0;
  for i:=1 to n*length(S[1]) do
    if free[i] then
      begin
        inc(cnt);
        p:=A[i];
        while p<>nil do
          begin
            v:=p^.value;
            inc(dd[v]);
            p:=p^.next;
          end;
      end;
  for i:=1 to n*length(S[1]) do
    if free[i] then
      begin
        if Check(i) then
          begin
            Decr(i);
            dec(cnt);
          end;
      end;
  writeln(f2,cnt);
end;

begin
  Run;
  close(f1);
  close(f2);
end.
