#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, T, x[N], t[N];

main() {
	freopen("cakes.inp", "r", stdin);
	freopen("cakes.out", "w", stdout);
	
	scanf("%d%d", &n, &T);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &x[i], &t[i]);
	
	priority_queue<int> qu;
	long Sum=0; int Max=0;
	for (int i=1; i<=n; i++) {
		if (x[i] > T) break;
		qu.push(t[i]); Sum+=t[i];
		while (Sum+x[i] > T)
		{ Sum-=qu.top(); qu.pop(); }
		Max = max(Max, (int)qu.size());
	}
	cout << Max << endl;
}
