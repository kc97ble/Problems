const
  maxN = 20000;

var
  fi, fo, fa: text;
  kq, da, n: longint;
  w, cnt, list: array [1..2 * maxN] of longint;

procedure open_file;
begin
  assign(fi, ParamStr(1));  reset(fi);
  assign(fo, ParamStr(3));  reset(fo);
  assign(fa, ParamStr(2));  reset(fa);
  {$macro on}
  {$define frep:=stderr}
end;

procedure close_file;
begin
  close(fi);
  close(fo);
  close(fa);
end;

procedure sort(l, r: longint);
var i, j, mid, tmp: longint;
begin
  if l >= r then exit;
  i := l;
  j := r;
  mid := list[(l + r) shr 1];
  repeat
    while list[i] < mid do inc(i);
    while list[j] > mid do dec(j);
    if i <= j then
      begin
        tmp := list[i];
        list[i] := list[j];
        list[j] := tmp;
        inc(i);
        dec(j);
      end;
  until i > j;
  sort(l, j);
  sort(i, r);
end;

procedure read_data;
var i, u, v: longint;
begin
  readln(fi, n);
  for i := 1 to n - 1 do
    begin
      readln(fi, u, v);
      list[i] := u * 100000 + v;
    end;
  sort(1, n - 1);
end;

function check(x, y: longint): longint;
var key, l, r, mid, p: longint;
begin
  p := 0;
  key := x * 100000 + y;
  l := 1;
  r := n - 1;
  while l <= r do
    begin
      mid := (l + r) shr 1;
      if list[mid] = key then
        begin
          p := mid;
          break;
        end;
      if list[mid] < key then l := mid + 1 else r := mid - 1;
    end;
  check := p;
end;

procedure process;
var
  i, j, u, v, x, z1, z2: longint;
  da1, kq1: extended;
begin
  readln(fa, da);
  readln(fo, kq);
  for i := 1 to kq do
    begin
      x := 0;
      while not seekeoln(fo) do
        begin
          inc(x);
          read(fo, w[x]);
        end;
      if x < 2 then
        begin
          writeln(frep, 'w');
          writeln(frep, 0);
          writeln(frep, 'Co tuyen tau dien ngam co it hon 2 ga');
          exit;
        end;
      for j := 1 to x - 1 do
        begin
          z1 := check(w[j], w[j + 1]);
          z2 := check(w[j + 1], w[j]);
          if (z1 = 0) and (z2 = 0) then
            begin
              writeln(frep, 'w');
              writeln(frep, 0);
              writeln(frep, 'Chon nhung duong di khong co');
              exit;
            end;
          if (z1 > 0) then inc(cnt[z1]) else inc(cnt[z2]);
        end;
      readln(fo);
    end;
  for i := 1 to n - 1 do
    begin
      if cnt[i] = 0 then
        begin
          writeln(frep, 'w');
          writeln(frep, 0);
          writeln(frep, 'Con duong chua co tuyen tau dien ngam di qua');
          exit;
        end;
      if cnt[i] > 1 then
        begin
          writeln(frep, 'w');
          writeln(frep, 0);
          writeln(frep, 'Co duong co hon 1 tuyen tau dien ngam di qua');
          exit;
        end;
    end;
  if kq < da then
    begin
      writeln(frep, 'c');
      writeln(frep, 1000);
      writeln(frep, 'Tot hon dap an ?? ');
      exit;
    end;
  if kq = da then
    begin
      writeln(frep, 'c');
      writeln(frep, 10);
      writeln(frep, 'Dung');
      exit;
    end;
  if kq > da then
    begin
      da1 := da;
      kq1 := kq;
      writeln(frep, 'w');
      writeln(frep, trunc(7*da1*da1*da1/kq1/kq1/kq1));
      writeln(frep, 'Chua toi uu');
      exit;
    end;
end;

begin
  open_file;
  read_data;
  process;
  close_file;
end.


