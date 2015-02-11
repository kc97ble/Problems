#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 123;
int m, n, x[7], y[7], of[N][N];
char IsTarget[N*N], Visited[N*N], t=0;
int Adj[4][N*N], Prev[N*N];

bool visit(int u) {
	if (Visited[u]==t) return false;
	else Visited[u]=t;
	if (IsTarget[u]) return true;
	for (int i=0; i<=3; i++)
	if (int v=Adj[i][u]) {
		if (Prev[v]==u)
			continue;
		else if (Prev[u]==v) {
			if (visit(v))
			{ Prev[u]=0; return true; }
		} else if (Prev[v]==0) {
			if (visit(v))
			{ Prev[v]=u; return true; }
		} else if (Prev[v]!=-1) {
			if (Visited[v]!=t && visit(Prev[v]))
			{ Prev[v]=u; return true; }
		}
	}
	return false;
}

void enter() {
	scanf("%d%d", &m, &n);
	for (int i=0; i<=6; i++) scanf("%d", &x[i]);
	for (int i=0; i<=6; i++) scanf("%d", &y[i]);
	vector<int> xkey, ykey;
	for (int i=0; i<=6; i++) {
		int A=max(1, x[i]-4), B=min(m, x[i]+4);
		for (int j=A; j<=B; j++) xkey.push_back(j);
		int C=max(1, y[i]-4), D=min(n, y[i]+4);
		for (int j=C; j<=D; j++) ykey.push_back(j);
	}
	#define all(a) a.begin(), a.end()
	#define sort_unique(a) sort(all(a)), a.erase(unique(all(a)), a.end())
	sort_unique(xkey); m=xkey.size();
	sort_unique(ykey); n=ykey.size();
	#define index_of(x, a) (lower_bound(all(a), x) - a.begin() + 1)
	for (int i=0; i<=6; i++) {
		x[i] = index_of(x[i], xkey);
		y[i] = index_of(y[i], ykey);
	}
	/*char c[m+2][n+2];
	memset(c, 0, sizeof c);
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		c[i][j]='0';
	for (int i=0; i<=6; i++)
		c[x[i]][y[i]]=i+'1';
	for (int i=1; i<=m; i++)
		printf("%s\n", c[i]+1);*/
}

void build() {
	int Peak=0;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		of[i][j]=++Peak;
	of[x[0]][y[0]] = 0;
	if (Peak>=N*N) cerr << "Peak = " << Peak << endl;

	int rx[]={-1,0,1,0}, ry[]={0,-1,0,1};
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	for (int k=0; k<=3; k++) {
		int x=i+rx[k], y=j+ry[k];
		Adj[k][of[i][j]] = of[x][y];
	}
}

main(){
	enter();
	build();
	for (int i=4; i<=6; i++)
		IsTarget[of[x[i]][y[i]]]=true;
	for (int i=1; i<=3; i++) {
		int u = of[x[i]][y[i]];
		if (Prev[u]==0) {
			if (++t, visit(u)) Prev[u]=-1;
			else { cout << "No" << endl; cerr << i << " 1\n"; return 0; }
		} else {
			if (++t, visit(Prev[u])) Prev[u]=-1;
			else { cout << "No" << endl; cerr << i << " 2\n"; return 0; }
		}
		/*for (int i=1; i<=m; i++) {
			for (int j=1; j<=n; j++)
			printf("%d ", Prev[of[i][j]]);
			printf("Prev[%d]\n", i);
		}
		for (int i=1; i<=m; i++) {
			for (int j=1; j<=n; j++)
			printf("%d ", of[i][j]);
			printf("of[%d]\n", i);
		}*/
	}

	cout << "Yes" << endl;
}
