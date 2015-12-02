#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<long, long> llll;
typedef pair<llll, llll> quad;
#define X first
#define Y second
const int N = 100005, oo = 0x3c3c3c3c;
int n, m, k, p;
int h[N], a[N];

inline long ceil(long a, long b)
	{ return a/b + !!(a%b); }
inline long g(long hu, int u) 
	{ return hu/a[u]+1; }

struct cmp {
	inline bool operator () (llll p, llll q)
	{ return g(p.X, p.Y) > g(q.X, q.Y); }
};

bool ok(long x) {
	#define push_quad(x, y, u, v) push(quad(llll(x, y), llll(u, v)))
	priority_queue<quad> qu;
	for (int i=1; i<=n; i++) 
	qu.push_quad(-g(x, i), 0, x, i);
	long Remain=0;
	
	for (int i=1; i<=m; i++) {
		if (Remain) 
			{ Remain += k; continue; }
		for (int j=1; j<=k; j++) {
			quad Top=qu.top();
			long hu=Top.Y.X, u=Top.Y.Y, gu=-Top.X.X;
			if (gu <= i) {
				return false;
			} else if (gu <= m) {
				qu.pop(); qu.push_quad(-g(hu+p, u), 0, hu+p, u);
			} else {
				Remain++;
			}
		}
	}
	while (qu.size()) {
		quad Top=qu.top(); qu.pop();
		long hu=Top.Y.X, u=Top.Y.Y, gu=-Top.X.X;
		hu = hu - 1LL*a[u]*m;
		if (hu<h[u])
		Remain -= ceil(h[u]-hu, p);
	}
	return Remain >= 0;
}

main() {
	freopen("bamboos.inp", "r", stdin);
	freopen("bamboos.out", "w", stdout);
	
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &h[i], &a[i]);

	long ll=0, rr=5001LL*oo, mm=(ll+rr)/2;
	while (ll!=rr) {
		if (ok(mm)) rr=mm; else ll=mm+1;
		mm=(ll+rr)/2;
	}
	cout << mm << endl;
}
