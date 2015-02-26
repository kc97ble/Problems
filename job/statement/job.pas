program job;
type int=longint;
const max=100000+10;
var S,P:array[1..max]of int;
    n:int;
    f1,f2:text;
    TopMin:int;
    HeapMin:array[1..max]of int;

procedure ReadData;
var i,j:int;
begin
  assign(f1,'');reset(f1);
  assign(f2,'');rewrite(f2);
  readln(f1,n);
  for i:=1 to n do readln(f1,S[i],P[i]);
  inc(n);
  P[n]:=0;
  S[n]:=1;
end;

procedure Swap(var a,b:int);
var t:int;
begin
  t:=a;
  a:=b;
  b:=t;
end;


procedure QuickSort;

  procedure Sort(l,h:int);
  var i,j,k:int;
  begin
    if l>=h then Exit;
    i:=l;
    j:=h;
    k:=S[random(h-l+1)+l];
    repeat
      while S[i]>k do inc(i);
      while S[j]<k do dec(j);
      if i<=j then
        begin
          if i<j then
            begin
              Swap(S[i],S[j]);
              Swap(P[i],P[j]);
            end;
          inc(i);
          dec(j);
        end;
    until i>j;
    Sort(l,j);
    Sort(i,h);
  end;

begin
  Sort(1,n);
end;

procedure UpHeapMin(k:int);
var pp:int;
begin
  pp:=k div 2;
  while true do
    begin
      if k=1 then Exit;
      if P[HeapMin[pp]]>P[HeapMin[k]] then Exit;
      Swap(HeapMin[pp],HeapMin[k]);
      k:=pp;
      pp:=k div 2;
    end;
end;

procedure DownHeapMin(k:int);
var pp:int;
begin
  pp:=2*k;
  while true do
    begin
      if pp>TopMin then Exit;
      if P[HeapMin[pp]]<P[HeapMin[pp+1]] then pp:=pp+1;
      if P[HeapMin[k]]>P[HeapMin[pp]] then Exit;
      Swap(HeapMin[pp],HeapMin[k]);
      k:=pp;
      pp:=2*k;
    end;
end;

procedure Push(u:int);
begin
  inc(TopMin);
  HeapMin[TopMin]:=u;
  UpHeapMin(TopMin);
end;

function Pop:int;
begin
  Pop:=HeapMin[1];
  HeapMin[1]:=HeapMin[TopMin];
  dec(TopMin);
  DownHeapMin(1);
end;


procedure Process;
var i,j:int;
    kq:int64;
    c:int;
begin
  kq:=0;
  QuickSort; // for i:=1 to n do writeln(S[i],' ',P[i]);
  i:=1;
  j:=1;
  while true do
    begin
      Push(i);
      if S[i]<>S[i+1] then break;
      inc(i);
    end;
  kq:=kq+P[Pop];   // writeln(kq,' a');
  while true do
    begin
      c:=0;
      inc(i);
      while (c<S[j]-S[i]-1) and(TopMin>0) do
        begin
          kq:=kq+P[Pop];
          inc(c);
        //writeln(kq,' b');
        end;
      j:=i;
      if i=n+1 then break;
      while true do
        begin
          Push(i);
          if S[i]<>S[i+1] then break;
          inc(i);
        end;
      kq:=kq+P[Pop];// writeln(kq,' c');
      if i=n then break;
    end;
  writeln(f2,kq);
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