#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, x[52], y[52];
int FF[52][10004];
bool F[52][10004];

int ceil(int x, int y)
	{ return x/y + !!(x%y); }
int h(int l, int n) 
	{ return 1LL * ((l+1)+(l+n)) * n / 2; }

int f(int u, int l) {
	if (F[u][l]++) return FF[u][l];
	int Max = 0;
	for (int i=1; i<=n; i++) {
		int dx=x[i]-x[u], dy=y[i]-y[u];
		if (x[i]>x[u] && h(l,dx) <= dy) 
		Max = max(Max, f(i, l+dx + ceil(dy-h(l,dx), dx))+1);
	}
	return FF[u][l]=Max;
}

main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &y[i], &x[i]);
	cout << f(0, 0) << endl;
}
