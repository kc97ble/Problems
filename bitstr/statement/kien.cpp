#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int M = 1000007, N = 100005;
int n, k, F[N], s[N];

main() {
	cin >> n >> k;
	
	F[0]=1; s[0]=1;
	for (int i=1; i<=n+1; i++) {
		F[i] = (s[i-1] - (i<=k ? 0 : s[i-k-1]) + M) % M;
		s[i] = (s[i-1] + F[i]) % M;
		//printf("F[%d] = %d\n", i, F[i]);
	}
	int P = 1;
	for (int i=1; i<=n; i++)
	P = P*2%M;
	cout << (P - F[n+1] + M) % M << endl;
}
