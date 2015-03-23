#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
typedef pair<long, ii> triple;
#define X first
#define Y second

#define N 102
const int oo = 0x3c3c3c3c;
const long oooo = 1LL*oo*oo;

int n, m, c[N][N], F, Cost[N];
long d[N][N], Answer=oooo;

bool minimize(long &a, long b)
	{ if (a>b) a=b; else return false; return true; }
bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

void dijkstra(int p, int u, int Target){
	priority_queue<triple> qu;
	memset(d, 0x3c, sizeof d);
	qu.push(triple(0,ii(p,u))); d[p][u]=0;
	
	while (qu.size()){
		triple Top = qu.top(); qu.pop();
		long du=-Top.X; int p=Top.Y.X, u=Top.Y.Y;
		if (d[p][u] != du) continue;
		//printf("d[%d][%d]=%d\n", p, u, d[p][u]);
		if (u==Target) minimize(Answer, d[p][u]);
		
		if (p==u) {
			f1(v,n) if (c[u][v]<=F)
			if (minimize(d[u][v], d[p][u]))
			qu.push(triple(-d[u][v], ii(u,v)));
		} else {
			int Fuel=F-c[p][u];
			f1(v,n) {
				int Charge=c[u][v]-Fuel;
				if (Charge>=0 && Charge+Fuel<=F)
				if (minimize(d[0][v], d[p][u]+1LL*Charge*Cost[u]))
				qu.push(triple(-d[0][v], ii(0,v)));
			}
			if (minimize(d[u][u], d[p][u]+1LL*(F-Fuel)*Cost[u]))
			qu.push(triple(-d[u][u], ii(u,u)));
		}
	}
}

main(){
	scanf("%d%d", &n, &m);
	f1(i,n) scanf("%d", &Cost[i]);
	scanf("%d", &F);
	f1(i,n) f1(j,n) c[i][j]=oo;
	f1(i,n) c[i][i]=0, c[0][i]=F;
	f1(i,m) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z); x++, y++;
		if (minimize(c[x][y], z)) c[y][x]=z;
	}
	f1(k,n) f1(i,n) f1(j,n) minimize(c[i][j], c[i][k]+c[k][j]);
	dijkstra(0, 1, 2);
	if (Answer >= oooo) Answer=-1;
	cout << Answer << endl;
}
