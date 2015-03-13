#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

long k;
int n, Where[10][1<<20];
char a[2309];

long F1[1<<20];
bool F2[1<<20];

long f(int u, int Used, long Index=0) {
	if (u==n) return 1;
	if (!Index && F2[Used]++) return F1[Used];
	long Sum = 0;
	f0(k,10) if (int x=Where[k][Used]) {
		if (Index && Sum+f(u+1, Used|x)>=Index)
		{ printf("%d", k); f(u+1, Used|x, Index-Sum); Index=0; }			
		Sum += f(u+1, Used|x);
	}
	return F1[Used]=Sum;
}

main(){
	freopen("numere.in", "r", stdin);
	freopen("numere.out", "w", stdout);
	
	cin >> k >> a; n=strlen(a);
	f0(i,n) f0(Used,1<<n) if ((1<<i)&(~Used))
	if (!Where[a[i]-'0'][Used]) Where[a[i]-'0'][Used]=(1<<i);	
	if (k>f(0, 0)) cout << -1 << endl;
	else { f(0, 0, k); cout << endl; }
}
