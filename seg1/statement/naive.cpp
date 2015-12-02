#include <bits/stdc++.h>
using namespace std;

#define long long long
const int N = 100005, M = 1000000007;
int n, m, a[N];

void inc_range(int L, int R, int x) {
	for (int i=L; i<=R; i++)
	a[i] = (a[i]+x)%M;
}

int sum_range(int L, int R) {
	long Sum = 0;
	for (int i=L; i<=R; i++)
	Sum += a[i];
	return (Sum%M+M)%M;
}

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=m; i++) {
		char s[4]; scanf("%s", s);
		if (s[2]=='T') { // set
			int u, x; scanf("%d%d", &u, &x);
			x -= sum_range(u, u);
			inc_range(u, u, x);
		} else if (s[2]=='C') { // inc
			int L, R, x; scanf("%d%d%d", &L, &R, &x);
			inc_range(L, R, x);
		} else if (s[2]=='M') { // sum
			int L, R; scanf("%d%d", &L, &R);
			printf("%d\n", sum_range(L, R));
		}
	}
}
