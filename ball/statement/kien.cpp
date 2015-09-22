#include <bits/stdc++.h>
using namespace std;

#define long long long
const int M = 1000000007, N = 2003;

long C[N][N], F[N];

main() {
	for (int i=0; i<N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i=1; i<N; i++)
	for (int j=1; j<i; j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
	F[0]=1;
	for (int i=1; i<N; i++)
		F[i] = F[i-1] * (2*i-1)*2 %M;
	
	int t; scanf("%d", &t);
	while (t-->0) {
		int n; scanf("%d", &n);
		long Sum = 0;
		for (int i=1; i<=n; i++)
		Sum += F[i-1] * F[n-i] %M * (2*n-1)*2 %M * C[2*n-2][2*i-2] %M;
		cout << Sum%M << endl;
	}
}

