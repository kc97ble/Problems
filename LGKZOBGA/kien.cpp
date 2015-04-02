#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 52
const int M = 1000000007;
int n, k;
bool F1[2*N][N][2][N*N];
long F2[2*N][N][2][N*N];
#define C n][l0][l1&1][k-min(Used, k)

long f(int n, int l0, int l1, int Used) {
	if (n==0) return l0==0 && l1==0 && Used>=k;
	if (F1[C]++) return F2[C];
	long Sum = f(n-1, l1, l0+1, Used+(n+1)/2);
	if (l1) Sum += f(n-1, l1-1, l0, Used) * l1;
	//printf("f(%d, %d, %d, %d) = %lld\n", n, l0, l1, Used, Sum);
	return F2[C] = Sum % M;
}

long gt(int n) 
	{ long P=1; f1(i,n) P=P*i%M; return P; }

main(){
	while (scanf("%d%d", &n, &k) > 0)
	if (n!=0 || k!=0)
	cout << (f(2*n, 0, 0, 0) * gt(n) % M) << endl;
}
