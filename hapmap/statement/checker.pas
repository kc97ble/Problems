const           id                      ='hapmap';

var             path                    :string;
                s1hs,s2hs               :string;
                s1gv,s2gv               :string;
                f                       :text;
                err                     :longint;
                errMsg                  :array[1..100]of string;
                geno,hap                :array[1..1000]of string;
                n_geno,l_geno,n_hap     :longint;
                dapso                   :longint;


procedure readInput;
var i:longint;
 begin
   //doc du lieu
   //file input nam trong duong dan path
   assign(f,ParamStr(1)); reset(f);
   readln(f,n_geno,l_geno);

   for i:=1 to n_geno do readln(f,geno[i]);

   close(f);

 end;

procedure readOutput;
 begin
   //doc dap an
   //file output nam trong duong dan path
   assign(f,ParamStr(2)); reset(f);

   readln(f,dapso);

   close(f);

 end;

procedure readHs;
var i:longint;
 begin
   //doc lay ket qua hoc sinh
   assign(f,ParamStr(3)); reset(f);

   readln(f,n_hap);

   for i:=1 to n_hap do readln(f,hap[i]);

   close(f);
 end;


function ktH1H2Geno(h1,h2,g:string):boolean;
var i  :longint;
 begin
   for i:=1 to l_geno do begin
     if (g[i]='1')and((h1[i]='0')or(h2[i]='0')) then exit(false);
     if (g[i]='0')and((h1[i]='1')or(h2[i]='1')) then exit(false);
     if (g[i]='2')and((h1[i]+h2[i]='01')or(h1[i]+h2[i]='10')=false) then exit(false);
   end;
   exit(true);
 end;

function ktGeno(g:string):boolean;
var i,j:longint;
 begin
   for i:=1 to n_hap do
    for j:=i to n_hap do
      if ktH1H2Geno(hap[i],hap[j],g) then exit(true);

   exit(false);
 end;


function kiemtra:longint;
var k:longint;
 begin
   for k:=1 to n_geno do
     if ktGeno(geno[k])=false then
      exit(k);

   exit(0);
 end;

function score:longint;
 begin
   if kiemtra>0 then begin
      errMsg[1]:='khong tao duoc het geno';
      exit(1);
   end;

   if n_hap>dapso+20 then begin
      errMsg[2]:='ket qua qua toi';
      exit(2);
   end;

   if n_hap<=dapso then exit(0);

   exit(3);
 end;

procedure writeScore;
 begin
   //cham bai
   err:=score;

   writeln(stderr, err);
   writeln((20-n_hap+dapso)/20);

 end;

BEGIN
   //doc du lieu vao
   readInput;

   //doc dap an
   readOutput;

   //doc ket qua hoc sinh
   readHs;

   //ghi ket qua
   writeScore;
END.
