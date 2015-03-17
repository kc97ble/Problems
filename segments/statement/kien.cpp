#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 3003;
int n, x[N], y[N];
double b[N];

long consist(int u) {
	int m=0; long Sum=0;
	for (int i=1; i<=n; i++)
		if (i!=u) b[m++] = atan2(y[i]-y[u], x[i]-x[u]);
	sort(b, b+m);
	for (int i=0; i<m; i++)
		b[i+m] = b[i] + 2*M_PI;
	int k = 0;
	for (int i=0; i<m; i++) {
		while (b[k]<b[i]+M_PI) k++;
		Sum += (k-i-1) * (m-k+i);
	}
	long c3m = 1LL*m*(m-1)*(m-2)/1/2/3;
	return (Sum - c3m) / 2;
}

main(){
	int ax, bx, mx, ay, by, my;
	scanf("%d", &n);
	cin >> x[1] >> bx >> ax >> mx;
	cin >> y[1] >> by >> ay >> my;
	for (int i=2; i<=n; i++) {
		x[i] = (1LL*x[i-1]*ax+bx)%mx;
		y[i] = (1LL*y[i-1]*ay+by)%my;
	}
	long Y = 0;
	for (int i=1; i<=n; i++)
		Y += consist(i);
	long c4n = 1LL*n*(n-1)*(n-2)*(n-3)/1/2/3/4;
	cout << c4n-Y << endl;
}

