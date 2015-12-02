#include <bits/stdc++.h>
using namespace std;

#define long long long
const int M = 1000000007;
int n, S, T, c[123][123];
long k;

map<long, long> Map[123][123];

long f(long k, int S, int T) {
	if (k==1) return c[S][T];
	if (Map[S][T].count(k)) return Map[S][T][k];
	long k1=k/2, k2=k-k1, Sum=0;
	for (int i=1; i<=n; i++)
	Sum += f(k1, S, i) * f(k2, i, T) % M;
	return Map[S][T][k] = Sum % M;
}

main() {
	cin >> n >> S >> T >> k;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	scanf("%d", &c[i][j]);
	
	cout << f(k, S, T) << endl;
}
