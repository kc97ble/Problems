#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = (1<<20)+1;

struct fenwick_tree {
	int T[N];
	void update(int u, int x)
		{ for (int i=u; i<N; i+=i&-i) T[i]+=x; }
	int get(int u)
		{ int Sum=T[u]; while (u-=u&-u) Sum+=T[u]; return Sum; }
	void fill1(int n) {
		memset(T, 0, sizeof T);
		for (int i=1; i<=n; i++) 
		T[i]=1;
		for (int i=1; i+(i&-i)<N; i++) 
		T[i+(i&-i)] += T[i];
	}
	int lower_bound(int x) {
		int u=N-1;
		for (int i=20-1; i>=0; i--)
		if (T[u-(1<<i)]>=x) u-=(1<<i);
		else x -= T[u-(1<<i)];
		return u;
	}
} W;

int n, List[N];

main() {
	freopen("ranking.inp", "r", stdin);
	freopen("ranking.out", "w", stdout);
	
	scanf("%d", &n);
	W.fill1(n);
	for (int i=1; i<=n; i++) {
		int x; scanf("%d", &x);
		int Rank = W.lower_bound(x+1);
		List[Rank]=i;
		W.update(Rank, -1);
	}
	for (int i=1; i<=n; i++)
	printf("%d\n", List[i]);
}

