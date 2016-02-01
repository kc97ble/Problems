{$mode objfpc}
uses math;
const 
	z = 500;
var
	m, n: integer;
	i, j: integer;
	a, F: array[1..z, 1..z] of integer;
begin
	readln(m, n);
	for i := 1 to m do
	for j := 1 to n do
	read(a[i][j]);
	
	for i := 1 to m do
	for j := 1 to n do
	if (i=1) and (j=1) then
		F[i][j] := a[i][j]
	else begin
		F[i][j] := low(integer);
		if i>1 then F[i][j] := max(F[i][j], F[i-1][j]+a[i][j]);
		if j>1 then F[i][j] := max(F[i][j], F[i][j-1]+a[i][j]);
	end;
	writeln(F[m][n]);
end.
