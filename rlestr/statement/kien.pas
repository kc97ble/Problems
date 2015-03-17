{$mode objfpc}{$H+}
{$coperators on}
uses sysutils, math;

type
	T = object
		a: array [0..100005] of char;
		b: array [0..100005] of int64;
		Count: integer;
		function Last: Integer;
		procedure Add(x: char; y: int64);
		procedure Enter;
		procedure Plus(var C: T);
		procedure Show(kind: string);
		procedure Copy(var C: T; p, q: Integer);
	end;

function T.Last: Integer;
begin
result := Count - 1;
end;

procedure T.Add(x: char; y: int64);
begin
	if (Count<>0) and (a[Last]=x) then b[Last] += y
	else begin Count+=1; a[Last]:=x; b[Last]:=y; end;
end;

procedure T.Enter;
var 
	s: string;
	c: char;
begin
	Count := 0;
	readln(s);
	for c in s do
	if c in ['0'..'9'] then
		b[Last] := b[Last] * 10 + (ord(c)-ord('0'))
	else
		Add(c, 0);
end;

procedure T.Plus(var C: T);
var i: integer;
begin
	for i := 0 to C.Last do
	Add(C.a[i], C.b[i]);
end;

procedure T.Show(Kind: string);
var i: Integer;
begin
	write(kind, ': ');
	for i := 0 to Last do
	write(a[i], b[i]);
	writeln;
end;

procedure T.Copy(var C: T; p, q: Integer);
var 
	i, x, y: integer;
begin
	x := 0;
	Count := 0;
	for i := 0 to C.Last do
	begin
		y := min(x+C.b[i], q) - max(x, p);
		//writeln(x:10, C.b[i]:10, q:10, x:10, p:10);
		if y>0 then Add(C.a[i], y);
		x += C.b[i];
	end;
end;
	
var
	A, B, C: T;
	x, y: Integer;
	Kind: String;

begin
	while not SeekEOF do
	begin
		readln(Kind);
		if Kind='@1' then
		begin
			A.Enter;
			B.Enter;
			A.Plus(B);
			A.Show(kind);
		end;
		if Kind='@2' then
		begin
			C.Enter;
			readln(x, y); x-=1;
			A.Copy(C, 0, x);
			B.Copy(C, x+y, maxInt);
			A.Plus(B);
			A.Show(kind);
		end;
		if Kind='@3' then
		begin
			A.Enter;
			readln(x, y); x-=1;
			B.copy(A, x, x+y);
			B.show(kind);
		end;
		if Kind='@4' then
		begin
			A.enter;
			B.enter;
			readln(x); x-=1;
			C.copy(A, 0, x);
			C.plus(B);
			B.copy(A, x, MaxInt);
			C.plus(B);
			C.show(kind);
		end;
	end;
end.
