#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
typedef pair<ii, int> line;
#define X first
#define Y second

bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

#define N 150
int m, n;
ii a[N], b[N];
line d[N][N];
int C[N][N][N];
bool CC[N][N][N];

ii operator ! (ii a)
	{ return ii(-a.Y, a.X); }
ii operator - (ii a, ii b)
	{ return ii(a.X-b.X, a.Y-b.Y); }
line xxfd(ii a, ii b)
	{ ii n=!(b-a); return line(n, n.X*a.X+n.Y*a.Y); }
int xdf(ii a, line d)
	{ return d.X.X*a.X+d.X.Y*a.Y-d.Y; }
int sign(int x)
	{ if (x==0) return 0; return x>0?1:-1; }
int sign(ii a, line d)
	{ return sign(xdf(a, d)); }

int c(int x, int y, int z){
	if (CC[x][y][z]++) return C[x][y][z];
	int Count = 0;
	f1(i,n) {
		int X = sign(b[i], d[x][y]);
		int Y = sign(b[i], d[y][z]);
		int Z = sign(b[i], d[z][x]);
		Count += (X==Y && Y==Z);
	}
	return C[x][y][z] = Count;
}

bool FF[N][N][N];
int F[N][N][N];

#define xyp x][y][p>0
int f(int x, int y, int p, bool Tracing=false){
	if (FF[xyp]++) return F[xyp];
	int Min=0;
	
	for (int k=y+1; k<=m; k++) {
		if (sign(a[k], d[x][y])!=p) {
			int w = +20-111*c(x,y,k);
			minimize(Min, f(y, k, sign(a[x], d[y][k]))+w);
			minimize(Min, f(x, k, sign(a[y], d[x][k]))+w);
		}
	}
	//printf("f(%d, %d) = %d\n", x, y, Min);
	return F[xyp] = Min;
}

main(){
	scanf("%d%d", &m, &n);
	f1(i,m) scanf("%d%d", &a[i].X, &a[i].Y);
	f1(i,n) scanf("%d%d", &b[i].X, &b[i].Y);
	sort(a+1, a+m+1);
	
	f1(i,m) f1(j,m) d[i][j]=xxfd(a[i], a[j]);
	
	int Min=0;
	f1(i,m) f1(j,m) if (i<j) {
		minimize(Min, f(i, j, -1)+20+20);
		minimize(Min, f(i, j, 1)+20+20);
	}

	cout << 111*n+Min << endl;
}
