#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int m, n, xa, ya, xb, yb, xc, yc;
#define d(x, y) (abs(x-xb)+abs(y-yb))
int rx[]={-1,0,1,0}, ry[]={0,-1,0,1};
const int M = 1000000007, N = 102;

bool FF[N][N][N][2];
long F[N][N][N][2];
#define C xa][ya][xc][(xa^ya^xc^yc)&1

long f(int xa, int ya, int xc, int yc) {
	if (d(xa, ya)==0) return 1;
	if (xa==xc && ya==yc) return 0;
	if (FF[C]++) return F[C];
	
	long Sum = 0;
	for (int i=0; i<4; i++) {
		int xx=xa+rx[i], yy=ya+ry[i];
		if (d(xx, yy) < d(xa, ya))
		Sum += f(xc, yc, xx, yy);
	}
	return F[C] = Sum % M;
}

bool GG[N][N];
long G[N][N];

long g(int x, int y) {
	if (d(x, y)==d(xc, yc))
	return f(x, y, xc, yc);
	if (GG[x][y]++) return G[x][y];
	
	long Sum = 0;
	for (int i=0; i<4; i++) {
		int xx=x+rx[i], yy=y+ry[i];
		if (d(xx, yy) < d(x, y))
		Sum += g(xx, yy);
	}
	return G[x][y] = Sum % M;
}

long naive(int a, int b, int c, bool NotDouble) {
	if (a<b && b<c || c<b && b<a) return 1;
	return (NotDouble ? 1 : 2) * abs(abs(a-b)-abs(c-b));
}

main() {
	freopen("sqgame.inp", "r", stdin) && 
	freopen("sqgame.out", "w", stdout);
	cin >> m >> n;
	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> xc >> yc;
	if (xa==xb && xb==xc)
		cout << naive(ya, yb, yc, xa==1 || xa==m) << endl;
	else if (ya==yb && yb==yc)
		cout << naive(xa, xb, xc, ya==1 || ya==n) << endl;
	else {
		if (d(xa, ya) < d(xc, yc)) 
		{ swap(xa, xc); swap(ya, yc); }
		cout << g(xa, ya) << endl;
	}
}
