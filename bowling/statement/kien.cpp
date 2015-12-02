#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int oo = 0x3c3c3c3c, N=200005;
int n, r, a[N], t;
long s[N], F[2][2][N];
int FF[2][2][N];

long f(int u, bool Continue, bool nz) {
	if (u>n) return nz ? 0 : -1LL*oo*oo;
	#define THIS Continue][nz][u
	if (FF[THIS]!=t) FF[THIS]=t; else return F[THIS];
	long Max = f(u+1, false, nz);
	if (Continue) Max = max(Max, f(u+1, true, true)+a[u]);
	if (u+r<=n) Max = max(Max, f(u+2*r+1, true, true) + s[min(n, u+2*r)] - s[u-1]);
	return F[THIS] = Max;
}

main() {
	scanf("%d", &t);
	do {
		scanf("%d%d", &n, &r);
		for (int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			s[i] = s[i-1] + a[i];
		}
		for (int i=n; i>=1; i--) {
			f(i, 0, 0); f(i, 0, 1);
			f(i, 1, 0); f(i, 1, 1);
		}
		
		if (n <= r+1) {
			cout << s[n] << endl;
		} else {
			long Max1 = s[r+1] + f(r+2, true, true);
			long Max2 = f(1, false, false);
			cout << max(Max1, Max2) << endl;
		}
	} while (--t);
}
