{$mode objfpc}
uses math;
type
	__ = 0..300;
var
	n, k: integer;
	a: array [__] of integer;
	G: array [__,__] of int64;

function maximize(var a: int64; b: int64): boolean;
begin
	Result := a<b;
	if Result then a:=b;
end;

function f(u, k: integer; Tracing: boolean=false): int64;
var
	Current: integer = MaxInt;
	i, Decision: integer;
begin
	if u=n+1 then exit(0);
	if k=0 then exit(low(Result));
	if (G[u, k]<>0) and (not Tracing) then exit(G[u, k]);
	Result := 0;
	for i := u to n do
	begin
		Current := min(Current, a[i]);
		if maximize(Result, f(i+1, k-1) + Current) then
		Decision := i;
	end;
	G[u, k] := Result;
	
	if Tracing then
	begin
		i := Decision;
		if i=n then writeln
		else write(i, ' ');
		f(i+1, k-1, true);
	end;
end;

var
	i: integer;
begin
	readln(n, k);
	for i := 1 to n do
	read(a[i]);
	writeln(f(1, k));
	f(1, k, true);
end.

