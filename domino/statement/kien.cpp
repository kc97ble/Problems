#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int m, n, t, M;
bool b[123][123];

long F[16][16][1<<16];
bool FF[16][16][1<<16];
#define ff x-1][y-1][Used^Using

long f(int x, int y, int Used, int Using) {
	if (x==m+1) return 1;
	if (y==n+1) return f(x+1, 1, Using , 0);
	if (FF[ff]++) return F[ff];
	long Sum = f(x, y+1, Used | (1<<y-1), Using);
	if (y==1 || ((1<<y-2) & (~Using)))
	if (!b[x][y] && ((1<<y-1) & (~Used)))
	Sum += f(x, y+1, Used | (1<<y-1), Using | (1<<y-1));
	return F[ff] = Sum % M;
}

long G[20][2][256][256];
bool GG[20][2][256][256];
#define gg Depth][n&1][A][B

long g(int n, int A, int B, int Depth) {
	if (n==0) return A==B;
	if (n==1) return (A&B)==0;
	if (GG[gg]++) return G[gg];
	int L=(n/2), R=(n-L);
	long Sum = 0;
	for (int i=0; i<(1<<m); i++)
	if ((i&(i*2))==0)
	Sum += g(L, A, i, Depth+1) * g(R, i, B, Depth+1) % M;
	//printf("g(%d, %d, %d) = %lld\n", n, A, B, Sum);
	return G[gg] = Sum % M;
}

main() {
	scanf("%d", &M);
	
	scanf("%d%d%d", &m, &n, &t);
	for (int i=1; i<=t; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		b[x][y] = true;
	}
	cout << f(1, 1, 0, 0)%M << endl;
	
	long Sum = 0LL;
	scanf("%d%d", &m, &n);
	for (int i=0; i<(1<<m); i++)
	if ((i&(i*2))==0)
	Sum += g(n, 0, i, 0);
	cout << Sum%M << endl;
}
