#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 250
const int oo = 0x3c3c3c3c;
int n, f[N][N], c[N][N], d[N];
double R;
int t=2309, Visited[N], Penguins=0;
int Current[N], Limit[N], x[N], y[N];
vector<int> a[N];

bool bfs(int S, int T) {
	memset(d, 0, sizeof d);
	queue<int> qu;
	qu.push(S); d[S]=1;
	while (qu.size()) {
		int u=qu.front(); qu.pop();
		if (u==T) return true;
		for (int i=0; int v=a[u][i]; i++) 
		if (d[v]==0 && f[u][v]<c[u][v]) 
		{ d[v]=d[u]+1; qu.push(v); }
	}
	return false;
}

int visit(int u, int T, int Min) {
	if (u==T) return Min;
	if (Visited[u]==t) return 0; else Visited[u]=t;
	
	for (int i=0; int v=a[u][i]; i++)
	if (d[v]==d[u]+1 && f[u][v]<c[u][v]) {
		if (int x = visit(v, T, min(Min, c[u][v]-f[u][v])))
		{ f[u][v]+=x; f[v][u]-=x; return x; }
	}
	return 0;	
}

long sqr(long x) 
	{ return x*x; }

void build(int S){
	for (int i=1; i<=n; i++) {
		a[S].push_back(i); c[S][i]+=Current[i]; // multiple graph
		a[i].push_back(S); c[i][S]+=0;
		a[i].push_back(N-i); c[i][N-i]+=Limit[i];
		a[N-i].push_back(i); c[N-i][i]+=oo;
	}
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (sqr(x[i]-x[j]) + sqr(y[i]-y[j])<=R*R+1e-9) {
		a[N-i].push_back(j); c[N-i][j]+=oo;
		a[j].push_back(N-i); c[j][N-i]+=0;
		a[N-j].push_back(i); c[N-j][i]+=oo;
		a[i].push_back(N-j); c[i][N-j]+=0;
	}
	for (int i=0; i<N; i++)
	a[i].push_back(0);
}

bool ok(int S, int T){
	int Success = 0;
	
	for (int i=0; i<N; i++)
	for (int j=0; j<N; j++)
	f[i][j]=0; // reset
		
	while (bfs(S, T)) {
		while (int x = (t++, visit(S, T, oo)))
		Success += x;
	}
	return Success == Penguins;
}

main(){
	scanf("%d%lf", &n, &R);
	for (int i=1; i<=n; i++)
	scanf("%d%d%d%d", &x[i], &y[i], &Current[i], &Limit[i]);
	for (int i=1; i<=n; i++)
	Penguins += Current[i]; // how many penguins
	
	int S = N/2;
	build(S);
	
	vector<int> T;
	for (int i=1; i<=n; i++)
	if (ok(S, i)) T.push_back(i-1);
	
	if (T.size()==0) cout << -1 << endl;
	else {
		for (int i=0; i<T.size(); i++)
		printf(i+1==T.size() ? "%d\n" : "%d ", T[i]);
	}
}
