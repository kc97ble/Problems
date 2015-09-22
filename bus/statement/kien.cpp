#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int oo = 0x3c3c3c3c;
int n, K, L, x[11], y[11];
int F[50][1<<10][1<<10];
int pq, p[123], q[123], w[123];

main() {
	scanf("%d%d%d", &n, &K, &L);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &x[i], &y[i]);
	
	for (int i=1; i<=n-1; i++)
	for (int j=i+1; j<=n; j++)
	if (abs(x[i]-x[j]) + abs(y[i]-y[j]) >= L) { 
		pq++; p[pq]=i; q[pq]=j; 
		w[pq]=abs(x[i]-x[j]) + abs(y[i]-y[j]);
	}
	
	for (int u=0; u<=pq; u++)
	for (int A=0; A<(1<<n); A++)
	for (int B=0; B<(1<<n); B++) 
	if (K==1 && B || K==2 && (B&A)) 
		F[u][A][B] = oo;
	else if (u==0)
		F[u][A][B] = (A || B ? oo : 0);
	else {
		#define shl(x) (1<<(x)-1)
		F[u][A][B] = F[u-1][A][B];
		if (((A|B)&shl(p[u])) || ((A|B)&shl(q[u]))) {
			int AA = A ^ shl(p[u]) ^ shl(q[u]);
			int BB = B ^ (shl(p[u])&~A) ^ (shl(q[u])&~A);
			F[u][A][B] = min(F[u][A][B], F[u-1][AA][BB]+w[u]);
		}
	}
	
	int dx=0, dy=0;
	if (int u=pq)
	for (int A=0; A<(1<<n); A++)
	for (int B=0; B<(1<<n); B++)
	if (F[u][A][B]<oo) {
		int PopCount = __builtin_popcount(B)*2 + __builtin_popcount(A);
		if (dx<PopCount) { dx=PopCount; dy=oo; }
		if (dx==PopCount) dy=min(dy, F[u][A][B]);
	}
	cout << dx/2 << " " << dy << endl;
}

