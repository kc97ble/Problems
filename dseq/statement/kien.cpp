#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003, oo = 0x3c3c3c3c;
int n; char a[N];
int Match[N][N];
int F[N][40];

int f(int u, int l) {
	int Max = 0;
	if (F[u][l]!=-1) return F[u][l];
	for (int i=u+l+1; i<=n; i++)
		if (a[i-(l+1)]!='0')
		Max = max(Max, f(i, l+1)+1);
	for (int i=u+l; i<=n; i++) 
	if (a[i-l]!='0') {
		int r = Match[u-l][i-l];
		if (r<l && a[i-l+r]>a[u-l+r])
		Max = max(Max, f(i, l)+1);
	}
	return F[u][l] = Max;
}

main() {
	memset(F, -1, sizeof F);
	scanf("%d%s", &n, a);
	for (int i=n-1; i>=0; i--)
	for (int j=n-1; j>=0; j--)
	Match[i][j] = (a[i]==a[j] ? Match[i+1][j+1]+1 : 0);
	
	int Max = -oo;
	for (int i=1; i<=n; i++)
	Max = max(Max, f(i, 1)+1);
	cout << Max << endl;
}

