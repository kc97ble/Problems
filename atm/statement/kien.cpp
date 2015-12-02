#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500005, oo=0x3c3c3c3c;
int n, m;
int Value1[N], Value2[N];
bool Exit1[N], Exit2[N];
vector<int> a1[N], a2[N], b[N];
int Group[N];
bool Bfs[N], Dfs[N];
vector<int> List;
int F[N]; bool FF[N];

int f(int u) {
	if (FF[u]++) return F[u];
	int Max = (Exit2[u] ? 0 : -oo);
	for (int i=0; int v=b[u][i]; i++)
	Max = max(Max, f(v));
	//printf("f(%d) = %d\n", u, Max + Value2[u]);
	return F[u] = Max + Value2[u];
}

void bfs(int U) {
	queue<int> qu; 
	qu.push(U); Bfs[U]=true;
	while (qu.size()) {
		int u=qu.front(); qu.pop();
		Group[u]=U;
		//printf("%d ", u);
		for (int i=0; int v=a2[u][i]; i++)
		if (!Bfs[v]) { qu.push(v); Bfs[v]=true; }
	}
	//printf("Group=%d\n", U);
}

void dfs(int U) {
	stack<int> st; st.push(U);
	while (st.size()) {
		int u=st.top(); st.pop();
		if (u<0) {
			List.push_back(-u);
		} else if (!Dfs[u]) {
			Dfs[u] = true;
			st.push(-u);
			for (int i=0; int v=a1[u][i]; i++)
			if (!Dfs[v]) st.push(v);
		}
	}
}

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a1[x].push_back(y);
		a2[y].push_back(x);
	}
	for (int i=1; i<=n; i++) {
		a1[i].push_back(0);
		a2[i].push_back(0);
		scanf("%d", &Value1[i]);
	}
	
	int S, P;
	scanf("%d%d", &S, &P);
	
	for (int i=1; i<=P; i++) {
		int x; scanf("%d", &x);
		Exit1[x] = true;
	}
	// done a, Value1, Exit1
	
	for (int i=1; i<=n; i++)
		if (!Dfs[i]) dfs(i);
	for (int i=List.size()-1; i>=0; i--)
		if (!Bfs[List[i]]) bfs(List[i]);
	// done Group, Dfs, Bfs
	
	for (int i=1; i<=n; i++)
	if (int I = Group[i]) {
		Value2[I] += Value1[i];
		Exit2[I] |= Exit1[i];
	}
	// done Value2, Exit2
	
	for (int u=1; u<=n; u++)
	if (int U=Group[u]) {
		for (int i=0; int v=a1[u][i]; i++)
		if (U!=Group[v])
		b[U].push_back(Group[v]);
	}
	for (int i=1; i<=n; i++) {
		#define all(a) a.begin(), a.end()
		sort(all(b[i]));
		b[i].erase(unique(all(b[i])), b[i].end());
		b[i].push_back(0);	
	}
	// done b
	
	for (int i=List.size()-1; i>=0; i--)
		f(Group[List[i]]);
	cout << f(Group[S]) << endl;
}

