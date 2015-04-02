const           id                      ='BSEQ';
                fi                      ='compar$r.inp';
                fo                      ='compar$r.out';

var
                f,g                     :text;
                err                     :string;
                a,s                     :array[0..1000000]of longint;
                n                       :longint;

procedure cham;
var i :longint;
begin
   //doc lay ket qua hoc sinh

   for i:=1 to n*n+n do begin
        read(g,a[i]);
        s[i]:=s[i-1] + a[i];
   end;

   for i:=0 to n*n-n do
     if (s[i+n]-s[i]) >= (s[i+2*n]-s[i+n]) then begin
        str(i,err);
        exit;
     end;

end;

BEGIN
   assign(f,ParamStr(1)); reset(f);
   assign(g,ParamStr(3)); reset(g);

   err:='DUNG';

   readln(f,n);
   cham;

   close(f);
   close(g);

   writeln(stderr, err);
   if err='DUNG' then writeln('1.0')
   else writeln('0.0');
END.
