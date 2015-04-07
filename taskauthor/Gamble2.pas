var
   i, a, b, V, E : Longint;
begin
  read(V, E);
  for i := 0 to E-1 do begin
    read(a, b);
  end;

  writeln('TLE because iteration counter > 1000000');
  exit; // this is TLE

  writeln(V);
  write(0);
  for i := 1 to V-1 do begin
    write(' ',i);
  end;
  writeln();
end.
