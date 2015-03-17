#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100005
int n, m, k, d[N], p[N];
vector<int> a[N];

int bfs(int u) {
	queue<int> qu;
	for (int i=0; int v=a[u][i]; i++)
	{ d[v]=0; p[v]=v; qu.push(v); }
	
	while (qu.size()) {
		int u=qu.front(); qu.pop();
		//printf("d[%d]=%d, p=%d\n", u, d[u], p[u]);
		for (int i=0; int v=a[u][i]; i++)
		if (p[v]==p[u]) 
			continue;
		else if (p[v]==0)
			{ d[v]=d[u]+1; p[v]=p[u]; qu.push(v); }
		else
			return d[u]+d[v]+1;
	}
	return -1;
}

main(){
	freopen("reinvent.in", "r", stdin);
	freopen("reinvent.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	f1(i,m) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	f1(i,n) a[i].push_back(0);
	f1(i,k) {
		int x; scanf("%d", &x);
		a[0].push_back(x);
	}
	a[0].push_back(0);
	cout << bfs(0) << endl;
}
