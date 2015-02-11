#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 52
int n, a[N];

bool G1[N][N];
bool G2[N][N];

bool g(int ll, int rr) {
	if (rr==ll+1) return true;
	if (G1[ll][rr]++) return G2[ll][rr];
	if (__builtin_popcount(a[ll] & a[rr]) < 2) return false;
	bool Any = false;
	for (int i=ll+1; i<=rr-1; i++)
	Any |= g(ll, i) && g(i, rr);
	return G2[ll][rr] = Any;
}

bool F[N][N];
int FF[N][N];

int f(int ll, int rr) {
	if (rr==ll+1 || g(ll, rr)) return rr-ll-1;
	if (F[ll][rr]++) return FF[ll][rr];
	int Max = 0;
	for (int i=ll+1; i<=rr-1; i++)
	Max = max(Max, f(ll, i) + f(i, rr));
	return FF[ll][rr] = Max;
}

main(){
	scanf("%d", &n);
	f1(i,n) {
		char x, y, z;
		scanf(" %c%c%c", &x, &y, &z);
		a[i] = (1<<x-64) | (1<<y-64) | (1<<z-64);
	}
	cout << f(1, n) << endl;
}
