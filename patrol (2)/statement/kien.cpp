#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, k, P[N];
vector<int> a[N];

int F[N][3][2];
bool FF[N][3][2];
#define C v][k][U

int f(int u, int i, int k, bool U) {
	if (i==a[u].size()) return 0;
	int v = a[u][i];
	if (v==P[u]) return f(u, i+1, k, U);
	if (FF[C]++) return F[C];
	
	int Max = 0;
	if (U) {
		for (int j=0; j<=k; j++) {
			Max = max(Max, f(v, 0, j, true) + f(u, i+1, k-j, false) +1);
			Max = max(Max, f(v, 0, j, false) + f(u, i+1, k-j, true));
		}
	} else {
		for (int j=0; j<=k; j++) // not choose
		Max = max(Max, f(v, 0, j, false) + f(u, i+1, k-j, false));
		for (int j=0; j<=k-1; j++) // choose
		Max = max(Max, f(v, 0, j, true) + f(u, i+1, k-1-j, true) +1);
	}
	//printf("f(%d, %d, %d, %d, [v=%d]) = %d\n", u, i, k, U+0, v, Max);
	return F[C] = Max;
}

void visit (int u, int p) {
	P[u]=p;
	for (int v: a[u]) if (v!=p) {
		visit(v, u);
	}
}

main() {
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	visit(1, 0);
	cout << 2*(n-1) - f(1, 0, k, false) +k << endl;
}

