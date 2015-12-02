#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, a[N];

typedef pair<int*, int*> range_t;
#define X first
#define Y second

struct cmp {
	int u;
	cmp(int u) : u(u) 
		{ }
	bool operator () (int x, int y) 
		{ return ((1<<u)&x) < ((1<<u)&y); }
};

range_t access(range_t R, int u, int x) 
	{ return equal_range(R.X, R.Y, x<<u, cmp(u)); }

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	
	int m; scanf("%d", &m);
	while (m-->0) {
		int x; scanf("%d", &x);
		range_t R(a+1, a+n+1);
		for (int i=29; i>=0; i--) {
			range_t R1 = access(R, i, !((1<<i)&x));
			if (R1.X!=R1.Y) R=R1;
		}
		printf("%d\n", *R.X);
	}
}

