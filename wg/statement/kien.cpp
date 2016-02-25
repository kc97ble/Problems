#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1003, oo=0x3c3c3c3c;
char b[N], a[N][123]; int n;
int m, Length[N], L[N], R[N];

int G[N][N];
bool GG[N][N];

int next(int u, int x) {
	if (GG[u][x]++) return G[u][x];
	int o = u;
	for (int i=1; char c=a[x][i]; i++)
	if (c==b[u]) u++;
	return G[o][x] = u;
}

int F[N][26][30];
bool FF[N][26][30];
#define C u][c-'a'][Bad

int f(int u, char c, int Bad) {
	if (Bad==27) return oo;
	if (u==n+1) return 0;
	if (FF[C]++) return F[C];
	int Min = oo;
	for (int i=1; i<=m; i++) if (L[i]==c)
	if (R[i]!=L[i] || next(u, i)!=u)
	Min = min(Min, f(next(u, i), R[i], next(u, i)==u ? Bad+1 : 0) + (Length[i]-1));
	return F[C] = Min;
}

main() {
	scanf("%s", b+1); n=strlen(b+1);
	scanf("%d", &m);
	for (int i=1; i<=m; i++) {
		scanf("%s", a[i]);
		Length[i] = strlen(a[i]);
		L[i] = a[i][0];
		R[i] = a[i][Length[i]-1];
	}
	
	int Min = oo;
	for (int i='a'; i<='z'; i++)
	Min = min(Min, f(i==b[1] ? 2 : 1, i, 0)+1);
	if (Min==oo) Min=-1;
	cout << Min << endl;
}
