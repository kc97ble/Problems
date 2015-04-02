//////////////////////////////////////////////////
// score with AMM2
// Author: Do Duc Dong

//                        id'problem here...
//xor.inp
//xor.out

{$mode objfpc}{$H+}
uses lineinfo;
const           id                      ='XOR';
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


var
                s1hs                    :string;
                s1gv                    :string;
                f                       :text;
                a,b                     :array[1..100]of int64;
                n,m                     :longint;

function countones(z: int64): longint;
var
	r: longint;
begin
	r := 0;
	while (z > 0) do begin
		if z mod 2 = 1 then inc(r);
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

procedure readInput;
var i :longint;
 begin
   assign(f,ParamStr(1)); reset(f);
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
   assign(f,ParamStr(2)); reset(f);
   readln(f,s1gv);
   close(f);
 end;

procedure readHs;
var i :longint;
    z :int64;
 begin
   //doc lay ket qua hoc sinh
   assign(f,ParamStr(3)); reset(f);
   readln(f,s1hs);
   if (s1gv='-1') xor (s1hs='-1') then halt(1);
   if (s1gv='-1') and (s1hs='-1') then exit;
   reset(f);
   z:=0;
   for i:=1 to n do begin
      if eof(f) then halt(7);
      read(f,b[i]);
      if (b[i] < 0) then halt(3);
	  if countbits(b[i]) > m then halt(4);
      if countones(b[i]) <> countones(a[i]) then halt(5);
	  z := z xor b[i];
   end;
   if z<>0 then halt(6);
   close(f);
 end;

BEGIN
   readInput;
   readOutput;
   readHs;
END.
