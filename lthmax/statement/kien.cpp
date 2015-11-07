#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int M = 1000000007;
int n, k;

#define N 52
long F[N][N][N*N];
bool FF[N][N][N*N];
#define C n0][n2][k

long f(int n, int n0, int n1, int n2, int k) {
	if (n==0) return k>=::k;
	if (FF[C]++) return F[C];
	long Sum = 0;
	#define try Sum +=
	if (n0) try n0 * f(n-1, n0-1, n1, n2+1, k+n); // 0-0
	if (n0>=2) try (1LL*n0*(n0-1)) * f(n-1, n0-2, n1+2, n2, k+n+n); // 0-0
	if (n0 && n1) try (1LL*n0*n1) * f(n-1, n0-1, n1, n2+1, k+n); // 0-1, 1-0
	if (n1) try (n1/2LL)*(n1/2LL) * f(n-1, n0, n1-2, n2+2, k);
	//printf("f(%d, %d, %d, %d, %d) = %lld\n", n, n0, n1, n2, k, Sum);
	return F[C] = Sum % M;
}

main() {
	cin >> n >> k;
	cout << f(n, n, 0, 0, 0) << endl;
}
