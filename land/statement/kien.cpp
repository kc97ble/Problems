#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int m, n, k, w[123], h[123], l[123];
bool a[123][123];

bool empty(int x, int y, int W, int H) {
	for (int i=0; i<W; i++)
	for (int j=0; j<H; j++)
	if (a[i+x][j+y]) return false;
	return true;
}

void fill(int x, int y, int W, int H, int k) {
	for (int i=0; i<W; i++)
	for (int j=0; j<H; j++)
	a[i+x][j+y]=k;
}

bool ok(int u, int W, int H) {
	if (u==-1) return true;
	for (int i=1; i<=m-W+1; i++)
	for (int j=1; j<=n-H+1; j++)
	if (empty(i, j, W, H)) {
		fill(i, j, W, H, 1);
		if (ok(u-1, w[l[u-1]], h[l[u-1]])) return true;
		if (ok(u-1, h[l[u-1]], w[l[u-1]])) return true;
		fill(i, j, W, H, 0);
	}
	return false;
}

bool by_size(int u, int v) {
	return w[u]*h[u] < w[v]*h[v];
}

main(){
	scanf("%d%d%d", &m, &n, &k);
	for (int i=1; i<=k; i++)
		scanf("%d%d", &w[i], &h[i]);
	for (int i=0; i<=k; i++)
		l[i]=i;
	
	for (int p=min(m, n); p>=1; p--) {
		w[0]=h[0]=p;
		sort(l, l+k+1, by_size);
		if (ok(k, w[l[k]], h[l[k]]) || ok(k, h[l[k]], w[l[k]])) 
			{ cout << p*p << endl; return 0; }
	}
	cout << 0 << endl;
}
