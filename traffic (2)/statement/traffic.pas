{Mau cham bai co nhieu ket qua }
{Bai TRAFFIC}
const
   PathIn                       =    'COMPAR$R.INP';
   PathOut                      =    'COMPAR$R.OUT';
   tf_in                        =    'TRAFFIC.INP';
   tf_out                       =    'TRAFFIC.OUT';
   MaxN                         =    900001;
type  TOADO  = record x,y : word end;
      m1        = array[1..maxN] of toado;
var   a   : ^m1;
      n   : longint;
      p0   : toado;

   b_path                       :    string;
   t_input, t_answer, t_output  :    string;
   fi, fo, fa                   :    text;
   error,P                      :    longint;
   debug                        :    boolean;


procedure  read_input;
var f : text;
    x,y: word; j : longint;
begin
     readln(fi, n);
     for j:=1 to n do begin
        readln(fi, x, y);
        p0.x := x; p0.y := y;
        a^[j] :=p0;
     end;
end;
procedure read_output;
var i : longint; x,y : word;  g: text;
begin
    i:=n;
    while not seekeof(fo) do begin
       i := i+1;
       readln(fo, x, y);
       p0.x := x; p0.y := y;
       a^[i] := p0;
       (*if i=800000 then begin writeln(i); readln; end;*)
    end;
    n:=i;
end;
procedure quicksort(l: longint; r : longint);
var i,j: longint; p, t : toado;
begin
    i:=l; j := r;
    p := a^[(l+r) div 2];
    while i<=j do begin
       while ((a^[i].x<p.x) or ((a^[i].x=p.x) and (a^[i].y<p.y))) do inc(i);
       while ((a^[j].x>p.x) or ((a^[j].x=p.x) and (a^[j].y>p.y))) do dec(j);
       if i<=j then begin
            if i<j then begin
               t := a^[i]; a^[i] := a^[j]; a^[j]:=t; end;
            i := i+1;  j:= j-1;
       end;
    end;
    if l<j then quicksort(l,j);
    if i<r then quicksort(i,r);
end;

function find ( p : toado): boolean;
var l, r, m : longint ; p1 : toado;
begin
    l := 1; r:= n;
    while (l<=r) do begin
        m:=(l+r) div 2;
        p1 := a^[m];
        if (p.x<p1.x) or ((p.x=p1.x) and (p.y<p1.y)) then r:= m-1;
        if (p.x>p1.x) or ((p.x=p1.x) and (p.y>p1.y)) then l:= m+1;
        if (p.x=p1.x) and (p.y=p1.y) then exit(true);
    end;
    exit(false);
end;

procedure Test;
var i, j : longint; x1,x2,x3 : word; p1,p2 : toado;
begin
    quicksort(1,n);
    error := 0;
    for i:=1 to n  do begin
        x1 := a^[i].x;
        for j:=i+1 to n do begin
            x2 := a^[j].x;
            for x3:=x1 to x2 do begin
                p1.x := x3; p1.y := a^[i].y;
                p2.x := x3; p2.y := a^[j].y;
                if (find(p1) and find(p2)) then exit;
            end;
        end;
    end;
    error := 1;
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
   (*assign(fa,t_answer); reset(fa); *)
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
  (* close(fa); *)
   close(fo);
end;


{--------------------------Cham bai hs -------------}

procedure StartTest; {bat dau thuc hien cham bai}
begin
  (* read_answer;*)
   new(a);
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

