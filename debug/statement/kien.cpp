#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long
const int N = 302;
int m, n;
char a[N][N], b[N][N];
long A[N][N], B[N][N];
long M[N*N];

void hash(char a[N][N], int m, int n, long H[N][N]) {
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	H[i][j] = a[i][j] 
		+ H[i-1][j]*M[n] 
		+ H[i][j-1]*M[1] 
		- H[i-1][j-1]*M[n+1];
}

long hash(long H[N][N], int x, int y, int u, int v) {
	x--, y--;
	return H[u][v]
		- H[u][y]*M[v-y]
		- H[x][v]*M[(u-x)*n]
		+ H[x][y]*M[(u-x)*n+(v-y)];
}

main() {
	M[0]=1; M[1]=239; for (int i=2; i<N*N; i++) M[i]=M[i-1]*M[1]; //
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
		scanf("%s", a[i]+1);
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		b[i][j]=a[m-i+1][n-j+1];
	hash(a, m, n, A);
	hash(b, m, n, B);
	/*for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++)
		printf("%lld ", B[i][j]);
		printf("\n");
	}*/
	
	int Max = 0;
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	for (int k=0; i+k<=m && j+k<=n; k++) {
		long H1 = hash(A, i, j, i+k, j+k);
		long H2 = hash(B, m-(i+k)+1, n-(j+k)+1, m-i+1, n-j+1);
		if (H1==H2) {
			//printf("(%d %d %d) = %lld\n", i, j, k, H1);
			Max = max(Max, k+1);
		}
	}
	if (Max<=1) Max=-1;
	cout << Max << endl;
}
