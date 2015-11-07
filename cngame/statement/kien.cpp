#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int n, b[123], t;
long k, M;
bool c[123][123];

long F[20][20][50][2];
int FF[20][20][50][2];
#define ff A-1][B-1][d][k&1

long indian(long a, long b, long M) {
	long Sum1 = (a>>20) * b % M;
	long Sum2 = (a&(1<<20)-1) * b % M;
	return ((Sum1<<20) + Sum2) % M;
}

long f(int A, int B, long k, int d) {
	if (k==1) return c[A][B];
	if (FF[ff]!=t) FF[ff]=t; else return F[ff];
	long Sum = 0;
	for (int i=1; i<=n; i++)
	Sum += indian(f(A, i, k/2, d+1), f(i, B, k-k/2, d+1), M);
	return F[ff] = Sum % M;
}

long G[20][50][2];
int GG[20][50][2];
#define gg A-1][d][k&1

long g(int A, long k, int d) {
	if (k==1) return c[A][n];
	if (GG[gg]!=t) GG[gg]=t; else return G[gg];
	long Sum = g(A, k/2, d+1);
	for (int i=1; i<=n; i++)
	Sum += indian(f(A, i, k/2, d+1),  g(i, k-k/2, d+1), M);
	//printf("g(%d, %lld) = %lld\n", A, k, Sum);
	return G[gg] = Sum % M;
}

long H[21][1000006];
int HH[21][1000006];

long h(int u, long k) {
	if (k==0) return u==n;
	if (HH[u][k]!=t) HH[u][k]=t; else return H[u][k];
	long Sum = (u==n);
	for (int i=1; i<=n; i++)
	if (c[u][i]) Sum += h(i, k-1);
	//if (Sum) printf("h(%d, %lld) = %lld\n", u, k, Sum);
	return H[u][k] = Sum % M;
}

bool is_prime(long n) {
	for (long i=2; i*i<=n; i++)
	if (n%i==0) return false;
	return true;
}

main() {
//	freopen("cngame.inp", "r", stdin);
//	freopen("cngame.out", "w", stdout);

	scanf("%d", &t);
	do {
		cin >> n >> k >> M;
		for (int i=1; i<=n; i++)
		scanf("%d", &b[i]);

		for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		c[i][j] = i!=j && is_prime(b[i]*6LL+b[j]);

		/*for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		printf(j==n ? "%d\n" : "%d ", c[i][j]+0);*/

		cout << g(1, k, 0) << endl;
		//cout << h(1, k) << endl;
	} while (--t);
}
