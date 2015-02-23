const fi='';//'horror.inp';
      fo='';//'horror.out';
      maxn=6;


Var l,s:array[0..maxn] of longint;
    n,t:longint;
    kq1,sl,sl1:longint;
    chon,d,cs:array[0..maxn] of longint;
    f1,f2:text;

Procedure nhap;
Var i,j:longint;
Begin
    Assign(f1,fi);
    reset(f1);
    readln(f1,n);
    For i:=0 to n-1 do
    begin
        readln(f1,l[i],s[i]);

    end;
    sl1:=0;
    t:=74;
    close(f1);
end;

Procedure capnhat;
Var i,j:longint;
Begin
    If sl>sl1 then
    Begin
        sl1:=sl;
        For i:=0 to sl1 do
        cs[i]:=d[i];
        For i:=sl1+1 to n do
        For j:=0 to n-1 do
        If chon[j]=0 then
        cs[i]:=j;
    end;
end;

Procedure duyet(i:longint);
Var j:longint;
Begin
    If i=n then
    Begin
    sl:=n;
    capnhat ;
    end else
    Begin
        sl:=0;
        For j:=0 to 6 do
        If chon[j]=0 then
        Begin
            If (s[i]-t>=0) and (l[i]-s[i]+t+47>=0) then
            Begin
                chon[j]:=1;
                d[i]:=j;
                t:=l[i]-s[i]+t+47;
                inc(sl);
                duyet(i+1);
                chon[j]:=0;
                t:=-(l[i]-s[i])+t-47;
            end;
        end;
    end;
end;

Procedure inkq;
Var i,j:longint;
Begin
    Assign(f2,fo);
    rewrite(f2);
    For i:=1 to sl1 do
    write(f2,cs[i]);
    close(f2);
end;



Begin
    nhap;
    duyet(0);
   // xuly;
    inkq;
end.
