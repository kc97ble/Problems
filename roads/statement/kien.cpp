#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 1003;
const int oo = 0x3c3c3c3c;

int n, m, x[N], y[N];
bool b[N][N];
long d[N];
bool Locked[N];

long sd(int p, int q) {
	long dx = x[p]-x[q];
	long dy = y[p]-y[q];
	return dx*dx+dy*dy;
}

int best() {
	int u = 0; // 0 default
	for (int i=1; i<=n; i++) if (!Locked[i])
	if (u==0 || d[i]<d[u]) u=i;
	return u;
}

double prim(int u) {
	for (int i=1; i<=n; i++)
		d[i] = 1LL*oo*oo;
	d[u]=0;
	double Sum = 0;

	while (int u = best()) {
		Sum += sqrt(d[u]);
		Locked[u] = true;
		for (int i=1; i<=n; i++) if (!Locked[i])
		d[i] = min(d[i], b[u][i] ? 0LL : sd(u, i));
	}
	return Sum;
}

main(){
	//freopen("input", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for (int i=1; i<=m; i++) {
		int p, q; 
		scanf("%d%d", &p, &q);
		b[p][q] = b[q][p] = true;
	}
	(cout << fixed).precision(2);
	cout << prim(1) << endl;
}
