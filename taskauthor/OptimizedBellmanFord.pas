var
  i, j, u, vv, w_u_vv, V, n, w, Q, counter, s, t : Longint;
// note to contestants who use Pascal:
// this is a static array whereas the C++ version is a resizeable vector
  dist : array[0..999] of Longint;
  AdjList : array[0..999,0..999] of Longint;
  weight : array[0..999,0..999] of Longint;
  sz : array[0..999] of Longint;
  change : Boolean;
begin
  read(V);
  for i := 0 to V-1 do begin
    read(n);
    sz[i] := 0;
    while n > 0 do begin
      dec(n);
      read(j, w);
      AdjList[i,sz[i]] := j;
      weight[i,sz[i]] := w;
      inc(sz[i]);
    end;
  end;
 
  counter := 0;
  read(Q);
  while Q > 0 do begin
    dec(Q);
    read(s, t);
    for i := 0 to V-1 do begin
      dist[i] := 1000000000;
    end;
    dist[s] := 0;
 
    for i := 0 to V-2 do begin
      change := false;
      for u := 0 to V-1 do begin
        for j := 0 to sz[u]-1 do begin
          inc(counter);
          if counter > 1000000 then begin
            writeln('TLE because iteration counter > 1000000');
            exit;
          end;
 
          vv := AdjList[u,j];
          w_u_vv := weight[u,j];
          if dist[u] + w_u_vv < dist[vv] then begin
            dist[vv] := dist[u] + w_u_vv;
            change := true;
          end;
        end;
      end;
 
      if change = false then begin // the optimized BellmanFord
        break;
      end;
    end;
 
    writeln(dist[t]);
  end;
  writeln('The value of counter is: ', counter);
end.
