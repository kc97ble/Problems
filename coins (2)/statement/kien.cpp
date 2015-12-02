#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300005;
int n, m, K;
int F1[N], F2[N];
bool FF1[N], FF2[N];
vector<int> a[N], a1[N], a2[N], G1[N], G2[N];

int f1(int u, int U) {
	if (FF1[u]++) return F1[u];
	G1[U].push_back(u);
	int Max = 0;
	for (int i=0; int v=a[u][i]; i++)
		Max = max(Max, f1(v, U));
	for (int i=0; int v=a1[u][i]; i++)
		Max = max(Max, f1(v, v)+1);
		
	if (u==U) {
		G1[u].push_back(0);
		for (int i=0; int v=G1[u][i]; i++)
		F1[v] = Max;
	}
	return F1[u] = Max;
}

int f2(int u, int U) {
	if (FF2[u]++) return F2[u];
	G2[U].push_back(u);
	int Max = 0;
	for (int i=0; int v=a[u][i]; i++)
		Max = max(Max, f2(v, U));
	for (int i=0; int v=a2[u][i]; i++)
		Max = max(Max, f2(v, v)+1);
		
	if (u==U) {
		G2[u].push_back(0);
		for (int i=0; int v=G2[u][i]; i++)
		F2[v] = Max;
	}
	return F2[u] = Max;
}

main() {
	freopen("coins.inp", "r", stdin);
	freopen("coins.out", "w", stdout);
	
	scanf("%d%d%d", &K, &n, &m);
	for (int i=1; i<=m; i++) {
		int x, y; char c;
		scanf("%d%c%d", &x, &c, &y);
		if (c=='=') {
			a[x].push_back(y);
			a[y].push_back(x);
		} else if (c=='<') {
			a1[x].push_back(y);
			a2[y].push_back(x);
		}
	}
	for (int i=1; i<=n; i++) {
		a[i].push_back(0);
		a1[i].push_back(0);
		a2[i].push_back(0);
	}
	for (int i=1; i<=n; i++)
		if (!FF1[i]) f1(i, i);
	for (int i=1; i<=n; i++)
		if (!FF2[i]) f2(i, i);
		
	//for (int i=1; i<=n; i++) printf("%d ", F1[i]); puts("F1");
	//for (int i=1; i<=n; i++) printf("%d ", F2[i]); puts("F2");
	
	for (int i=1; i<=n; i++)
	if (F1[i]+F2[i]==K-1)
		printf("K%d\n", F2[i]+1);
	else
		puts("?");
}
