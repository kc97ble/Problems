#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=100005, oo=0x3c3c3c3c;
int n, k, a[N], Next[N];
long F[102][N];

struct box {
	int rr[N], n; long id[N];
	void update(int R, long X)
		{ rr[n]=R, id[n]=X; n++; }
	long min_range(int R) {
		long Min = +1LL*oo*oo;
		while (n && rr[n-1]<=R)
		{ Min=min(Min, id[n-1]); n--; }
		update(R, Min);
		return Min;
	}
} Box;

void solve() {
	for (int u=1, k=0; u<=n+1; u++) 
		F[k][u] = (u==n+1 && k==0 ? 0 : 1LL*oo*oo);
	for (int k=0, u=n+1; k<=::k; k++)
		F[k][u] = (u==n+1 && k==0 ? 0 : 1LL*oo*oo);
	for (int k=1; k<=::k; k++) {
		Box.n=0;
		for (int u=n; u>=1; u--) {
			F[k][u] = F[k][Next[u]];
			Box.update(u+1, F[k-1][u+1]);
			F[k][u] = min(F[k][u], Box.min_range(Next[u]) + a[u]);
		}
	}
}

main(){
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=n; i>=1; i--) {
		int j=i+1; while (j!=n+1 && a[j]<a[i]) j=Next[j];
		Next[i]=j; // a[j]>=a[i]
	}
	solve();
	cout << F[k][1] << endl;
}
