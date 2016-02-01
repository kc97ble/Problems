{$mode objfpc}
uses math;
var
	s: string;
	F: array [1..200] of integer;
	i, j, n: integer;
begin
	readln(s); n:=length(s);
	for i := 1 to n do
	begin
		F[i] := 1;
		for j := 1 to i-1 do
		if s[j]<=s[i] then
		F[i] := max(F[i], F[j]+1);
	end;
	writeln(MaxIntValue(F[1..n]));
end.
