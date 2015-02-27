#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 32;
char s[N][N];
int m, n, R, Node[N][N];
int Prev[N*N], x[N*N], y[N*N], Peak=0;
int Visited[N*N], t=0;
vector<int> a[N*N];
#define s(u) s[::x[u]][::y[u]]

bool visit(int u) {
	if (Visited[u]!=t) Visited[u]=t; else return false;
	if (s(u)=='S') return true;

	for (int i=0; int v=a[u][i]; i++)
	if (v==Prev[u]) {
		if (visit(v)) { Prev[u]=0; return true; }
	} else if (Prev[v]==u) {
		continue;
	} else if (Prev[v]==0) {
		if (visit(v)) { Prev[v]=u; return true; }
	} else if (Prev[v]!=-1 && Visited[v]!=t) {
		if (visit(Prev[v])) { Prev[v]=u; return true; }
	}
	return false;
}

struct double_queue {
	int S, T, a[N*N], b[N*N];
	void push(int x, int y)
		{ a[T]=x; b[T]=y; T++; }
	void pop(int &x, int &y)
		{ x=a[S]; y=b[S]; S++; }
} qu;

int d[N][N], MaxD=0;
int rx[]={-1,0,1,0};
int ry[]={0,-1,0,1};

void bfs(int u, int R) {
	qu.S=qu.T=0; qu.push(x[u], y[u]);
	int Start = d[x[u]][y[u]] = MaxD+1;

	while (qu.S != qu.T) {
		int x, y; qu.pop(x, y);
		if (MaxD=d[x][y], MaxD-Start>=R) return;
		for (int i=0; i<4; i++) {
			int xx=x+rx[i], yy=y+ry[i];
			if (s[xx][yy]=='.' && d[xx][yy]<Start) {
				d[xx][yy]=d[x][y]+1;
				qu.push(xx, yy);
			}
			if (int v=Node[xx][yy]) if (s(v)!='W')
				{ a[u].push_back(v); a[v].push_back(u); }
		}
	}
}

main() {
	scanf("%d%d%d", &m, &n, &R);
	for (int i=1; i<=m; i++)
		scanf("%s", s[i]+1);
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		if (s[i][j]=='G' || s[i][j]=='S' || s[i][j]=='W')
		{ int u=++Peak; x[u]=i, y[u]=j; Node[i][j]=u; }
	for (int i=1; i<=Peak; i++)
		if (s(i)=='W') bfs(i, R);
	for (int i=1; i<=Peak; i++)
		a[i].push_back(0);
	/*for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++)
		printf("%d", Node[i][j]);
		printf(" Node[%d]\n", i);
	}
	for (int u=1; u<=Peak; u++) {
		for (int i=0; int v=a[u][i]; i++)
		printf("%d -> %d\n", u, v);
	}*/
	int Success = 0;
	for (int i=1; i<=Peak; i++)
	if (s(i)=='G') {
		if (Prev[i]==0) {
			if (++t, visit(i))
			{ Prev[i]=-1; Success++; }
		} else {
			if (++t, visit(Prev[i]))
			{ Prev[i]=-1; Success++; }
		}
	}
	cout << Success << endl;
}
