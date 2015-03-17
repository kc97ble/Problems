{$mode objfpc}
{$coperators+, H+}

uses sysutils, classes, math;
var 
	m, n, t: integer;
	XRow: array [-3000..3000] of boolean;

function ok(x, y, k: integer): boolean;
var
	A, B: boolean;
begin
	A := InRange(x, -m, m) and InRange(y, -m, m);
	B := InRange(x+k, -m, m) and InRange(y+k, -m, m);
	if not A or not B then exit(false);
	A := InRange(x, -n, n) or InRange(x+k, -n, n);
	B := InRange(y, -n, n) or InRange(y+k, -n, n);
	Result := not A or not B;
	//if Result then writeln('ok', x:3, y:3, k:3);
end;

function solve_row(x, k: integer): Int64;
var
	i: Integer;
begin
	Result := 0;
	for i := -m to m do
	if ok(x, i, k) then
	Result += 1;
end;

procedure set_x_row(Index: array of integer; Delta: integer; Value: boolean);
var
	i: integer;
begin
	for i in Index do
	XRow[i+Delta] := Value;
end;

function solve: Int64;
var
	LastRow: integer;
	k, i: integer;
begin
	Result := 0;
	for k := 1 to 2*m do
	begin
		set_x_row([-m, -m-1, -n, -n-1, n, n+1, m, m+1], 0, true);
		set_x_row([-m, -m-1, -n, -n-1, n, n+1, m, m+1], -k, true);
		for i := -m to m do
		begin
			if XRow[i] then
			LastRow := solve_row(i, k);
			//writeln(format('size=%d, row=%d, rslt=%d', [k, i, LastRow]));
			Result += LastRow;
		end;
		set_x_row([-m, -m-1, -n, -n-1, n, n+1, m, m+1], 0, false);
		set_x_row([-m, -m-1, -n, -n-1, n, n+1, m, m+1], -k, false);
	end;
end;

begin
	readln(t);
	for t := 1 to t do
	begin
		readln(m, n);
		writeln(solve);
	end;
end.
