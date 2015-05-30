#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

const int N = 1003, oo = 0x3c3c3c3c, M = 1000006;
int m, n, Base;
char P[N][123], Q[N][123];
vector<ii> a[M]; //
int Peak, Source, Target, d[M]; //
int F[2][N][123][10]; //

void f(int p, int pp, int q, int qq, int Mod, int u, int w) {
	if (P[p][pp]==0 && Q[q][qq]==0 && Mod==0) 
	return a[u].push_back(ii(Target, w)); // return 0
	
	if (P[p][pp]!=0 && Q[q][qq]!=0) {
		if (P[p][pp]!=Q[q][qq] || P[p][pp]-'0'>Base) return ; //return oo;
		return f(p, pp+1, q, qq+1, (Mod+(P[p][pp]-'0'))%Base, u, w+1);
	}
	
	int &v = (P[p][pp]==0 ? F[0][q][qq][Mod] : F[1][p][pp][Mod]);
	if (v==0) { v=++Peak; if (v>=M) cout << "!!!" << endl; } 
	else return a[u].push_back(ii(v, w));
	
	if (P[p][pp]==0) {
		for (int i=1; i<=m; i++)
		f(i, 0, q, qq, Mod, v, 0);
	} else {
		for (int i=1; i<=n; i++)
		f(p, pp, i, 0, Mod, v, 0);
	}
	//printf("f(%d, %d, %d, %d, %d) = %d\n", p, pp, q, qq, Mod, Min);
	return a[u].push_back(ii(v, w));
}

int dijkstra(int S, int T) {
	priority_queue<ii> qu;
	memset(d, 0x3c, sizeof d);
	qu.push(ii(0, S)); d[S]=0;
	
	while (qu.size()) {
		ii w=qu.top(); qu.pop();
		int u=w.second, du=-w.first;
		if (d[u]!=du) continue;
		if (u==T) return d[u];
		
		for (int i=0; i<a[u].size(); i++) {
			int v=a[u][i].first, w=a[u][i].second;
			if (d[v] > d[u]+w) {
				d[v] = d[u]+w;
				qu.push(ii(-d[v], v));
			}
		}
	}
	return oo;
}

main() {
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
	scanf("%s", P[i]);
	for (int i=1; i<=n; i++)
	scanf("%s", Q[i]);
	
	int Min = oo;
	for (int k=2; k<=10; k++) {
		Source=1, Target=2, Peak=2;
		memset(F, 0, sizeof F);
		
		Base = k-1;
		for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		f(i, 0, j, 0, 0, Source, 0);
		
		Min = min(Min, dijkstra(Source, Target));
		for (int i=1; i<=Peak; i++)
		a[i].clear();
	}
	if (Min==oo) Min=-1;
	cout << Min << endl;
}

