#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=102, M=1000000009;
int n, k, m;
char a[N], b[N];
long C[N][N];

long F[N][N];
int FF[N][N], t=0;

long f(int p, int q, int k) {
	if (k==0) return q==0;
	if (FF[p][k]!=t) FF[p][k]=t; else return F[p][k];
	long Sum = 0;
	for (int i=0; i<=p && i<=m; i++)
		if (m-i <= q)
		Sum += C[p][i] * C[q][m-i] % M * f(p-i+(m-i), q+i-(m-i), k-1) % M;
	//printf("f(%d, %d, %d) = %lld\n", p, q, k, Sum);
	return F[p][k] = Sum % M;
}

main() {
	for (int i=0; i<N; i++)
		C[i][0]=C[i][i]=1;
	for (int i=1; i<N; i++)
		for (int j=1; j<i; j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
	while (scanf("%d%d%d", &n, &k, &m) > 0) {
		t++;
		scanf("%s%s", a, b);
		int p=0, q=0;
		for (int i=0; i<n; i++)
		(a[i]==b[i] ? p : q)++;
		cout << f(p, q, k) << endl;
	}
}
