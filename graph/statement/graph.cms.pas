uses math;

const           id                      ='graph';
                fi                      ='compar$r.inp';
                fo                      ='compar$r.out';

var             path                    :string;
                f                       :text;
                g1,g2                   :array[1..1000,1..1000]of longint;
                d1,d2,r                 :array[1..1000]of longint;
                err                     :string;
                dapan,mt                :longint;
                i,j,k,n1,n2,m1,m2,n     :longint;
                res                     :real;

procedure cham;
begin
   //doc lay ket qua hoc sinh
   assign(f,ParamStr(3)); reset(f);
   readln(f,n);

   for k:=1 to n do begin
      readln(f,i,j);

      if (i<1)or(i>n1)or(d1[i]=1) then
        begin err:='chi so dinh sai'; break; end;

      d1[i]:=1;

      if (j<1)or(j>n2)or(d2[j]=1) then
        begin err:='chi so dinh sai'; break; end;

      r[i]:=j;

      d2[j]:=1;
   end;

   close(f);

   if err<>'DUNG' then exit;

   mt:=0;
   for i:=1 to n1 do
    if d1[i]=1 then
    for j:=i+1 to n1 do
    if (d2[j]=1)and(g1[i,j]=1) then mt:=mt + g2[r[i],r[j]];
   res:=min(1,mt/dapan);

end;

BEGIN
   //doc lay dap an
   //file input va output nam trong duong dan path
   assign(f,ParamStr(1)); reset(f);
   readln(f,n1,m1);
   for k:=1 to m1 do begin
      readln(f,i,j);
      g1[i,j]:=1; g1[j,i]:=1;
   end;

   readln(f,n2,m2);
   for k:=1 to m2 do begin
      readln(f,i,j);
      g2[i,j]:=1; g2[j,i]:=1;
   end;
   close(f);

   assign(f,ParamStr(2)); reset(f);
   read(f,dapan);
   close(f);

   err:='DUNG';
   cham;

   //ghi ket qua

   writeln(stderr, err);
   if err='DUNG' then writeln(res)
   else writeln('0.0');
END.
