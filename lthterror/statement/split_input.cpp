#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t=0;
char FileName[123], s[123];

main() {
	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) > 0) {
		sprintf(FileName, "lthterror.%d.in", ++t);
		cerr << FileName << endl;
		freopen(FileName, "w", stdout);
		
		printf("%d %d\n", n, m);
		for (int i=1; i<=n; i++) {
			int x; scanf("%d", &x);
			printf(i==n ? "%d\n" : "%d ", x);
		}
		for (int i=1; i<=m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			printf("%d %d\n", x, y);
		}
	}
}

