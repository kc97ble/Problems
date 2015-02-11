#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 2003
bool b[N][N];
int n, F[N];

struct shape {
	char Type; // 'R' | 'C'
	int x, y, u, v, r;
	void rect(int X, int Y, int U, int V)
		{ Type='R'; x=X, y=Y, u=U, v=V; }
	void circle(int X, int Y, int R)
		{ Type='C'; x=X, y=Y, r=R; }
} Shape[N];

double dist(int x, int y, int u, int v) 
	{ return hypot(x-u, y-v); }
bool in_circle(int x, int y, const shape &b) 
	{ return dist(x, y, b.x, b.y) <= b.r+1e-9; }

bool operator <= (const shape &a, const shape &b) {
	if (a.Type=='R' && b.Type=='R') {
		return b.x<=a.x && a.u<=b.u
			&& b.y<=a.y && a.v<=b.v;
	} else if (a.Type=='R' && b.Type=='C') {
		return in_circle(a.x, a.y, b)
			&& in_circle(a.x, a.v, b)
			&& in_circle(a.u, a.y, b)
			&& in_circle(a.u, a.v, b);
	} else if (a.Type=='C' && b.Type=='R') {
		return b.x <= a.x-a.r && a.x+a.r <= b.u
			&& b.y <= a.y-a.r && a.y+a.r <= b.v;
	} else {
		return dist(a.x, a.y, b.x, b.y)+a.r <= b.r+1e-9;
	}
}

int f(int u) {
	if (F[u]) return F[u];
	int Max = 1;
	for (int i=1; i<=n; i++)
	if (b[i][u]) Max = max(Max, f(i)+1);
	return F[u] = Max;
}

main(){
	scanf("%d", &n);
	f1(i,n) {
		int c, x, y; scanf("%d%d%d", &c, &x, &y);
		int u, v; scanf(c==0 ? "%d%d" : "%d", &u, &v);
		if (c==0) Shape[i].rect(x, y, u, v);
		else Shape[i].circle(x, y, u);
	}
	f1(i,n) f1(j,n) b[i][j] = (i!=j && Shape[i] <= Shape[j]);
	f1(i,n) f1(j,n) if (b[i][j] && b[j][i]) b[i][j]=false;
	int Max = 0;
	f1(i,n) Max = max(Max, f(i));
	cout << Max << endl;
}
