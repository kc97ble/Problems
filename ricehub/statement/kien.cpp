#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int n, m, a[N];
long s[N], L;

long h(int L, int R) {
	int M = (L+R)/2;
	long Sum1 = (s[R]-s[M-1]) - 1LL*a[M]*(R-M+1);
	long Sum2 = 1LL*a[M]*(M-L+1) - (s[M]-s[L-1]);
	return Sum1 + Sum2;
}

main() {
	cin >> n >> m >> L;
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		s[i] = s[i-1] + a[i];
	
	int R=1, Max=0;
	for (int i=1; i<=n; i++) {
		while (R+1<=n && h(i, R+1)<=L) R++;
		Max = max(Max, R-i+1);
	}
	cout << Max << endl;
}
