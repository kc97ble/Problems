const           id                      ='BSEQ';
                fi                      ='compar$r.inp';
                fo                      ='compar$r.out';

var             path                    :string;
                f                       :text;
                n                       :longint;
                a,s                     :array[0..100000]of longint;
                err                     :string;

procedure cham;
var i :longint;
begin
   //doc lay ket qua hoc sinh
   assign(f,id+'.out'); reset(f);

   for i:=1 to n*n+n do begin
        read(f,a[i]);
        s[i]:=s[i-1] + a[i];
   end;

   for i:=0 to n*n-n do
     if (s[i+n]-s[i]) >= (s[i+2*n]-s[i+n]) then begin
        str(i,err);
        exit;
     end;

end;

BEGIN
   // doc lay duong dan
   assign(f,fi); reset(f);
   read(f,path);
   close(f);

   //doc lay dap an
   //file input va output nam trong duong dan path
   assign(f,path+id+'.inp'); reset(f);
   readln(f,n);
   close(f);

   err:='DUNG';
   cham;

   //ghi ket qua

   writeln(err);

   assign(f,fo); rewrite(f);
   if err='DUNG' then writeln(f,'DUNG')
   else begin writeln(f,'SAI'); writeln(f,err); end;

   close(f);
END.
