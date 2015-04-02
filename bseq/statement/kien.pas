{$mode objfpc}{$H+}

var 
	n: integer;
	i, j: integer;

begin
	readln(n);
	for i := 0 to n do
	begin
		for j := n downto 1 do
		write(('01')[ord(j<=i)+1], ' ');
	end;
end.
