{Mau cham bai co nhieu ket qua }
{Bai PASSWORD}


const
   PathIn                       =    'COMPAR$R.INP';
   PathOut                      =    'COMPAR$R.OUT';
   tf_in                        =    'PASSWORD.INP';
   tf_out                       =    'PASSWORD.OUT';
var
   la, ra, lo, ro , soa, sob              : longint;
   a, b                         : ansistring;
   mark                         : integer;

   b_path                       :    string;
   t_input, t_answer, t_output  :    string;
   fi, fo, fa                   :    text;
   error,P                      :    longint;
   debug                        :    boolean;


procedure read_answer;
begin
    read(fa, la, ra);
end;

procedure  read_input;
var i : integer;
begin
    readln(fi, a);
    readln(fi, b);
end;

procedure read_output; {Doc ket qua tra loi cua hoc sinh, tu tep fo}
var i : integer;
begin
    read(fo, lo, ro );
end;


{------------------------Doc duong dan cua test---------------}
procedure fix_s(var s: string);
begin
   while (length(s)>0) and (s[1]=#32) do delete(s,1,1);
   while (length(s)>0) and (s[length(s)]=#32) do delete(s,length(s),1);
end;
procedure Prepare_Path;
var f: text;
begin
   assign(f,PathIn); reset(f);
   readln(f,b_path);
   fix_s(b_path);
   close(f);

   t_input:=b_path+tf_in;
   t_answer:=b_path+tf_out;
   t_output:=tf_out;

   if debug = true then
    begin
      t_input :='test01\' + tf_in;
      t_answer:='test01\' + tf_out;
    end;
end;
{---- Mo cac file input, answer va output-------------------------------}
procedure open_file;
begin
   assign(fi,t_input); reset(fi);
   assign(fa,t_answer); reset(fa);
   assign(fo,t_output); reset(fo);
   if ioresult<>0 then
      begin
         error := 2;
         exit;
      end;
end;

procedure close_file;
begin
   close(fi);
   close(fa);
   close(fo);
end;


{--------------------------Cham bai hs -------------}
procedure Test;
var i, i1, i2 : longint;
begin
    mark := 0;  error := 0;
    if (la=lo) and (ra=ro) then exit;
    i1 := length(a);
    i2 := length(b);

    if (lo>ro) or (ro>i1) or (lo>i2 )then begin
        error := 1;
        exit;
    end;
    i := 1;
    while i<ro do begin
       if a[i]<>b[i] then begin
          error := 1;
          exit;
       end;
       inc(i);
    end;
    while i1>ro do begin
       if a[i1]<>b[i2] then begin
          error := 1;
          exit;
       end;
       dec(i1); dec(i2);
    end;
    sob := 0;
    for i:= lo to i2 do sob := sob*10 + ord(b[i]) - 48;
    i := lo;
    soa := 0;
    while i<=ro do begin
       soa := soa + ord(a[i]) - 48;
    end;
    if soa<>sob then begin
        error := 1;
        exit;
    end;
end;

procedure StartTest; {bat dau thuc hien cham bai}
begin
   read_answer;
   read_input;
   read_output;
   if error<>0 then exit;
   Test;
end;

procedure WriteResult;
var f: text;
begin
   assign(f,PathOut); rewrite(f);
   case error of
      0: writeln(f,'DUNG');
      1: writeln(f,'SAI');
      2: writeln(f,'LOI MO FILE');
      3: writeln(f,'DUNG MOT PHAN',P);
   end;
   close(f);
end;
BEGIN
   {$i-}
   debug := false;
   {Neu dat Debug = true thi thuc hien chay test01 cua bai,
   copy file out vao cung thu muc voi file cham nay}

   Prepare_Path;
   error:=0;
   open_file;
   if error=0 then StartTest;
   close_file;

   WriteResult;
   {$i+}
END.
