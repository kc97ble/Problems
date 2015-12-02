uses math;
const cs = 1000000000;
      Base = 9;

Type Big = record
Max : longint;
A:array[1..100] of longint;
End;
const maxn=301;
cmod = 100000;
type pair = record
y,x:longint;
end;
type mang = array[1..maxn,1..maxn] of pair;

var f1,f2:text;
A,B:mang;
R:array[1..maxn,1..maxn] of char;
Count:array[1..maxn,1..maxn] of longint;
Next:array[1..maxn,1..maxn] of pair;
free:array[1..maxn,1..maxn] of longint;
n,m,sd,i,j:longint;
S:array[1..maxn,1..maxn] of longint;
G:array[0..maxn*maxn] of longint;
T:array[0..maxn*maxn] of pair;
kq:array[1..maxn*maxn] of longint;
dem:longint;
tk:ansistring;
k:big;
s1:big;
temp:char;
tt:longint;
sk:big;

Function Con(s:longint):Big;
Begin
        FIllchar(con.a,sizeof(con.a),0);
        Con.a[1]:=s;
        Con.max:=1;
End;

Procedure Chia(var so:Big;s:longint;var rem:longint);
var i,j:longint;
t:int64;
Begin
        Rem:=0;
        for i:=so.max downto 1 do
        Begin
          t:=so.A[i]+int64(Rem)*cs;
          so.A[i]:=t div s;
          Rem:=t Mod s;
        End;
        if so.A[so.max]=0 then dec(so.max);

End;

Procedure ROTR(y,x:longint;var A:mang);
var tg:pair;
begin
        tg:=A[y,x];
        a[y,x]:=A[y+1,x];
        A[y+1,x]:=A[y+1,x+1];
        A[y+1,x+1]:=A[y,x+1];
        A[y,x+1]:=tg;
end;

Procedure ROTL(y,x:longint;var A:mang);
var tg:pair;
begin
        tg:=A[y,x];
        A[y,x]:=A[y,x+1];
        A[y,x+1]:=A[y+1,x+1];
        A[y+1,x+1]:=A[y+1,x];
        A[y+1,x]:=tg;
end;

Procedure DFS(y,x:longint);
begin
        free[y,x]:=tt;
        inc(dem);
        G[dem]:=G[dem-1]+Count[y,x];
        T[dem]:=Next[y,x];
        if free[Next[y,x].y,Next[y,x].x]<>tt then
        begin
          DFS(Next[y,x].y,Next[y,x].x);
        end
        else
          exit;
end;

Function mp(y,x:longint):pair;
begin
        mp.y:=y;mp.x:=x;
end;

Procedure process2;
var i,j:longint;
begin
        s1:=con(1);
        for i:=1 to n-1 do
        for j:=1 to m-1 do
        begin
          dec(sd);
          kq[(b[i,j].y-1)*m+b[i,j].x]:=(kq[(b[i,j].y-1)*m+b[i,j].x]+1) mod cmod;
          if R[i,j]='R' then ROTR(i,j,b);
          if R[i,j]='L' then ROTL(i,j,b);
          if sd=0 then exit;
        end;
end;

Function CHMOd(v:big):longint;
begin
        Chmod:=v.a[1] mod cmod
end;

procedure process;
var i,j,x,vrem:longint;
vd:big;
begin
        for i:=1 to n-1 do
        for j:=1 to m-1 do
        Begin
          inc(count[a[i,j].y,a[i,j].x]);
          if R[i,j]='R' then ROTR(i,j,A);
          if R[i,j]='L' then ROTL(i,j,A);
        End;
        For i:=1 to n do
        for j:=1 to m do
        begin
          Next[a[i,j].y,a[i,j].x]:=mp(i,j);
        end;
        for i:=1 to n do
        for j:=1 to m do
        begin
          inc(tt);
          dem:=0;
          T[0]:=mp(i,j);
          DFS(i,j);
          if dem=0 then writeln(f2,0) else
          vd:=sk;
          chia(vd,dem,vrem);
          Kq[(i-1)*m+j]:=(int64(G[dem])*CHMOD(vd)+G[vrem]) mod cmod;
          B[T[vrem].y,T[vrem].x]:=mp(i,j);
        end;
        process2;
        for i:=1 to n*m do
        writeln(f2,kq[i]);
end;

Procedure Convert(var SA:Ansistring;var A : Big);
var i:longint;
Code:longint;
Begin
        i:=length(SA)-Base+1;
        A.max:=0;
        Fillchar(A.A,sizeof(A.A),0);
        While i>=1 do
        Begin
          Inc(A.Max);
          Val(Copy(SA,i,Base),A.A[A.Max],Code);
          i:=i-Base;
        End;
        i:=i+base-1;
        Inc(A.Max);
        Val(Copy(SA,1,i),A.A[A.Max],Code);
End;

begin
        assign(f1,'');reset(f1);
        assign(f2,'');rewrite(f2);
        readln(f1,n,m,temp,tk);
        convert(tk,k);
        for i:=1 to n do for j:=1 to m do begin a[i,j]:=mp(i,j); end;
        for i:=1 to n-1 do
        begin
        for j:=1 to m-1 do
        read(f1,R[i,j]);
        readln(f1);
        end;
        sk:=k;
        chia(sk,(n-1)*(m-1),sd);
        process;
        close(f1);
        close(F2);
end.
