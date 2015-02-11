#include <stdio.h>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 752
typedef int intss[N][N];
int m, n, Seed, Threshold;
intss a, c1, c2, c3, c4, c13, c24;

int next_int()
	{ return Seed = (Seed * 25173 + 13849) & 65535; }

main(){
	scanf("%d%d", &m, &n);
	scanf("%d%d", &Seed, &Threshold);
	f1(i,m) f1(j,n) a[i][j] = (next_int()>=Threshold);

	for (int i=1; i<=m; i++) f1(j,n) {
		c1[i][j] = (a[i][j] ? 1 + c1[i-1][j-1] : 0);
		c2[i][j] = (a[i][j] ? 1 + c2[i-1][j+1] : 0);
	}
	for (int i=m; i>=1; i--) f1(j,n) {
		c3[i][j] = (a[i][j] ? 1 + c3[i+1][j-1] : 0);
		c4[i][j] = (a[i][j] ? 1 + c4[i+1][j+1] : 0);
	}
	f1(i,m) f1(j,n) c13[i][j] = min(c1[i][j], c3[i][j]);
	f1(i,m) f1(j,n) c24[i][j] = min(c2[i][j], c4[i][j]);

	int Max = 0;
	for (int i=1; i<=m; i++) {
		set<int> Set[2];
		for (int j=1; j<=n; j++) if (a[i][j]) {
			Set[j&1].insert(j);
			set<int> :: iterator it;
			it = Set[j&1].lower_bound(j-2*c13[i][j]+2);
			while ((*it)+2*c24[i][*it]-2 < j) {
				Set[j&1].erase(it);
				it = Set[j&1].lower_bound(j-2*c13[i][j]+2);
			}
			Max = max(Max, (j-(*it))/2+1);
		}
	}
	cout << Max << endl;
}
