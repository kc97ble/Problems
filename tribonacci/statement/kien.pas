{$mode objfpc}
const
	n = 38;
var
	a: array [0..n] of integer;
	i, x: integer;

begin
	a[0]:=0; a[1]:=0; a[2]:=1;
	for i := 3 to n do
	a[i] := a[i-1] + a[i-2] + a[i-3];
	
	repeat
		readln(x);
		for i := 0 to n do
		if a[i]>=x then break;
		writeln(a[i]);
	until seekeof;
end.
