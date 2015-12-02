#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<long, long> llll;
typedef pair<llll, llll> sc;
#define X first
#define Y second

const int N = 1000006, M = 1000000000;
int n, a[N];
sc F[6][N], G[6][N];

llll operator + (llll a, llll b) {
	llll c (a.X+b.X, a.Y+b.Y);
	c.X+=c.Y/M; c.Y%=M;
	return c;
}

sc max_vivi(sc a, sc b) {
	if (a.X==b.X) return sc(a.X, a.Y+b.Y);
	return a.X<b.X ? b : a;
}

ostream& operator << (ostream& cout, const llll &a) {
	if (a.X==0) return cout << a.Y;
	char s[10]; sprintf(s, "%09d", (int)a.Y);
	return cout << a.X << s;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	for (int k=0; k<=5; k++)
	for (int i=0; i<=n; i++) 
	if (k==0) 
		G[k][i] = sc(llll(0, 0), llll(0, 1));
	else if (i==0)
		G[k][i] = F[k][i] = sc(llll(-0x3c3c3c3c, -0x3c3c3c3c), llll(0, 0));
	else {
		F[k][i] = sc(
			G[k-1][i-1].X + llll(0, k&1 ? a[i] : -a[i]), 
			G[k-1][i-1].Y);
		G[k][i] = max_vivi(G[k][i-1], F[k][i]);
//		printf("f(%d, %d) = %lld, g = %lld\n", k, i, F[k][i], G[k][i]);
	}
	cout << G[5][n].X << " " << G[5][n].Y << endl;
}

