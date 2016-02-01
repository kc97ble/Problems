const
  maxn = 1000000;
var
  n, i : longint;
  a, b : array[0..maxn] of int64;
  sum, ans, sum2 : int64;
begin
  assign(input, 'delivery2.inp'); reset(input);
  assign(output, 'delivery2.out'); rewrite(output);
  read(n);
  assert((1 <= n) and (n <= maxn));
  b[0] := 0;
  sum := 0;
  for i := 1 to n do begin
    read(a[i]);
    assert(abs(a[i]) <= 10000);
    b[i] := b[i - 1] + a[i];
    sum := sum + b[i - 1];
  end;
  ans := sum;
  sum2 := 0;
  for i := n - 1 downto 0 do begin
    sum := sum - b[i];
    sum2 := sum2 + b[n] - b[i + 1];
    if (sum + sum2 < ans) then begin
      ans := sum + sum2;
    end;
  end;
  writeln(ans);
end.