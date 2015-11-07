{Mau cham bai co nhieu ket qua }
{Bai CAMP}

const
   PathIn                       =    'COMPAR$R.INP';
   PathOut                      =    'COMPAR$R.OUT';
   tf_in                        =    'CAMP.INP';
   tf_out                       =    'CAMP.OUT';
   MaxN                         =    10001;
   soluong   : array[1..10] of integer = (9,28,55,92,197,255,360,500,786,843);
type  dactrung  = record x,y,r,c,c1,c2 : integer end;
      m2        = array[0..maxN,0..maxN] of longint;
      m1        = array[1..maxN] of dactrung;
var   a   : m2;
      d   : m1;
      r,c : integer;{dong, cot cua ban do}
      l,w : integer;{dong, cot cua trai}
      h   : integer;{ so luong dac trung}
      sl, slbest: integer;
      dong, cot, dong_hs, cot_hs : integer;

   b_path                       :    string;
   t_input, t_answer, t_output  :    string;
   fi, fo, fa                   :    text;
   error,P                      :    longint;
   debug                        :    boolean;


procedure read_answer;
begin
    read(fa, dong, cot);
    read(fa,slbest);
end;

procedure  read_input;
var f : text;
    i,j : integer;
begin
     fillchar(a,sizeof(a),0);
     readln(fi,r,c);
     for i:=1 to r do
         for j:=1 to c do read(fi, a[i,j]);
     read(fi,l,w); {kich thuoc trai}
     read(fi,h);   {so dac trung}
     for i:=1 to h do
     with d[i] do
     read(fi,x,y,r,c,c1,c2);
end;

procedure read_output; {Doc ket qua tra loi cua hoc sinh, tu tep fo}
var somay: longint;
    i : longint;
begin
    readln(fo, dong_hs, cot_hs);
end;
procedure new_a;
var i,j : integer;
begin
    for i:=1 to r do
    begin
        for j:=1 to c do
        begin
            if (j=1) then a[i,j] := a[i-1,1] + a[i,j] else
            a[i,j] := a[i,j-1] + a[i,j] + a[i-1,j] - a[i-1,j-1];
        end;
    end;
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
var k,d0,c0,i,j : integer;
    h0,h1,h2,h3,h4,h5 : longint;
    stop : boolean;
begin
    if (dong=dong_hs) and (cot=cot_hs) then begin
        error:=0;
        exit;
    end;
    new_a; //tich luy cac gia tri tren manh dat a
    sl   := 0;
    i:=dong_hs; j:=cot_hs;
    if (i<1) or (i>r) or (j<1) or (j>c) or
       (i+l-1>r) or (j+w-1>c) then begin
        error := 1;
        exit;
    end;
    if (i+l-1<=r) and (j+w-1<=c) then  {hcn1 cua trai thuoc khu dat}
    for k:=1 to h do  begin
        d0 := i + d[k].x - 1;  //toa do goc trai tren cua trai
        c0 := j + d[k].y - 1;
        h0 := a[d0-1,c0-1];    //tinh tong do cao hcn1=
        h1 := a[d0-1,c0+d[k].c-1];
        h2 := a[d0+d[k].r-1,c0-1];
        h3 := a[d0+d[k].r-1, c0+d[k].c-1];
        if d[k].c1=1 then begin {hcn1 tren hcn2}
           if (d0 + 2*d[k].r-1> i+l-1) or (c0 + d[k].c-1>j+w-1) then begin
               error := 1; //hcn2 co phan nam ngoai khu dat
               exit;
           end;
           if (d0 + 2*d[k].r-1 <= i+l-1) and (c0 + d[k].c-1<=j+w-1) then
           begin
              h4 := a[d0+2*d[k].r-1,c0-1];
              h5 := a[d0+2*d[k].r-1, c0+d[k].c-1];
              if ((2*h3-h1-2*h2+h0-h5+h4 <0) and (d[k].c2=0))
               or ((2*h3-h1-2*h2+h0-h5+h4 >=0) and (d[k].c2=1)) then inc(sl);
              if sl + (h-k) <= slbest then  begin   {can thoat kip thoi}
                 error := 3;
                 exit;
              end;
         end;
         end else
         if d[k].c1=0 then   {hcn1 ben trai hcn2}
            begin
                if (d0 + d[k].r-1> i+l-1) or (c0 + 2*d[k].c-1>j+w-1) then begin
                   error := 1;
                   exit;
                end;
                if (d0 + d[k].r-1 <= i+l-1) and (c0 + 2*d[k].c-1<=j+w-1) then {hcn1 thuoc trai}
                begin
                    h4 := a[d0-1,c0+2*d[k].c-1];
                    h5 := a[d0+d[k].r-1, c0+2*d[k].c-1];
                    if ((2*h3+h0+h4-2*h1-h2-h5<0) and (d[k].c2=0))
                    or ((2*h3+h0+h4-2*h1-h2-h5>=0) and (d[k].c2=1))  then inc(sl);
                    if sl + (h-k) <= slbest then
                    begin
                        error := 3;
                        exit;
                    end;
                end;
            end;
        end;
        if sl>slbest then error:=3;
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
