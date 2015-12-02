#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 200005, oo = 0x3c3c3c3c;
int n, a[N];
long b[N];

long F[3][2][N];
bool FF[3][2][N];
#define C Done][Cont][u

long f(int u, int Done, bool Cont) {
	if (u==n+1) return Done==2 ? 0 : -1LL*oo*oo;
	if (FF[C]++) return F[C];
	long Max = f(u+1, Done, false);
	if (Cont && u+2<=n) Max = max(Max, f(u+3, Done, true) + b[u]);
	if (u+2<=n && Done<=1) Max = max(Max, f(u+3, Done+1, true) + b[u]);
	return F[C] = Max;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		b[i] = 0LL+a[i]+a[i+1]+a[i+2];
	for (int i=n; i>=1; i--)
	for (int k=0; k<=5; k++)
		f(i, k/2, k%2);
	cout << f(1, 0, 0) << endl;
}

