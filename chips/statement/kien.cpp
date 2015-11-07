#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=200005, oo=0x3c3c3c3c;
int n, M, P[N], Q[N], Time=0;
int ll[N], rr[N], Earn[N], Next[N];
vector<int> a[N];

void visit(int u, int p) {
	//printf("%d ", u);
	ll[u]=++Time; Earn[ll[u]]=Q[u];
	for (int i=0; int v=a[u][i]; i++)
	if (v!=p) visit(v, u);
	rr[u]=Time; Next[ll[u]]=rr[u]+1;
	//printf("{%d} ", u);
}

int F[2][N];

inline int f(int x, int m, bool Solved=true) {
	if (m==0) return 0;
	if (x==n+1) return -oo;
	#define THIS m&1][x
	if (Solved) return F[THIS];
	int Max1 = f(Next[x], m-1) + Earn[x];
	int Max2 = f(x+1, m);
	return F[THIS] = max(Max1, Max2);
}

main() {
	scanf("%d%d", &n, &M);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &P[i], &Q[i]);
		a[P[i]].push_back(i);
	}
	for (int i=1; i<=n; i++) 
		a[i].push_back(0);
	visit(a[0][0], 0);
	for (int k=0; k<=M; k++)
		for (int i=n; i>=1; i--)
		f(i, k, false);
	cout << f(1, M) << endl;
}
