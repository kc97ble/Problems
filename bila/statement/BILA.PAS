const
  dx:array[1..4]of integer=(0,0,1,-1);
  dy:array[1..4]of integer=(1,-1,0,0);
var a, b:array[0..126,0..126]of word;
    i,j,n,m,y,h,max,t,v,p,k,x,q,min,nr:word; ok:boolean;
begin
  assign(input,'bila.in');reset(input);
  assign(output,'bila.out');rewrite(output);
  readln(n,m);
  for i:=0 to n+1 do
    for j:=0 to m+1 do
      if (i in [0,n+1]) or (j in [0,m+1]) then a[i,j]:=65001 else read(a[i,j]);
  max:=0;h:=65001;
  for i:=1 to n do
    for j:=1 to m do begin
      x:=i; y:=j; ok:=true; nr:=0;
      if b[i,j]=0 then begin
       while ok do begin
         min:=a[x,y];v:=0;
         for k:=1 to 4 do
          if a[x+dx[k],y+dy[k]]<min then begin
               min:=a[x+dx[k],y+dy[k]];
               v:=k;
         end;
         inc(b[i,j]);
         if v=0 then ok :=false
         else begin
           x:=x+dx[v]; y:=y+dy[v];
           if b[x,y]<>0 then begin
             inc(b[i,j],b[x,y]);
             break;
           end;
         end;
       end;
       p:=i; q:=j;
       if b[p,q]>max then begin
         max:=b[p,q]; h:=a[p,q]; end
       else if (b[p,q]=max)and(h>a[p,q]) then h:=a[p,q];
       while (p<>x)or(q<>y) do begin
         min:=a[p,q];v:=0;
         for k:=1 to 4 do
          if a[p+dx[k],q+dy[k]]<min then begin
               min:=a[p+dx[k],q+dy[k]];
               v:=k;
          end;
          b[p+dx[v],q+dy[v]]:=b[p,q]-1;
          p:=p+dx[v];
          q:=q+dy[v];
       end;
     end;
    end;
    writeln(max,' ',h);
    close(output);
end.
