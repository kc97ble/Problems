#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=10004, oo=0x3c3c3c3c;
int n, m, k, Edge[N];
int p[N], q[N], w[N];
long pe[1003][1003];
long c[1003][1003], d[N];
bool Used[N];

void floyd() {
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	c[i][j] = (i==j ? 0 : 1LL*oo*oo);
	
	for (int i=1; i<=m; i++) {
		int p=::p[i], q=::q[i], w=::w[i];
		c[p][q] = c[q][p] = w;
	}
	
	for (int k=1; k<=n; k++)
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
}

bool as_w(int x, int y)
	{ return w[x]<w[y]; }

main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++)
	scanf("%d%d%d", &p[i], &q[i], &w[i]);
	for (int i=1; i<=m; i++) Edge[i]=i;
	sort(Edge+1, Edge+m+1, as_w);
	
	floyd(); // done c
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		pe[i][j] = 1LL*oo*oo;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int u=::p[j], v=::q[j], w=::w[j];
			if (c[u][i]>c[v][i]) swap(u, v);
			if (c[v][i]==c[u][i]+w)
			pe[v][i] = min(pe[v][i], (long)w);
		}
	}
	
	while (k--) {
		long Sum=0;
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		for (int i=1; i<=n; i++)
			d[i] = min(c[i][x], min(c[i][y], c[i][z]));
		for (int i=1; i<=n; i++)
		if (i!=x && i!=y && i!=z) {
			long wx=pe[i][x], wy=pe[i][y], wz=pe[i][z];
			long Min = 1LL*oo*oo;
			if (d[i]==c[i][x]) Min=min(Min, wx);
			if (d[i]==c[i][y]) Min=min(Min, wy);
			if (d[i]==c[i][z]) Min=min(Min, wz);
			Sum += Min;
		}
		cout << Sum << "00" << endl;
	}
	
}
