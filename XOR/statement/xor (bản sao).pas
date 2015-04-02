//////////////////////////////////////////////////
// score with AMM2
// Author: Do Duc Dong

//                        id'problem here...
//xor.inp
//xor.out

const           id                      ='XOR';
                fi                      ='compar$r.inp';
                fo                      ='compar$r.out';
                errMsg                  :array[1..9]of string  = (
                                        'Err 1: Phai thong bao la -1',
                                        'Err 2: Thong bao -1 la sai',
                                        'Err 3: So am(-)',
                                        'Err 4: So co qua max bit',
                                        'Err 5: So bit 1 khong khop',
                                        'Err 6: Xor <> 0',
                                        'Err 7:',
                                        'Err 8:',
                                        'Err 9:');


var             path                    :string;
                s1hs,s2hs               :string;
                s1gv,s2gv               :string;
                f                       :text;
                err                     :longint;
                a,b                     :array[1..100]of int64;
                n,m                     :longint;

function countones(z: int64): longint;
var
	r: longint;
begin
	r := 0;

	while (z > 0) do begin
		if z mod 2 = 1 then
			inc(r);
		z := z div 2;
	end;

	countones := r;
end;

function countbits(z: int64): longint;
var
	r: longint;
begin
	r := 0;

	while (z > 0) do begin
		inc(r);
		z := z div 2;
	end;

	countbits := r;
end;

procedure readPath;
 begin
   // doc lay duong dan
   assign(f,fi); reset(f);
   read(f,path);
   close(f);
 end;

procedure readInput;
var i :longint;
 begin
   //doc du lieu
   //file input nam trong duong dan path
   assign(f,path+id+'.inp'); reset(f);
   readln(f,n);
   m:=0;
   for i:=1 to n do begin
        read(f,a[i]);
        if countbits(a[i])>m then m:=countbits(a[i]);
   end;
   close(f);

 end;

procedure readOutput;
 begin
   //doc dap an
   //file output nam trong duong dan path
   assign(f,path+id+'.out'); reset(f);

   readln(f,s1gv);

   close(f);

 end;

procedure readHs;
var i :longint;
    z :int64;
 begin
   //doc lay ket qua hoc sinh
   assign(f,id+'.out'); reset(f);

   readln(f,s1hs);

   if s1gv='-1' then begin
      if s1hs<>s1gv then err:=1;
      close(f);
      exit;
   end;

   if s1hs='-1' then begin
      err:=2;
      close(f);
      exit;
   end;

   reset(f);

   z:=0;
   for i:=1 to n do begin
        if eof(f) then begin err:=7; close(f); exit; end;
        read(f,b[i]);
                if (b[i] < 0) then begin
                        err:=3;
                        close(f);
                        exit;
                end;
		if countbits(b[i]) > m then begin
                        err:=4;
                        close(f);
                        exit;
                end;
                if countones(b[i]) <> countones(a[i]) then begin
                        err:=5;
                        close(f);
                        exit;
                end;
		z := z xor b[i];
   end;

   if z<>0 then err:=6;

   close(f);
 end;


procedure writeScore;
 begin
   assign(f,fo); rewrite(f);

   if err=0 then writeln(f,'DUNG')
   else begin
//           if score=1 then writeln(f,'DUNGMOTPHAN 1') else
           writeln(f,'SAI');
           writeln(f,errMsg[err]);
        end;

   close(f);

 end;

BEGIN

   // doc duong dan
   readPath;

   //doc du lieu vao
   readInput;

   //doc dap an
   readOutput;

   //doc ket qua hoc sinh
   readHs;

   //ghi ket qua
   writeScore;
END.
