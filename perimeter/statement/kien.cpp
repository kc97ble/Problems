#include <stdio.h>
#include <math.h>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 100005;
int n; ii a[N];

double abs(ii a, ii b)
	{ return hypot(a.X-b.X, a.Y-b.Y); }
ii operator ~ (ii a)
	{ return ii(a.Y, a.X); }

main() {
	while (scanf("%d", &n) > 0) {
		if (n==0) return 0;
		for (int i=1; i<=n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = ii(x, y);
		}
		sort(a+1, a+n+1);
		
		set<ii> Set; int j=1;
		double Min=1.0/0.0;
		
		for (int i=1; i<=n; i++) {
			auto it = Set.emplace(~a[i]).first;
			while (a[i].X-a[j].X >= Min/2)
				Set.erase(~a[j++]);
			auto A=it; while (A!=Set.begin() && it->first - prev(A)->first <= Min/2) A--;
			auto B=it; while (B!=Set.end() && B->first - it->first <= Min/2) B++;
			for (auto I=A; next(I)!=B; I++)
			for (auto J=next(I); J!=B; J++)
			if (I!=it && J!=it)
			Min = min(Min, abs(*I,*it) + abs(*J,*it) + abs(*I,*J));
		}
		printf("%.3lf\n", Min);
	}
}

