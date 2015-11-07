#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 702;
int n, a[N];
long F[N][N];
bool FF[N][N];

int f(int ll, int rr) {
	if (FF[ll][rr]++) return F[ll][rr];
	int Max = 0;
	for (int i=ll+1; i<=rr-1; i++)
	Max = max(Max, f(ll, i) + f(i, rr) + a[i]*(a[ll]+a[rr]));
	return F[ll][rr] = Max;
}

main() {
//	freopen("game.inp", "r", stdin);
//	freopen("game.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	cout << f(1, n) << endl;
}
