#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5003;
int n, m, P[N], Enabled[N]; //
vector<int> a[N]; //
bool c[N][N]; //

int latest(int u) {
	int dx=0;
	for (int v: a[u]) if (Enabled[v])
	if (dx==0 || Enabled[v]>Enabled[dx])
	dx=v;
	return dx;
}

bool solve() {
	for (int j=n; j>=1; j--) {
		int u = P[j];
		Enabled[u] = n+1-j;
		int vv = latest(u);
		
		for (int v: a[u]) 
		if (Enabled[v] && !c[vv][v]) 
		return false;
	}
	return true;
}

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%d", &P[i]);
		c[i][i] = true;
	}
	for (int i=1; i<=m; i++) {	
		int x, y; scanf("%d%d", &x, &y);
		c[x][y] = c[y][x] = true;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	puts(solve() ? "YES" : "NO");
}

