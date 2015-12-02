{ prof. Szabo zoltan Gr. Sc. "Petru Maaior" Reghin}
{ complexitate O(n^3) }
const fin='flori.in';
      fout='flori.out';
var s,a:array[1..4000] of longint;
    lung,succ:array[1..4000] of integer;
    lungmin,l,k,n,m,i,j,pozmax,p:integer;
    x:word;
    f,g:text;
function ok(i,j,l:integer):boolean;
begin
  ok:=true;
  while (j<=k) and (a[i]=a[j]) do
    begin
      if i+j=2*l then
        begin
          ok:=false;
          exit;
        end;
      j:=succ[j];
    end;

end;
begin
  assign(f,fin);
  reset(f);
  assign(g,fout);
  rewrite(g);
  readln(f,n,m);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(f,x);
        inc(a[i-j+m],x);
      end;
  l:=m+n-1; {l e numarul straturillor}
  k:=2*l-1; {k toate straturile parcurse direct si inapoi}
  for i:=l+1 to k do
    a[i]:=a[2*l-i];
  succ[k]:=k+1;
  s[k]:=a[k];
  lung[k]:=1;
  for i:=k-1 downto 1 do
    begin
      s[i]:=a[i]; succ[i]:=k+1;lung[i]:=1;
      for j:=i+1 to k do
        if (a[i]<a[j]) or (a[i]=a[j]) and ok(i,j,l) then
          if (s[i]<s[j]+a[i]) then
            begin
              s[i]:=s[j]+a[i];
              succ[i]:=j;
              lung[i]:=lung[j]+1;
            end
          else
            if (s[i]=s[j]+a[i]) and (lung[i]>lung[j]+1) then
              begin
                lung[i]:=lung[j]+1;
                succ[i]:=j;
              end;
    end;
  pozmax:=1;lungmin:=32767;
  for i:=2 to k do
    if (s[pozmax]<s[i]) or (s[pozmax]=s[i]) and (lungmin>lung[i]) then
      pozmax:=i;
  writeln(g,s[pozmax]);
  writeln(g,lung[pozmax]);
  p:=pozmax;
  while p<>k+1 do
    begin
      if p<=l then
        write(g,p,' ')
      else
        write(g,2*l-p,' ');
      p:=succ[p];
    end;
  writeln(g);
  close(f);
  close(g);
end.
