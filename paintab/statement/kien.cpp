#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int m, n, a[N], b[N];

bool solve() {
	long SumA=0, SumB=0;
	for (int i=1; i<=n; i++) {
		SumA += a[i];
		SumB += b[i];
		if (SumB > SumA)
		return false;
	}
	return SumA==SumB;
}

main() {
	int t; scanf("%d", &t);
	while (t-->0) {
		scanf("%d%d", &m, &n);
		for (int i=1; i<=m; i++) 
			{ int x; scanf("%d", &x); a[x]++; }
		for (int i=n; i>=1; i--)
			a[i] += a[i+1];
		for (int i=1; i<=n; i++)
			scanf("%d", &b[i]);
		sort(b+1, b+n+1, greater<int>());
		
		//for (int i=1; i<=n; i++) printf("%d ", a[i]); cout << endl;
		cout << solve() << endl;
		
		memset(a, 0, sizeof a);
	}
}

