#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int n, m, c[N][N], d[N];
int G, b[N], L[N][N], R[N][N];
bool Done[N];

int dijkstra(int S, int T, int DS) {
	memset(d, 0x3c, sizeof d);
	d[S]=DS;
	int u=S;
	while (u!=T) {
		Done[u]=true;
		for (int v=1; v<=n; v++)
		if (!Done[v] && c[u][v])
		if (d[u]>=L[u][v] && d[u]<=R[u][v])
			d[v]=min(d[v], R[u][v]+c[u][v]);
		else
			d[v]=min(d[v], d[u]+c[u][v]);
		
		for (int i=1; i<=n; i++) if (!Done[i])
		if (Done[u] || d[u]>d[i]) 
		u=i;
	}
	return d[T];
}

main() {
	//freopen("bill.inp", "r", stdin)&&
	//freopen("bill.out", "w", stdout);
	int S, T, DS;
	cin >> n >> m;
	cin >> S >> T >> DS >> G;
	for (int i=1; i<=G; i++)
		scanf("%d", &b[i]);
	for (int i=1; i<=m; i++) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		c[x][y]=c[y][x]=w;
	}
	int Time = 0;
	for (int i=2; i<=G; i++) {
		L[b[i-1]][b[i]] = L[b[i]][b[i-1]] = Time;
		Time += c[b[i-1]][b[i]];
		R[b[i-1]][b[i]] = R[b[i]][b[i-1]] = Time;
	}
	cout << dijkstra(S, T, DS)-DS << endl;
}
