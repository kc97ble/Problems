Const
Fi='ticket.inp';
Fo='ticket.out';

Var
F       :Text;
S       :Longint;
ok      :Boolean;
a       :array[1..4] of Longint;
D       :array[1..4] of Boolean;

Procedure nhap;
Begin
        Assign(F,Fi) ; reset(F);
        Readln(F,s,a[1],a[2],a[3],a[4]);
        Close(F);
End;

Procedure Back(sum:Longint);
Var i:integer;
Begin
        If sum = S then ok:=true;
        For i:= 1 to 4 do
        If D[i] then
        Begin
                D[i]:=False;
                Back(sum+A[i]);
                D[i]:=true;
        end;
End;

Procedure xuly;
Begin
        Fillchar(D,sizeof(D),true);
        Back(0);
End;

Procedure inkq;
Begin
        Assign(F,Fo) ; Rewrite(F);
        If ok then write(F,'POSSIBLE')
        Else write(F,'IMPOSSIBLE');
        Close(F);
End;

BEGIN
        NHAP;
        XULY;
        INKQ;
END.