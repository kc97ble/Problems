#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxN=10000+10;

int countbit(int n){
    int res=0; for(;n>0;n/=2) res++;
    return res;
}

int n,m;

void print(int n,int nb){
    for (int i=nb-1;i>=0;i--) printf("%d",(n&(1<<i))>0);
    printf("\n");
}

int main(){
    //freopen("encoding.inp","r",stdin);
    scanf("%d",&n);
    int nb=countbit(n-1);    
    m=1<<nb; //printf("m=%d\n",m);
    if (n==1) nb=1;   
    int ct=n,i=0,last=0;
    for (;i<ct&&ct<m;i+=2) if (i+1<ct){
        print(i/2,nb-1); ct++;
        last=i+2;
    }
    for(;last<ct;last++) print(last,nb);
    return 0;
}
