#include <stdio.h>
#include <assert.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(), a.end()
const int N = 1003;
int n, m; bool c[N][N];
vector<int> a1[N], a2[N], a[N];

namespace kosaraju {
	vector<int> Finish;
	int Dfs[N], Bfs[N];
	
	void dfs(int u) {
		Dfs[u]=true;
		for (int v: a1[u])
		if (!Dfs[v]) dfs(v);
		Finish.push_back(u);
	}
	
	void bfs(int S) {
		queue<int> qu;
		qu.push(S); Bfs[S]=S;
		while (qu.size()) {
			int u=qu.front(); qu.pop();
			for (int v: a2[u]) if (!Bfs[v])
			{ qu.push(v); Bfs[v]=S; }
		}
	}
	
	void execute() {
		for (int i=1; i<=n; i++)
		if (!Dfs[i]) dfs(i);
		reverse(all(Finish));
		for (int u: Finish)
		if (!Bfs[u]) bfs(u);
		
		for (int u=1; u<=n; u++)
		for (int v: a1[u])
		c[Bfs[u]][Bfs[v]] = true;
	}
};

int Visited[N], t;
int Assigned[N];

bool visit(int u) {
	if (Visited[u]!=t) Visited[u]=t; else return false;
	for (int v: a[u])
	if (!Assigned[v] || visit(Assigned[v]))
	{ Assigned[v]=u; return true; }
	return false;
}

int Dfs[N], S;

void dfs(int u) {
	if (Dfs[u]!=S) Dfs[u]=S; else return;
	if (u!=S) a[S].push_back(u);
	for (int i=1; i<=n; i++)
	if (c[u][i]) dfs(i);
}

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a1[x].push_back(y);
		a2[y].push_back(x);
	}
	kosaraju :: execute();
	
	for (int i=1; i<=n; i++)
	if (kosaraju::Bfs[i]==i)
	{ S=i; dfs(i); }
	
	int Result=0, Count=0;
	for (int i=1; i<=n; i++)
	if (kosaraju::Bfs[i]==i)
	{ t++; Result+=!visit(i); }
	
	/*for (int i=1; i<=n; i++)
	if (kosaraju::Bfs[i]==i)
	printf("Assigned[%d] = %d\n", i, Assigned[i]);*/
	
	cout << Result << endl;
}

