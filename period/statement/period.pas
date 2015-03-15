program period;
const
  input  = '';
  output = '';
  st = 26;
  maxn = 1000000;
  base = 860990423;
var
  s: ansistring;
  k: longint;
  d,pow: array[0..maxn] of int64;
  stack: array[0..maxn] of longint;
  top: longint;
  res: int64;

procedure init;
var
  f: text;
  i: longint;
begin
  assign(f, input);
    reset(f);

  readln(f, k);
  readln(f, s);

  close(f);

  d[0] := 0;
  d[1] := ord(s[1]);
  for i := 2 to k do
    d[i] := (d[i - 1] * st + ord(s[i])) mod base;

  pow[0] := 1;
  for i := 1 to k do
    pow[i] := (pow[i - 1] * st) mod base;
end;

procedure push(x: longint);
begin
  inc(top);  stack[top] := x;
end;

procedure solve;
var
  i,t: longint;
  k1,k2: int64;
  tmp: int64;
begin
  top := 0;
  res := 0;
  push(1);

  for i := 2 to k do
    begin
      repeat
        if stack[top] < i div 2 then top := 0 else
          begin
            t := stack[top];

            tmp := (d[t] * pow[i - t]) mod base;
            k2 := d[i] - tmp;
            if k2 < 0 then k2 := k2 + base;

            k1 := d[i - t];

            if k1 <> k2 then dec(top) else break;
          end;
      until top = 0;

      res := res + stack[top];
      push(i);
    end;
end;

procedure printresult;
var
  f: text;
begin
  assign(f, output);
    rewrite(f);
    writeln(f, res);
  close(f);
end;

begin
  init;
  solve;
  printresult;
end.