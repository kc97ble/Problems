#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int n, x[N], y[N], z[N];
int a[N][N], c[N][N], s[N][N];
bool ok[N][N];

main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &x[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &y[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &z[i]);
	for (int i=1; i<=n; i++) {
		a[x[i]][y[i]]+=z[i];
		c[x[i]][y[i]]++;
	}
	for (int i=1; i<=1000; i++)
	for (int j=1; j<=1000; j++) {
		c[i][j] += c[i][j-1] + c[i-1][j] - c[i-1][j-1];
		s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	}
	int Max = 0;
	ok[1][1] = true;
	for (int i=1; i<=1000; i++)
	for (int j=1; j<=1000; j++) {
		if (!ok[i][j]) continue;
		Max = max(Max, c[i][1000]+c[1000][j]-c[i][j]);
		if (s[i][1000]+s[1000][j]-s[i][j] > i+j-2)
			ok[i+1][j] = ok[i][j+1] = true;
	}
	cout << Max << endl;
}

