#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 3003;
int m, n;
char a[N], b[N];
char a1[N], b1[N];
long a2[N], b2[N];
long G[N][N];
long F[N][N];
bool FF[N][N];

int convert(char a[], char b[], long d[]) {
	int n=0;
	for (int i=1; char c=a[i]; i++) {
		if (c>96) b[++n]=c;
		else d[n]=d[n]*10+(c-'0');
	}
	return n;
}

long f(int m, int n) {
	if (m==0 || n==0) return 0;
	if (FF[m][n]++) return F[m][n];
	long Max = max(f(m-1, n), f(m, n-1));
	if (a1[m]!=b1[n]) return F[m][n] = Max;
	
	char c=a1[m];
	int i=m-1, j=n-1;
	long A=a2[m], B=b2[n];
	Max = max(Max, f(i, j) + min(A, B));
	
	while (i || j) {
		if (i==0 && A<=B || j==0 && B<=A) break;
		while (i && A<=B) if (a1[i--]==c) 
		{ A+=a2[i+1]; Max = max(Max, f(i, j) + min(A, B)); }
		while (j && B<=A) if (b1[j--]==c)
		{ B+=b2[j+1]; Max = max(Max, f(i, j) + min(A, B)); }
	}
	//printf("f(%d, %d) = %lld\n", m, n, Max);
	return F[m][n] = Max;
}

main() {
//	freopen("lcrle.inp", "r", stdin);
//	freopen("lcrle.out", "w", stdout);
	scanf("%s%s", a+1, b+1);
	m=convert(a, a1, a2);
	n=convert(b, b1, b2);
	cout << f(m, n) << endl;
	
	long Max = 0;
	for (int i=m; i>=1; i--)
	for (int j=n; j>=1; j--)
	if (a1[i]==b1[j]) {
		if (a2[i]==b2[j]) {
			G[i][j] = G[i+1][j+1] + a2[i];
			Max = max(Max, G[i][j]);
		} else {
			G[i][j] = min(a2[i], b2[j]);
			Max = max(Max, G[i][j] + G[i+1][j+1]);
		}
	}
	cout << Max << endl;
}
