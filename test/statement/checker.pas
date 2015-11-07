const           id                      ='test';
                fi                      ='compar$r.inp';
                fo                      ='compar$r.out';

var             path                    :string;
                f,g                     :text;
                err                     :string;
                a,d,h                   :array[0..2000]of longint;
                n,iTest,nTest           :longint;

procedure check;
var i,j,v :longint;
 begin
   readln(f,n);
   for i:=1 to n do read(f,a[i]);

   fillchar(d,sizeof(d),0);

   for i:=1 to n do begin
      read(g,v);
      if (v>=1)and(v<=n)and(d[v]=0) then begin
                d[v]:=1;
                h[i]:=v;
      end
      else
        begin
                err:='chi so sai'; break;
        end;
   end;

   for i:=1 to n-2 do begin
     fillchar(d,sizeof(d),0);
     d[a[h[i+1]]]:=1;
     for j:=i+2 to n do begin
       v:=a[h[i]]+a[h[j]];
       if (v mod 2=0) and (d[v div 2]=1) then begin
          err:='khong thoa man rang buoc';
          exit;
       end;
       d[a[h[j]]]:=1;
     end;
   end;

 end;

BEGIN
   // doc lay duong dan

   assign(f,ParamStr(1)); reset(f);
   assign(g,ParamStr(3)); reset(g);

   readln(f,nTest);
   err:='DUNG';
   
   for iTest:=1 to nTest do begin
     check;
     if err<>'DUNG' then break;
   end;

   close(f);
   close(g);

   writeln(stderr, err);
   if err='DUNG' then writeln('1.0')
   else writeln('0.0');
END.
