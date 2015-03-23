#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long
const int N=1003, M=1000000007;

int m, n;
char a[N][N];
long H[N];

bool distinct(long a[], int n) {
	vector<long> T(a+1, a+n+1);
	sort(T.begin(), T.end());
	for (int i=1; i<T.size(); i++)
	if (T[i]==T[i-1]) return false;
	return true;
}

main() {
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
	scanf("%s", a[i]+1);
	
	for (int i=m; i>=1; i--) {
		for (int j=1; j<=n; j++)
		H[j] = H[j]*M+a[i][j];
		if (distinct(H, n))
		{ cout << i-1 << endl; return 0; }
	}
}
