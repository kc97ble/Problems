
{Mau cham bai co nhieu ket qua }
{Bai TRAFFIC}

const MaxN  =    100001;
type  toado  = record x,y : word; end;
      m1        = array[1..maxN] of toado;
var   a   : m1;
      p   : toado;
      n   : longint;
      f,g : text;
      error : byte;

procedure read_output;
var i , x, y: longint;  g: text;
begin
    assign(g, 'traffic.out'); reset(g);
    i:=n;
    while not seekeof(g) do begin
       i := i+1;
       readln(g, x, y);
       p.x := x; p.y := y;
       a[i] := p;
    end;
    close(g);
    n:=i;
end;

procedure  read_input;
var f : text;
    x,y,i,j : longint;
begin
     assign(f,'traffic.inp'); reset(f);
     readln(f, n);
     for j:=1 to n do begin
        read(f, x, y);
        p.x := x; p.y := y;
        a[j] := p;
     end;
     close(f);
end;
procedure quicksort(l: longint; r : longint);
var i,j: longint; p, t : toado;
begin
    i:=l; j := r;
    p := a[(l+r) div 2];
    while i<=j do begin
       while ((a[i].x<p.x) or ((a[i].x=p.x) and (a[i].y<p.y))) do inc(i);
       while ((a[j].x>p.x) or ((a[j].x=p.x) and (a[j].y>p.y))) do dec(j);
       if i<=j then begin
            if i<j then begin
               t := a[i]; a[i] := a[j]; a[j]:=t; end;
            i := i+1;  j:= j-1;
       end;
    end;
    if l<j then quicksort(l,j);
    if i<r then quicksort(i,r);
end;

function find ( p : toado): boolean;
var l, r, m : longint ; p1 : toado;
begin
    l := 1; r:= n;
    while (l<=r) do begin
        m:=(l+r) div 2;
        p1 := a[m];
        if (p.x<p1.x) or ((p.x=p1.x) and (p.y<p1.y)) then r:= m-1;
        if (p.x>p1.x) or ((p.x=p1.x) and (p.y>p1.y)) then l:= m+1;
        if (p.x=p1.x) and (p.y=p1.y) then exit(true);
    end;
    exit(false);
end;

procedure Test;
var i, j, x1, x2, x3 : longint; p1,p2 : toado;
begin
    quicksort(1,n);
    error := 0;
    for i:=1 to n  do begin
        x1 := a[i].x;
        for j:=i+1 to n do begin
            x2 := a[j].x;
            for x3:=x1 to x2 do begin
                p1.x := x3; p1.y := a[i].y;
                p2.x := x3; p2.y := a[j].y;
                if (find(p1) and find(p2)) then exit;
            end;
        end;
    end;
    error := 1;
end;
procedure StartTest; {bat dau thuc hien cham bai}
begin
   fillchar(a, sizeof(a), 0);
   read_input;
   read_output;
   if error<>0 then exit;
   Test;
end;
BEGIN
   error:=0;
   StartTest;
   if error=0 then writeln('Dung')
   else if error=3 then writeln('Sai');
   readln;
END.
