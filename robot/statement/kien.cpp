#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> quad;
#define X first
#define Y second

const int N = 202;
int n, m, t, Color[N];
vector<int> a[3][N]; //
int d[3][4][N][N], c[3][4][N][N]; //
#define of(u) u.X.X][u.X.Y][u.Y.X][u.Y.Y
#define quad_of(x, y, z, t) quad(ii(x, y), ii(z, t))

int bfs(int r, int b, int x, int y) {
	queue<quad> qu;
	qu.push(quad_of(r, b, x, y));
	d[r][b][x][y]=0; c[r][b][x][y]=t;

	while (qu.size()) {
		quad u=qu.front(); qu.pop();
		int r=u.X.X, b=u.X.Y, x=u.Y.X, y=u.Y.Y;
		//printf("d(%d, %d, %d, %d) = %d\n", r, b, x, y, d(u));
		if (b==3) {
			if (x==y)
				return d[of(u)]/2;
			int k = (Color[y]-r+3)%3;
			for (int i=0; int z=a[k][x][i]; i++) {
				quad v = quad_of(r, Color[x], z, y);
				if (c[of(v)]!=t)
				{ qu.push(v); d[of(v)]=d[of(u)]+1; c[of(v)]=t; }
			}
		} else {
			int k = (b-r+3)%3;
			for (int i=0; int z=a[k][y][i]; i++) {
				quad v = quad_of((r+1)%3, 3, x, z);
				if (c[of(v)]!=t)
				{ qu.push(v); d[of(v)]=d[of(u)]+1; c[of(v)]=t; }
			}
		}
	}
	return -1;
}

main(){
	int T; cin >> T;
	for (t=1; t<=T; t++) {
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
			{ scanf("%d", &Color[i]); Color[i]--; }
		for (int i=1; i<=m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[z-1][x].push_back(y);
		}
		for (int k=0; k<3; k++)
			for (int i=1; i<=n; i++)
			a[k][i].push_back(0);
		cout << bfs(0, 3, 1, 2) << endl;
		for (int k=0; k<3; k++)
			for (int i=1; i<=n; i++)
			a[k][i].clear();
	}
}

