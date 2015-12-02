#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=100005, M=1000000007;
int n, a[N], b[N];
int m, c[N], X[N], Y[N];
long Result[N];

struct worker {
	int T[N];
	void clear()
		{ memset(T, 0, sizeof T); }
	void update(int u, int x)
		{ if (x) for (int i=u; i<N; i+=i&-i) T[i]+=x; }
	int get(int u)
		{ int Sum=T[u]; while (u-=u&-u) Sum+=T[u]; return Sum; }
} Worker;

struct numeric {
	bool np[N];
	numeric() {
		np[0]=np[1]=true;
		for (int i=2; i*i<N; i++)
		for (int j=i*i; j<N; j+=i)
		np[j] = true;
	}
} Numeric;

int h(int x, int p) {
	int Count = 0;
	while (x%p==0) { Count++; x/=p; }
	return Count;
}

void solve(int p) {
	Worker.clear();
	for (int i=1; i<=n; i++)
		b[i] = h(a[i], p);
	for (int i=1; i<=n; i++)
		Worker.update(i, b[i]);
	for (int i=1; i<=m; i++) {
		int x=X[i], y=Y[i];
		if (c[i]==0) {
			if (int z = h(y, p)-b[x]) {
				Worker.update(x, z);
				b[x] += z;
			}
		} else {
			int z = Worker.get(y) - Worker.get(x-1) + 1;
			Result[i] = (Result[i] * z) % M;
		}
	}
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	scanf("%d%d%d", &c[i], &X[i], &Y[i]);
	
	for (int i=1; i<=m; i++)
	Result[i] = 1;
	
	for (int i=2; i<=10000; i++)
	if (!Numeric.np[i])
	solve(i);
	
	for (int i=1; i<=m; i++)
	if (c[i]==1)
	printf("%d\n", int(Result[i]));
}

