#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 1003;
int m, n, x[N], y[N], z[N]; //
long F[N]; 
int FF[N], t=0; //

void add(int a, int b, int c) 
	{ ++m; x[m]=min(a, b); y[m]=max(a, b); z[m]=c; }

long f(int u) {
	if (FF[u]!=t) FF[u]=t; else return F[u];
	long Max = 0;
	for (int i=1; i<=m; i++)
	if (x[i]<x[u] && y[i]<y[u])
	Max = max(Max, f(i));
	return F[u] = Max + z[u];
}

main() {
	while (++t) {
		scanf("%d", &n);
		if (n==0) return 0;
		for (int i=1; i<=n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
			add(y, z, x);
			add(z, x, y);
		}
		long Max = 0;
		for (int i=1; i<=m; i++)
		Max = max(Max, f(i));
		cout << Max << endl;
		
		m=0;
	}
}
