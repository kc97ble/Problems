{$mode objfpc}
const
	z = 202;
var
	m, n, t: integer;
	a: array [0..z, 0..z] of integer;
	s: array [0..z, 0..z] of int64;

function solve(x, y, p, q: integer): int64;
var
	i: integer;
begin
	Result := 0;
	for i := x to p do
	Result := Result + s[i, q]-s[i, y-1];
end;

var
	i, j, x, y, p, q: integer;

begin
	readln(m, n, t);
	for i := 1 to m do
		for j := 1 to n do
		read(a[i, j]);
	for i := 1 to m do
		for j := 1 to n do
		s[i, j] := s[i, j-1] + a[i, j];
	for i := 1 to t do
	begin
		readln(x, y, p, q);
		writeln(solve(x, y, p, q));
	end;
end.
