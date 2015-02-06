#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
typedef pair<int, ii> triple;
#define X first
#define Y second

#define N 1003
const int oo = 0x3c3c3c3c;
int n, m;
ii a[N];
triple b[N];

long F[2][N][N];
#define C Used][u][x

long f(int u, int x, bool Used, bool Solved=true) {
	if (x==n+1) return 0;
	if (u==m+1) return 1LL*oo*oo;
	if (Solved) return F[C];
	long Min = f(u+1, x, false);
	if (!Used) Min = min(Min, f(u, x, true) + b[u].Y.X);
	if (Used && a[x].X <= b[u].X) Min = min(Min, f(u, x+1, true) + 1LL*b[u].Y.Y*a[x].Y);
	return F[C] = Min;
}

main(){
	scanf("%d%d", &n, &m);
	f1(i,n) scanf("%d%d", &a[i].X, &a[i].Y);
	f1(i,m) scanf("%d%d%d", &b[i].X, &b[i].Y.X, &b[i].Y.Y);	
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	
	for (int i=m; i>=1; i--)
	for (int j=n; j>=1; j--)
	for (int k=1; k>=0; k--)
	f(i, j, k, false);
	
	cout << f(1, 1, false) << endl;	
}
