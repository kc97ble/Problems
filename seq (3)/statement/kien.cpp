#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 200005, oo = 0x3c3c3c3c;

struct worker {
	int T[20][N], K[N];
	long s[N];
	
	void init(int a[], int n) {
		for (int i=1; i<=n; i++)
			s[i] = s[i-1] + a[i];
		for (int i=1; i<=n; i++)
			T[0][i] = a[i];
		for (int k=1; k<=19; k++)
		for (int i=1; i<=n; i++) {
			T[k][i] = T[k-1][i];
			if (i+(1<<k-1)<=n)
			T[k][i] = max(T[k][i], T[k-1][i+(1<<k-1)]);
		}
		for (int i=2; i<=n; i++)
		K[i] = K[i/2]+1;
	}
	
	int max_range(int L, int R) {
		int k = K[R-L+1];
		return max(T[k][L], T[k][R-(1<<k)+1]);
	}
	
	long sum_range(int L, int R)
		{ return s[R] - s[L-1]; }
} W;

int n, k, a[N];

main() {
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	W.init(a, n);
	
	long Min = 1LL*oo*oo;
	for (int i=1; i+k-1<=n; i++)
	if (W.max_range(i, i+k-1) <= 1-i)
	Min = min(Min, 1LL*(1-i)*k - W.sum_range(i, i+k-1));
	
	if (Min == 1LL*oo*oo) Min=-1;
	cout << Min << endl;
}

