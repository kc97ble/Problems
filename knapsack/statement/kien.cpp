#include <bits/stdc++.h>
using namespace std;

const int N = 5003;
int n, M, a[N], b[N], F[N][N];

int f(int n, int M) {
	if (n==0) return 0;
	if (F[n][M]!=-1) return F[n][M];
	
	int Max = f(n-1, M);
	if (M>=a[n]) {
		int fx = f(n-1, M-a[n]) + b[n];
		Max = max(Max, fx);
	}
	return F[n][M] = Max;
}

main() {
	memset(F, -1, sizeof F);
	scanf("%d%d", &n, &M);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &a[i], &b[i]);
	
	cout << f(n, M) << endl;
}
