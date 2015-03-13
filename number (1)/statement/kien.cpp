#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=102, M=1000000007;
int L, b[10];
bool FF[N][10];
long F[N][10];
long C[N][N];

long f(int n, int k) {
	if (k==10) return n==0;
	if (FF[n][k]++) return F[n][k];
	long Sum = 0;
	for (int i=b[k]; i<=n; i++)
	Sum += f(n-i, k+1) * C[n-(k==0)][i] % M;
	return F[n][k] = Sum % M;
}

main() {
	for (int i=0; i<N; i++)
		C[i][i] = C[i][0] = 1;
	for (int i=1; i<N; i++)
	for (int j=1; j<i; j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
	
	scanf("%d", &L);
	for (int i=0; i<=9; i++)
		scanf("%d", &b[i]);
	long Sum = 0;
	for (int i=1; i<=L; i++)
		Sum += f(i, 0);
	cout << Sum % M << endl;
}
