#include <fstream.h>
long sw,i,j,a[10],t[10],s,x[10000],n;
int cauta(long k){
long m,p,u;
p=1;u=n;
while (p<=u)
{
 m=(p+u)/2;
 if(x[m]==k) return m;
  else
   if(k<x[m]) u=m-1;
    else
     p=m+1;
}
return 0;
}
int main(){
ifstream fin("dartz.in");
fin>>s;
fin.close();
cout<<s<<'\n';
n=1;
while (n*(n*n-1)<=s)
{
x[n]=n*(n*n-1);n++;//cout<<x[n-1]<<" ";
}
n--;
ofstream fout("dartz.out");
if (s%2) {fout<<0;fout.close();return 0;}
sw=1;
i=1;
while (sw){
a[1]=x[i];
a[2]=s/2-a[1];
j=cauta(a[2]);
if (j>0)
      {
       sw=0;
       fout<<i-1<<" "<<j-1<<" "<<i-1<<" "<<j-1;
       fout.close(); return 0;
      }
i++;
}
fout<<0;
 fout.close();
 return 0;
}