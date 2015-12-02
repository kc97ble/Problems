#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const int oo = 0x3c3c3c3c;

#define N 1000006
int n, Max=0, Min[33], Min2[N], Count[33], Used[33];
char a[N];

bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }
bool maximize(int &a, int b)
	{ if (a<b) a=b; else return false; return true; }

void consider(char u){
	f1(k,26) Min[k]=oo, Min2[k]=0, Count[k]=0;
	for (int i=1; char k=a[i]; i++){
		if (k==u) f1(v,26) minimize(Min[v], Min2[v]);
		Count[k]++;
		if (k==u) f1(v,26) minimize(Min2[v], Count[v]-Count[u]);
		if (k!=u) maximize(Max, Count[k]-Count[u]-Min[k]);
	}
	f1(k,26) maximize(Max, Count[k]-Count[u]-Min[k]);
}

main(){
	scanf("%d%s", &n, a+1);
	f1(i,n) Used[a[i]-=96]=true;
	f1(k,26) if (Used[k]) consider(k);
	cout << Max << endl;
}
