#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 3003;
int n, x[N], y[N];
double b[N];

int consist(int u) {
	long S=0; int m=0;
	for (int i=1; i<=n; i++) if (i!=u)
		b[m++] = atan2(y[i]-y[u], x[i]-x[u]);
	sort(b, b+m);
	for (int i=0; i<m; i++)
		b[i+m] = b[i]+2*M_PI;
	int k = 0;
	for (int i=0; i<m; i++) {
		while (b[k]<b[i]+M_PI) k++;
		S += (k-i-1) * (m-k+i);
	}
	long c3m = 1LL*m*(m-1)*(m-2)/1/2/3;
	return (S-c3m)/2;
}

main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &x[i], &y[i]);
	long Y = 0;
	for (int i=1; i<=n; i++)
		Y += consist(i);
	long c4n = 1LL*n*(n-1)*(n-2)*(n-3)/1/2/3/4;
	long c3n = 1LL*n*(n-1)*(n-2)/1/2/3;
	(cout << fixed).precision(6);
	cout << 1.*(Y+(c4n-Y)*2)/c3n+3.0 << endl;
}

