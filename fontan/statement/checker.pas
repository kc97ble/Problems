//CMS checker
{$mode objfpc}

uses sysutils, math;

var
	n, i: integer;
	xs, ys: double;
	x, y, r: array [0..100] of double;
	x0, y0, r0: double;
	x1, y1, r1: double;

begin
	try
		Assign(Input, ParamStr(1)); Reset(Input);
		readln(xs, ys, n);
		for i := 1 to n do
		readln(x[i], y[i], r[i]);
		
		Assign(Input, ParamStr(2)); Reset(Input);
		readln(x0, y0, r0);
		
		Assign(Input, ParamStr(3)); Reset(Input);
		readln(x1, y1, r1);
		
		if r1 < r0-1e-2 then
			raise Exception.Create('Solution is smaller than expected');
		if x1-r1 < 0-1e-2 then
			raise Exception.Create('Fountain intersects left wall');
		if y1-r1 < 0-1e-2 then
			raise Exception.Create('Fountain intersects top wall');
		if x1+r1 > xs+1e-2 then
			raise Exception.Create('Fountain intersects right wall');
		if y1+r1 > ys+1e-2 then
			raise Exception.Create('Fountain intersects bottom wall');
		for i := 1 to n do
			if hypot(x1-x[i], y1-y[i]) < r1+r[i]-1e-2 then
			raise Exception.Create('Fountain intersects a column');
		if r1 > r0+1e-2 then
			raise Exception.Create('Solution is better than expected! '+
			Format('Expected %f, found %f', [r0, r1]));
		writeln('1.0');
		writeln(stderr, 'Correct');
	except
		on E: Exception do
		begin
			writeln('0.0');
			writeln(stderr, E.Message);
		end;
	end;
end.
