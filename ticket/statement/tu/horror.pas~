Const
Fi='';//horror.inp';
Fo='';//horror.out';

Type
        Film = Record
        lk,sk:Longint;
        End;
        mang = array[0..10] of Longint;

Var
F       :Text;
N,s     :Longint;
Movie   :array[0..10] of Film;
kq,k    :array[0..10] of Longint;
D       :array[0..10] of Boolean;

Procedure nhap;
Var i:Longint;
Begin
        Assign(F,Fi) ; Reset(F);
        Readln(F,N);dec(N);
        For i:= 0 to N do
        Readln(F,Movie[i].lk,Movie[i].sk);
        ClosE(F);
End;

Procedure update(k:mang;sl:Longint);
Var i:Longint;
Begin
        If sl <= s then exit
        Else s:=sl;
        For i:= 0 to N do
        If D[i] then
        Begin
                inc(sl) ; k[sl]:=i;
        End;
        kq:=k;
End;

Procedure Back(Fear:Real;k:mang;sl:Longint);
Var
i,T:Longint;
tg:Real;
Begin
        For i:= 0 to N do
        If D[i] then
        Begin
                D[i]:=False;tg:=Fear;
                tg:= tg - Movie[i].sk ;
                k[sl+1]:=i;
                If tg < -0.5 then update(k,sl+1)
                Else
                Begin
                        tg:= tg + 47 - (Movie[i].lk-movie[i].sk);
                        Back(tg,k,sl+1);
                End;
                D[i]:=true;
        End;
End;

Procedure xuly;
Var i:Longint;
Begin
        Fillchar(D,sizeof(D),true);
        Fillchar(k,sizeof(k),255);
        s:=-1;
        For i:= 0 to N do kq[i]:=i;
        Back(74,k,-1);
End;

Procedure inkq;
Var i:Longint;
Begin
        Assign(F,Fo) ; Rewrite(F);
        For i:= 0 to N do writeln(F,kq[i]);
        ClosE(F);
End;

BEGIN
        NHAP;
        XULY;
        INKQ;
END.
