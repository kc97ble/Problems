#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=52, N4=6250006;
int m, n, d[N][N][N][N];
char a[N][N];
const int rx[] = {-1,0,1,0};
const int ry[] = {0,-1,0,1};

struct mega_queue {
	int S, T, a[N4], b[N4], c[N4], d[N4];
	void push(int x, int y, int u, int v)
	{ a[T]=x, b[T]=y, c[T]=u, d[T]=v; T++; }
	void pop(int &x, int &y, int &u, int &v)
	{ x=a[S], y=b[S], u=c[S], v=d[S]; S++; }
} qu;

int bfs(int x, int y, int u, int v) {
	qu.S=qu.T=0;
	d[x][y][u][v]=1; qu.push(x, y, u, v);
	int tu=x, tv=y;
	
	while (qu.S != qu.T) {
		int x, y, u, v; qu.pop(x, y, u, v);
		//printf("d[%d][%d][%d][%d] = %d\n", x, y, u, v, d[x][y][u][v]);
		if (u==tu && v==tv) return d[x][y][u][v]-1;
		
		for (int i=0; i<4; i++) {
			int xx=x+rx[i], yy=y+ry[i], uu=u, vv=v;
			if (a[xx][yy]==0 || a[xx][yy]=='#') continue;
			if (xx==u && yy==v) uu=x, vv=y;
			if (d[xx][yy][uu][vv]==0) {
				d[xx][yy][uu][vv] = d[x][y][u][v] + 1;
				qu.push(xx, yy, uu, vv);
			}
		}
	}
	return -1;
}

main() {
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
	scanf("%s", a[i]+1);
	
	int x[128], y[128];
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		{ x[a[i][j]]=i, y[a[i][j]]=j; }
	
	int z = bfs(x['.'], y['.'], x['X'], y['X']);
	if (z==-1) cout << "Impossible" << endl;
	else cout << z << endl;
}
