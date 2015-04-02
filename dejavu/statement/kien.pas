{$mode objfpc}{$H+}
{$coperators on}

var
	n, i: integer;
	x, y: array [1..100000] of integer;
	cx, cy: array [0..1000000] of integer;
	Sum : Int64 = 0;

begin
	readln(n);
	for i := 1 to n do
	begin
		readln(x[i], y[i]);
		cx[x[i]] += 1;
		cy[y[i]] += 1;
	end;
	for i := 1 to n do
	Sum += Int64(cx[x[i]]-1) * (cy[y[i]]-1);
	writeln(Sum);
end.

