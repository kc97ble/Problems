#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define X first
#define Y second
#define each(it, a) (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)

#define N 40004
vector<int> a[N];
int n, d[N], Size[N], Value[N];

int previsit(int u, int p) {
	Size[u]=1;
	for (int i=0; int v=a[u][i]; i++)
	if (!d[v] && v!=p) Size[u] += previsit(v, u);
	return Size[u];	
}

int biggest_child(int u, int p) {
	int Best = 0;
	for (int i=0; int v=a[u][i]; i++) if (!d[v] && v!=p)
	if (Size[v]>Size[Best]) Best=v;
	return Best;
}

int centroid(int u) {
	int Key = previsit(u, u) / 2;
	int v = biggest_child(u, u);
	while (Size[v] > Key) 
		{ int p=u; u=v; v=biggest_child(u, p); }
	return u;
}

void maximize(map<int, int> &Map, int Key, int Value) {
	if (!Map.count(Key) || Map[Key]<Value) 
	Map[Key]=Value;
}

void discover(int u, int p, int Sum, int MinSum, int MaxSum, map<int, int> &Map) {
	int Cur = Sum + Value[u];
	if (Cur>MaxSum) maximize(Map, Cur, abs(Cur-MinSum));
	if (Cur<MinSum) maximize(Map, Cur, abs(MaxSum-Cur));
	for (int i=0; int v=a[u][i]; i++) if (!d[v] && v!=p)
	discover(v, u, Cur, min(MinSum, Cur), max(MaxSum, Cur), Map);
}

int solve(int u) {
	int Best=0;
	map<int, int> Sum, Cur;
	Sum[Value[u]]=1;
	for (int i=0; int v=a[u][i]; i++) if (!d[v]) {
		Cur.clear(); discover(v, u, 0, 0, 0, Cur);
		for each(it, Cur) {
			if (Sum.count(-it->X))
			Best = max(Best, max(Sum[-it->X], it->Y));
		}
		
		int vu=Value[u];
		Cur.clear(); discover(v, u, vu, min(vu, 0), max(vu, 0), Cur);
		for each(it, Cur) maximize(Sum, it->X, it->Y);
	}
	return Best;
}

int bfs(int u){
	queue<int> qu;
	int Best = 0;
	qu.push(u=centroid(u)); d[u]=true;
	while (qu.size()) {
		int u=qu.front(); qu.pop();
		Best = max(Best, solve(u));
		for (int i=0; int v=a[u][i]; i++) if (d[v]==0) 
		{ qu.push(v=centroid(v)); d[v]=true; }
	}
	return Best;
}

main(){
	scanf("%d", &n);
	for (int i=2; i<=n; i++) {
		int x; scanf("%d", &x);
		a[i].push_back(x);
		a[x].push_back(i);
	}
	f1(i,n) a[i].push_back(0);
	
	for (int i=1; i<=n; i++) {
		int c; scanf(" %c", &c);
		Value[i] = (c=='(' ? 1 : -1);
	}
	cout << bfs(1) << endl;
}
