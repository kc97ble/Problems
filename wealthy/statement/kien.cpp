#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 30004;
int n, p[N], q[N];
int l[N], b[N], F[N], m;

bool by_pq(int x, int y)
	{ return q[x]!=q[y] ? q[x]>q[y] : p[x]>p[y]; }

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &p[i], &q[i]);
	for (int i=1; i<=n; i++) l[i]=i;
	sort(l+1, l+n+1, by_pq);
	
	for (int j=1; j<=n; j++) { 
		int i = l[j];
		F[i] = lower_bound(b+1, b+m+1, p[i]) - b;
		b[F[i]] = p[i];
		m = max(m, F[i]);
	}
	for (int i=1; i<=n; i++)
	printf("%d\n", F[i]);
}

