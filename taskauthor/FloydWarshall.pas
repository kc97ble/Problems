var
  i, j, k, V, n, w, counter, Q, s, t : Longint;
  M : array[0..299,0..299] of Longint;
begin
  read(V);
  for i := 0 to V-1 do begin
    for j := i+1 to V-1 do begin
      M[i,j] := 1000000000;
      M[j,i] := 1000000000;
    end;
  end;
  for i := 0 to V-1 do begin
    M[i][i] := 0;
  end;
 
  for i := 0 to V-1 do begin
    read(n);
    while n > 0 do begin
      dec(n);
      read(j, w);
      if w < M[i,j] then begin
        M[i,j] := w;
      end;
    end;
  end;
 
  counter := 0;
  for k := 0 to V-1 do begin
    for i := 0 to V-1 do begin
      for j := 0 to V-1 do begin
        inc(counter);
        if counter > 1000000 then begin
          writeln('TLE because iteration counter > 1000000');
          exit;
        end;
        if M[i,k] + M[k,j] < M[i,j] then begin
          M[i,j] := M[i,k] + M[k,j];
        end;
      end;
    end;
  end;
 
  read(Q);
  while Q > 0 do begin
    dec(Q);
    read(s, t);
    writeln(M[s,t]);
  end;
 
  writeln('The value of counter is: ', counter);
end.
