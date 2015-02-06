#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
#define X first
#define Y second

#define N 2502
const int oo = 0x3c3c3c3c;
int n; ii a[N];
int D1[2][N][N]; //
int D2[2][N][N]; //
#define C n&1][X][Y

struct int4 {
	int n, X, Y, Z;
	int4(int n, int X, int Y, int Z) :
		n(n), X(X), Y(Y), Z(Z) {}
	inline int h()
		{ return max(X, max(Y, Z)) * d(); }
	inline bool invalidated(){
               if (X>Y) swap(X, Y);
               if (Y>Z) swap(Y, Z);
               if (X>Y) swap(X, Y);
               if (D1[C]!=n) D2[C]=oo, D1[C]=n;
               else return false; return true;
        }
	inline int &d()
		{ return D2[C]; }
};

int4 operator + (const int4 &a, const int4 &b)
	{ return int4(a.n+b.n, a.X+b.X, a.Y+b.Y, a.Z+b.Z); }
inline bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

int bfs(int4 u) {
	queue<int4> qu;
	qu.push(u); u.d()=0;
	int Min = oo;

	while (qu.size()) {
		int4 u=qu.front(); qu.pop();
		//printf("(%d, %d, %d, %d) = %d [%d]\n", u.n, u.X, u.Y, u.Z, u.d(), u.h());
		if (u.n==n) {
			if (u.X && u.Y && u.Z)
			Min = min(Min, u.h());
		} else {
			int4 v(0, 0, 0, 0); int w;

			v = u+int4(1, a[u.n+1].Y, 0, 0);
			w = (u.X==0 ? a[u.n+1].X : 0);
			if (v.invalidated()) qu.push(v);
		        v.d() = min(v.d(), u.d() + w);

			v = u+int4(1, 0, a[u.n+1].Y, 0);
			w = (u.Y==0 ? a[u.n+1].X : 0);
			if (v.invalidated()) qu.push(v);
			v.d() = min(v.d(), u.d() + w);

			v = u+int4(1, 0, 0, a[u.n+1].Y);
			w = (u.Z==0 ? a[u.n+1].X : 0);
			if (v.invalidated()) qu.push(v);
			v.d() = min(v.d(), u.d() + w);
		}
	}
	return Min;
}

main(){
	int T; cin >> T;
	while (T-->0) {
		scanf("%d", &n);
		f1(i,n) scanf("%d%d", &a[i].X, &a[i].Y);
		sort(a+1, a+n+1);
		reverse(a+1, a+n+1);

		cout << bfs(int4(0, 0, 0, 0)) << endl;
		memset(D1, 0, sizeof D1);
		memset(D2, 0, sizeof D2);
	}
}
