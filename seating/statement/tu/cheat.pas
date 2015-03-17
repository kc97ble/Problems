Uses Math;
Const
Fi='';//cheat.inp';
Fo='';//cheat.out';

Var
F       :Text;
kq,N,sl :Longint;
s       :String;
D       :array[1..10] of Boolean;
A       :array[1..10000] of Longint;

Procedure nhap;
Begin
        Assign(F,Fi) ; Reset(F);
        Readln(F,S)  ;
        Close(F);
End;

Procedure Eratos;
Var
i,T:Longint;
Dau     :array[1..10000] of Boolean;
Begin
        Fillchar(dau,sizeof(dau),true);
        sl:=0; dau[1]:=False;
        For i:= 2 to 10000 do
        If dau[i] then
        Begin
                inc(sl) ; A[sl]:= i;
                T:= i*i;
                While T < 10000 do
                Begin
                        dau[T]:=False;
                        T:=T+i;
                End;
        End;
End;

Function check(S:string):Boolean;
Var
i,p,su:Longint;
x:int64;
Begin
        Val(S,x);
        If x = 0 then exit(true);
        su:=1  ;
        For i:= 1 to sl do
        If (A[i] <= round(sqrt(x))) then
        Begin
                p:=0;
                While (X mod A[i])=0 do
                Begin
                        inc(P);
                        X:= X div A[i] ;
                End;
                su:= su * (p+1);
                If su mod 2 = 0 then exit(False);
        End Else Break;
        If x > 1 then exit(False);
        If odd(su) then exit(true);
End;

Procedure Back(St:string;l:Longint);
Var
c:char;
s1:string;
i,e:Longint;
Begin
        If l >=kq then exit;
        If check(St) then
        Begin
                kq:= min(kq,l);
                exit;
        End;
        For i:= 1 to N do
        If D[i] then
        Begin
                D[i]:=False;
                For c:= '0' to '9' do
                If  c <> St[i] then
                Begin
                        s1:=st; s1[i]:=c;
                        Back(s1,l+1);
                End;
                D[i]:=true;
        End;
End;

Procedure xuly;
Var i:Longint;
Begin
        N:= Length(S);
        Eratos;
        Fillchar(D,sizeof(D),true);
        kq:=N;
        If check(S) then
        Begin
                kq:=0 ; exit;
        End;
        Back(S,0);
End;

Procedure inkq;
Begin
        Assign(F,Fo) ; RewritE(F);
        Writeln(F,kq);
        Close(F);
End;

BEGIN
        NHAP;
        XULY;
        INKQ;
END.
