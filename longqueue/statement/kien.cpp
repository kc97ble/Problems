#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;
int n, m, k, a[N], s[N];

main() {
	freopen("longqueue.inp", "r", stdin);
	freopen("longqueue.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] = (a[i]>=k);
		s[i] = s[i-1] + a[i];
	}
	scanf("%d", &m);
	
	int L=1, R=n+1;
	while (m--) {
		int c; scanf("%d", &c);
		if (c==1) {
			int x; scanf("%d", &x);
			a[R] = (x>=k);
			s[R] = s[R-1] + a[R];
			R++;
		} else if (c==2) {
			L++;
		} else if (c==3) {
			int x; scanf("%d", &x);
			printf("%d\n", s[L+x-1]-s[L-1]);
		}
	}
}
