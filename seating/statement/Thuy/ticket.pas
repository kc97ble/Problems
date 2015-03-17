const fi='';//'ticket.inp';
      fo='';//'ticket.out';


Var b:array[1..4] of longint;
    F,kq:longint;
    ok:boolean;
    f1,f2:text;

Procedure nhap;
var i,j:longint;
begin
    Assign(f1,fi);
    reset(f1);
    read(f1,f);
    For i:=1 to 4 do
    read(f1,b[i]);

    close(f1);
    ok:=false;
end;

Procedure xuly1;
Var i,j:longint;
Begin
    For i:=1 to 4 do
    If b[i]=f then ok:=true;
    If b[1]+b[2]+b[3]+b[4]=f then ok:=true;
    If b[1]+b[2]=f then ok:=true;
     If b[1]+b[2]=f then ok:=true;
    If b[1]+b[3]=f then ok:=true;
    If b[1]+b[4]=f then ok:=true;
    If b[2]+b[3]=f then ok:=true;
    If b[2]+b[4]=f then ok:=true;
     If b[3]+b[4]=f then ok:=true;
     If b[1]+b[2]+b[3]=f then ok:=true;
     If b[1]+b[2]+b[4]=f then ok:=true;
     If b[1]+b[4]+b[3]=f then ok:=true;
     If b[4]+b[2]+b[3]=f then ok:=true;
end;

Procedure xuly2;
Var i,j:longint;
begin
    For i:=1 to (1 shl 4)-1 do
    Begin
        kq:=0;
        For j:=0 to 3 do
        If i and ( 1 shl j) <>0 then kq:=kq+b[j+1];
        if kq=f then ok:=true;
    end;
end;


Procedure inkq;
Begin
    Assign(f2,fo);
    rewrite(f2);
    If ok=true then writeln(f2,'POSSIBLE') else
    writeln(f2,'IMPOSSIBLE');
    close(f2);
end;

Begin
    nhap;
    xuly2;
    inkq;
end.
