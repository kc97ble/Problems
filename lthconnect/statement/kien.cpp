#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 152;
int n, m, Count[N];

struct djs {
	int P[N];
	djs()
		{ for (int i=0; i<N; i++) P[i]=i; }
	void join(int x, int y)
		{ P[at(x)]=at(y); }
	int at(int x)
		{ return x==P[x] ? x : P[x]=at(P[x]); }
} Label;

char F[N][N][2];
#define C n0][n1][k

bool f(int n, int n0, int n1, bool k) {
	if (n==1) return false;
	if (F[C]!=-1) return F[C];
	bool Win = false;
	#define try Win = Win | !
	if (k) try f(n, n0, n1, !k);
	if (n0>=2) try f(n-1, n0-1, n1, !k);
	if (n0 && n1) try f(n-1, n0-1, n1, !k);
	if (n1>=2) try f(n-1, n0+1, n1-2, !!k);
	return F[C]=Win;
}

main() {
	memset(F, -1, sizeof F);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Label.join(x, y);
	}
	for (int i=1; i<=n; i++)
		Count[Label.at(i)]++;
	
	int n0=0, n1=0; 
	long long k=-m;	
	for (int i=1; i<=n; i++) 
	if (int x=Count[i]) {
		//printf("Count[%d] = %d\n", i, x);
		x&1 ? n1++ : n0++;
		k+=(1LL*x*(x-1)/2);
	}
	//printf("n0=%d, n1=%d, k=%lld\n", n0, n1, k);
	puts(f(n0+n1, n0, n1, k&1) ? "Dung" : "Minh");
}

