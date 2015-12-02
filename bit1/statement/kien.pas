{$mode objfpc}
{$coperators on}

const
  MD = 1000000007;
var
  n, m: integer;
  T: array [1..100000] of integer;

procedure update(u, x: integer);
begin
  repeat
    T[u] := (T[u] + x) mod MD;
    u += u and -u;
  until u>n;
end;

function get(u: integer): integer;
begin
  Result := 0;
  repeat
    Result := (Result + T[u]) mod MD;
    u -= u and -u;
  until u<1;
end;

var
  i, x, u: integer;
  s: string = 'hahaha';
begin
  readln(n, m);
  for i := 1 to n do
  begin
    read(x);
    update(i, x);
  end;
  readln;

  for i := 1 to m do
  begin
    readln(s[1], s[2], s[3], u, x);
    case s[1] of
    'I': update(u, x);
    'S': writeln((get(x) - get(u-1) + MD) mod MD);
    end;
  end;
end.
