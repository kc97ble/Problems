#include <bits/stdc++.h>
using namespace std;

#define long long long
const int N = 100005;
int n, m; long a[N];

void inc_range(int L, int R, long X) {
	for (int i=L; i<=R; i++)
	a[i] += X;
}

int lower_bound(int L, long X) {
	long Sum=0;
	for (int i=L; i<=n; i++) {
		Sum += a[i];
		if (Sum>=X) return i;
	}
	return -1;
}

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	for (int i=1; i<=m; i++) {
		char s[4]; scanf("%s", s);
		if (s[0]=='I') {
			int L, R; long X; scanf("%d%d%lld", &L, &R, &X);
			inc_range(L, R, X);
		} else {
			int L; long X; scanf("%d%lld", &L, &X);
			int R = lower_bound(L, X);
			printf("%d\n", R);
		}
	}
}
