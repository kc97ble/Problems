#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define X first
#define Y second

const int N=2003, oo=0x3c3c3c3c;
int n, m, k;
int Earn[N], p[123];
int d[N][1<<7];
vector<int> a[N], b[N];

bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

int dijkstra() {
	priority_queue<iii> qu;
	for (int i=1; i<=n; i++)
		for (int j=0; j<(1<<k); j++)
		d[i][j] = oo;
	for (int i=1; i<=k; i++)
		{ d[p[i]][1<<i-1]=0; qu.push(iii(0, ii(p[i], 1<<i-1))); }
		
	while (qu.size()) {
		iii Pop=qu.top(); qu.pop();
		int u=Pop.Y.X, uu=Pop.Y.Y, du=Pop.X;
		if (-du!=d[u][uu]) continue;
		//printf("d[%d][%d] = %d\n", u, uu, d[u][uu]);
		if (uu==(1<<k)-1) return d[u][uu];
		
		for (int i=0; int v=a[u][i]; i++) {
			int vv = uu | Earn[v];
			int w = b[u][i] * (10-__builtin_popcount(uu)) / 10;
			if (minimize(d[v][vv], d[u][uu]+w))
			qu.push(iii(-d[v][vv], ii(v, vv)));
		}
	}
	return -1;
}

main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++) {
		int x, y, u, v;
		scanf("%d%d%d%d", &x, &y, &u, &v);
		a[x].push_back(y); b[x].push_back(u);
		a[y].push_back(x); b[y].push_back(v);
	}
	for (int i=1; i<=n; i++) 
		a[i].push_back(0);
	for (int i=1; i<=k; i++) {
		scanf("%d", &p[i]);
		Earn[p[i]]=(1<<i-1);
	}
	cout << dijkstra() << endl;
}
