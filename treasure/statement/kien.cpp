#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define for_each(it, a) for (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 2003;
int n, b[N][N], c[N][N];
int MaxD=0, d[N];
vector<ii> List;

bool ok(int x, int y) {
	MaxD++;
	for_each(it, List) {
		int L = abs(x-it->X) + abs(y-it->Y);
		if (d[L]==MaxD) return true;
		else d[L]=MaxD;
	}
	return false;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) {
		scanf("%d", &b[i][j]);
		if (b[i][j]) List.push_back(ii(i, j));
	}
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) {
		if (List.size() >= max(i-1, n-i) + max(j-1, n-j) + 2)
			c[i][j] = 1;
		else {
			c[i][j] = ok(i, j);
		}
	}
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	printf(j==n ? "%d\n" : "%d ", c[i][j]);
}
