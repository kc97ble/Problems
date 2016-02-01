{$mode objfpc}{$H+}
var
	s: string;
	m: integer;

function ok(L, R: integer): boolean;
begin
	if L>R then exit(True);
	if s[L]<>s[R] then exit(False);
	exit(ok(L+1, R-1));
end;

var
	i, L, R: integer;
begin
	readln(s);
	readln(m);
	for i := 1 to m do
	begin
		readln(L, R);
		if ok(L, R) then
		writeln('YES')
		else
		writeln('NO');
	end;
end.
