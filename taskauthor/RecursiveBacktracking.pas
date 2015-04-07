var
  i, a, b, V, E, counter, X : Longint;
  cur, ans, sz : array[0..999] of Longint;
  AdjList : array[0..999,0..999] of Longint;
  found : Boolean;

function backtrack(u : Longint; lbl : Longint) : Longint;
var
  j, vv : Longint;
  ok : array[0..999] of Boolean;
begin
  if found = true then begin
    exit;
  end;

  inc(counter);
  cur[u] := lbl; // assign label to u
  if u = V-1 then begin // done
    found := true;
    for j := 0 to V-1 do begin
      ans[j] := cur[j];
    end;
    exit;
  end;

  // explore neighbors
  for j := 0 to X-1 do begin
    ok[j] := true;
  end;
  for j := 0 to sz[u+1]-1 do begin
    inc(counter);
    if counter > 1000000 then begin
      exit;
    end;

    vv := AdjList[u+1,j];
    if cur[vv] <> -1 then begin
      ok[cur[vv]] := false;
    end;
  end;

  for j := 0 to X-1 do begin
    if ok[j] = true then begin
      backtrack(u+1,j);
    end;
  end;
end;

begin
  read(V, E);
  for i := 0 to E-1 do begin
    read(a, b);
    AdjList[a,sz[a]] := b;
    inc(sz[a]);
    AdjList[b,sz[b]] := a;
    inc(sz[b]);
  end;

  found := false;
  counter := 0;
  for X := 2 to V do begin
    for i := 0 to V-1 do begin
      cur[i] := -1;
    end;
    backtrack(0, 0);
    if found = true then begin
      break;
    end;

    if counter > 1000000 then begin
      writeln('TLE');
      exit;
    end;
  end;

  writeln(X);
  write(ans[0]);
  for i := 1 to V-1 do begin
    write(' ',ans[i]);
  end;
  writeln();

  writeln('The value of counter is: ', counter);
end.
