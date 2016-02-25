#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int n, m, P[N]; //
long W[N]; //

int at(int x) {
	if (x==P[x]) return x;
	int y = at(P[x]);
	W[x] += W[P[x]];
	return P[x]=y;
}

void solve() {
	for (int i=1; i<=m; i++) {
		char c; int x, y, z;
		scanf(" %c%d%d", &c, &x, &y);
		if (c=='?') {
			if (at(x)!=at(y)) puts("UNKNOWN");
			else printf("%d\n", W[y]-W[x]);
		} else {
			scanf("%d", &z);
			int X=at(x), Y=at(y);
			long Z = z+W[x]-W[y];
			P[X]=Y; W[X]=-Z;
		}
	}
}

main() {
	while (scanf("%d%d", &n, &m) > 0) {
		for (int i=1; i<=n; i++)
		{ P[i]=i; W[i]=0; }
		solve();
	}
}

