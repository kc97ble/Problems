type
  p = Record
    d, u : Longint;
  end;

var
  i, j, V, n, w, counter, Q, s, t, d, u, vv, w_u_vv : Longint;
  AdjList, weight : array[0..999,0..999] of Longint;
  sz, dist : array[0..999] of Longint;
  front : p;

//====================================================
// Start of Binary Heap implementation  
  A : array[0..999] of p;
  BinaryHeapSize : Longint;

function smaller(a : p; b : p) : Boolean;
begin
  if a.d <> b.d then begin
    if a.d < b.d then smaller := true else smaller := false;
  end
  else begin
    if a.u < b.u then smaller := true else smaller := false;
  end;
end;

function parent(i : Longint) : Longint;
begin
  parent := trunc(i / 2);
end;

function left(i : Longint) : Longint;
begin
  left := 2 * i;
end;

function right(i : Longint) : Longint;
begin
  right := 2 * i + 1;
end;
  
procedure Initialize;
begin
  A[0].d := 0;
  A[0].u := 0; // dummy
  BinaryHeapSize := 0;
end;

procedure shiftUp(i : Longint);
var
  temp : p;
begin
  while (i > 1) and (smaller(A[i], A[parent(i)])) do begin
    temp := A[i];
    A[i] := A[parent(i)];
    A[parent(i)] := temp;
    i := parent(i);
  end;
end;

procedure Enqueue(_d : Longint; _u : Longint);
begin
  inc(BinaryHeapSize);
  A[BinaryHeapSize].d := _d;
  A[BinaryHeapSize].u := _u;
  shiftUp(BinaryHeapSize);
end;

procedure shiftDown(i : Longint);
var
  minV, temp : p;
  min_id : Longint;
begin
  while i <= BinaryHeapSize do begin
    minV := A[i]; min_id := i;
    if (left(i) <= BinaryHeapSize) and (smaller(A[left(i)], minV)) then begin
      minV := A[left(i)];
      min_id := left(i);
    end;
    if (right(i) <= BinaryHeapSize) and (smaller(A[right(i)], minV)) then begin
      minV := A[right(i)];
      min_id := right(i);
    end;

    if min_id <> i then begin
      temp := A[i];
      A[i] := A[min_id];
      A[min_id] := temp;
      i := min_id;
    end
    else
      break;
  end;
end;

function Dequeue() : p;
var
  minV : p;
begin
  minV := A[1];
  A[1] := A[BinaryHeapSize];
  dec(BinaryHeapSize); // virtual decrease
  shiftDown(1);
  Dequeue := minV;
end;

function isEmpty() : Longint;
begin
  if BinaryHeapSize = 0 then isEmpty := 1 else isEmpty := 0;
end;
// End of Binary Heap implementation  
//====================================================

begin
  read(V);
  for i := 0 to V-1 do begin
    read(n);
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
    Initialize();
    Enqueue(0, s); 
    while isEmpty() = 0 do begin
      inc(counter);
      if counter > 1000000 then begin
        writeln('TLE because iteration counter > 1000000');
        exit;
      end;

      front := Dequeue();
      d := front.d; u := front.u;
      if d = dist[u] then begin
        for j := 0 to sz[u]-1 do begin
          vv := AdjList[u,j];
          w_u_vv := weight[u,j];
          if dist[u] + w_u_vv < dist[vv] then begin
            dist[vv] := dist[u] + w_u_vv;
            Enqueue(dist[vv], vv);
          end;
        end;
      end;
    end;

    writeln(dist[t]);
  end;
 
  writeln('The value of counter is ', counter);
end.
