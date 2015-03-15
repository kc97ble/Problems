#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005, M = 1000000009;
int n, a[N], s[N], F[N];

struct fenwick_tree {
	int T[N];
	void update(int u, int k, const vector<int> &Key) {
		u = lower_bound(Key.begin(), Key.end(), u) - Key.begin() + 1;
		for (int i=u; i<N; i+=i&-i) T[i]=(T[i]+k)%M;
	}
	int get(int u, const vector<int> &Key) {
		u = lower_bound(Key.begin(), Key.end(), u) - Key.begin() + 1;
		long Sum=T[u]; while (u-=u&-u) Sum+=T[u]; return Sum%M;
	}
} tr;

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		s[i] = s[i-1] + a[i];
	vector<int> Key(s, s+n+1);
	sort(Key.begin(), Key.end());
	
	F[0] = 1;
	tr.update(s[0], F[0], Key);
	for (int i=1; i<=n; i++) {
		F[i] = tr.get(s[i], Key);
		tr.update(s[i], F[i], Key);
		//printf("F[%d] = %d\n", i, F[i]);
	}
	cout << F[n] << endl;
}
