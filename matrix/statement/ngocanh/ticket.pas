CONST
        Fi = '';//'ticket.inp';
        Fo = '';//'ticket.out';
VAR
        F : text;
        s : longint;
        b : array[1..4] of longint;

procedure doc;
var i,j : longint;
begin
    assign(F,Fi); reset(F);
    read(F,s);
    for i:=1 to 4 do read(F,b[i]);
    close(F);
end;

procedure ghi;
var i,j,sum : longint;
        ok :boolean;
begin
    assign(F,Fo); rewrite(F);
    ok := false;
    for i:=1 to (1 shl 4) do
    begin
        sum := 0;
        for j:=1 to 4 do
        begin
            if (i shr(j-1) and 1) = 1 then
               sum := sum + b[j];
        end;
        if sum = s then
        begin
            ok := true; //
            break;
        end;
    end;
    if ok then writeLn(F,'POSSIBLE')
    else  writeLn(F,'IMPOSSIBLE');
    close(F);
end;

BEGIN
    doc;
    ghi;
END.

