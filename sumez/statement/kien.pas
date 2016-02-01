{$mode objfpc}
const
	z = 100005;
var
	n, m: integer;
	a: array [0..z] of integer;
	s: array [0..z] of int64;
var
	i, L, R: integer;
begin
	readln(n, m);
	for i := 1 to n do
		read(a[i]);
	for i := 1 to n do
		s[i] := s[i-1] + a[i];
	for i := 1 to m do
	begin
		readln(L, R);
		writeln(s[R]-s[L-1]);
	end;
end.
