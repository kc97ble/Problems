#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 802;
int rx[]={-1,0,1,0};
int ry[]={0,-1,0,1};

int n, Speed;
char a[N][N];
int h[N][N], d[N][N];

void bfs1() {
	queue<ii> qu;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (a[i][j]=='H') {
		h[i][j]=0;
		qu.push(ii(i, j));
	} else {
		h[i][j]=-1;
	}
	
	while (qu.size()) {
		ii o=qu.front(); qu.pop();
		int x=o.first, y=o.second;
		
		for (int i=0; i<4; i++) {
			int xx=x+rx[i], yy=y+ry[i];
			if (a[xx][yy]=='H' || a[xx][yy]=='G' || a[xx][yy]=='M')
			if (h[xx][yy]==-1) {
				h[xx][yy]=h[x][y]+1;
				qu.push(ii(xx, yy));
			}
		}
	}
}

int bfs2(int Stand) {
	queue<ii> qu;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (a[i][j]=='M' && Stand<h[i][j]) {
		d[i][j]=0;
		qu.push(ii(i, j));
	} else {
		d[i][j]=-1;
	}
	
	while (qu.size()) {
		ii o=qu.front(); qu.pop();
		int x=o.first, y=o.second;
		//printf("d[%d][%d] = %d\n", x, y, d[x][y]);
		if (a[x][y]=='D') return d[x][y];
		
		for (int i=0; i<4; i++) {
			int xx=x+rx[i], yy=y+ry[i];
			if (a[xx][yy]=='M' || a[xx][yy]=='G' || a[xx][yy]=='D')
			if (d[xx][yy]==-1)
			if (h[xx][yy]==-1 || d[x][y]+1 < (h[xx][yy]-Stand)*Speed) {
				d[xx][yy]=d[x][y]+1;
				qu.push(ii(xx, yy));
			}
		}
	}
	return -1;
}

main() {
	scanf("%d%d", &n, &Speed);
	for (int i=1; i<=n; i++)
	scanf("%s", a[i]+1);
	bfs1();
	/*for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
		printf(h[i][j]==-1 ? "-" : "%d", h[i][j]);
		printf("h[%d]\n", i);
	}*/
	if (bfs2(0)==-1)
		cout << -1 << endl;
	else {
		int ll=0, rr=1000000, mm=(ll+rr)/2;
		while (ll<rr) {
			if (bfs2(mm)!=-1) ll=mm; else rr=mm-1;
			mm=(ll+rr+1)/2;
		}
		cout << mm << endl;
	}
	
}

