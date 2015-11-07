#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int oo = 0x3c3c3c3c, N = 2003;
int W, n, a[N], s[N];
int F[N][N];

void solve1(int i) {
	int R=n, Min=oo;
	for (int L=1; L<=i; L++)
	if (s[i]-s[L-1]>W) F[L][i]=oo;
	else {
		while (R>i && s[R]-s[i] >= s[i]-s[L-1])
		{ Min=min(Min, F[i+1][R] + (s[R]-s[i])); R--; }
		F[L][i] = Min - (s[i]-s[L-1]);
	}
}

void solve2(int i) {
	int R=i+1, Min=oo;
	for (int L=i; L>=1; L--)
	if (s[i]-s[L-1]>W) F[L][i]=oo;
	else {
		while (R<=n && s[R]-s[i] <= s[i]-s[L-1])
		{ Min=min(Min, F[i+1][R] - (s[R]-s[i])); R++; }
		F[L][i] = min(F[L][i], Min + (s[i]-s[L-1]));
	}
}

bool FF[N][N];

int f(int L, int R) {
	if (s[R]-s[L-1]>W) return oo;
	if (R==n) return 0;

	if (FF[L][R]++) return F[L][R];
	int Min = oo;
	for (int i=R+1; i<=n; i++)
	if (s[i]-s[R] <= W)
	Min = min(Min, abs((s[i]-s[R])-(s[R]-s[L-1])) + f(R+1, i));

	return F[L][R] = Min;
}

int naive() {
	int Min = oo;
	for (int i=1; i<=n; i++)
	Min = min(Min, f(1, i));
	return Min;
}

main() {
//	freopen("ests.inp", "r", stdin);
//	freopen("ests.out", "w", stdout);

	scanf("%d%d", &W, &n); W++;
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]); a[i]++;
		//printf("%d ", a[i]=rand()%(W-1)+1); a[i]++;
	}
	for (int i=1; i<=n; i++)
	s[i] = s[i-1] + a[i];

	//for (int i=1; i<=n; i++) printf("%d ", a[i]); printf("a\n");
	//for (int i=1; i<=n; i++) printf("%d ", s[i]); printf("s\n");

	for (int i=n; i>=1; i--) {
		if (i==n) {
			for (int L=1; L<=i; L++)
			F[L][i] = (s[i]-s[L-1] <= W ? 0 : oo);
		} else {
			solve1(i);
			solve2(i);
		}
		/*for (int j=1; j<=n; j++)
		printf(F[j][i]==oo ? "X " : "%d ", F[j][i]);
		printf("F[][%d]\n", i);*/
	}
	int Min = oo;
	for (int i=1; i<=n; i++)
	Min = min(Min, F[1][i]);
	cout << Min << endl;
	//cerr << naive() << endl;
}
