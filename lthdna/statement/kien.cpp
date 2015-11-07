#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 202, oo = 0x3c3c3c3c;
char s1[N], s2[N];
int n, a[N];
char Dict[128] = "ACGT";
int F[N][4][N][2][N];
int FF[N][4][N][2][N], t=0;
#define C u][k][a1][a2][a3

int f(int u, int k, int a1, int a2, int a3) {
	if (u==n+1) return 0;
	k&=3;
	if (a1>=N || a2>=2 || a3>=N) return oo;
	if (FF[C]!=t) FF[C]=t; else return F[C];
	
	int Min = oo;
	if (a[u]==k) 
		Min = min(Min, f(u+1, k, a1, a2, a3));
	else if ((k+1&3)==a[u])
		Min = min(Min, f(u+1, k+1, a1+1, a2, a3) + 1);
	else if ((k+2&3)==a[u])
		Min = min(Min, f(u+1, k+2, a1, a2+1, a3) + 1);
	else if ((k+3&3)==a[u])
		Min = min(Min, f(u+1, k+3, a1, a2, a3+1) + 1);
	if (a1) Min = min(Min, f(u, k-1, a1-1, a2, a3));
	if (a2) Min = min(Min, f(u, k-2, a1, a2-1, a3));
	if (a3) Min = min(Min, f(u, k-3, a1, a2, a3-1));
	return F[C] = Min;
}

main() {
	for (int i=0; char k=Dict[i]; i++)
		Dict[k]=i;
	while (scanf("%s%s", s1+1, s2+1) > 0) {
		t++;
		n=strlen(s1+1);
		for (int i=1; i<=n; i++)
			a[i] = (Dict[s2[i]]-Dict[s1[i]]) & 3;
		cout << f(1, 0, 0, 0, 0) << endl;
	}
}
