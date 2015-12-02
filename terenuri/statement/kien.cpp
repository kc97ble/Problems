#include <stdio.h>
#include <math.h>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, double> lflf;
#define X first
#define Y second

double cross(lflf a, lflf b)
	{ return a.X*b.Y-a.Y*b.X; }
lflf operator - (lflf a, lflf b)
	{ return lflf(a.X-b.X, a.Y-b.Y); }
double abs(double a, double b)
	{ return a>b ? a-b : b-a; }

struct worker {
	set<lflf> Set;
	bool ok(lflf a, lflf b, lflf c) 
		{ return cross(b-a, c-a) <= 0.0; }
	void insert(double x, double y) {
		auto it = Set.emplace(x, y).first;
		
		if (it!=Set.begin() && next(it)!=Set.end())
			if (!ok(*prev(it), *it, *next(it)))
			{ Set.erase(it); return; }
		while (it!=Set.begin() && prev(it)!=Set.begin())
			if (!ok(*prev(prev(it)), *prev(it), *it))
			Set.erase(prev(it));
			else break;
		while (next(it)!=Set.end() && next(next(it))!=Set.end())
			if (!ok(*it, *next(it), *next(next(it))))
			Set.erase(next(it));
			else break;
		
		if (Set.size()>=2) {
			auto it1=Set.begin(), it2=next(it1);
			if (abs(it1->X, it2->X) <= 1e-9)
			Set.erase(it1->Y < it2->Y ? it1 : it2);
		}
		
		if (Set.size()>=2) {
			auto it1=Set.begin(), it2=next(it1);
			if (abs(it1->X, it2->X) <= 1e-9)
			Set.erase(it1->Y < it2->Y ? it1 : it2);
		}
	}
	
	void show(const char * s) {
		for (lflf u: Set)
		printf("%g:%g, ", u.X, u.Y);
		cout << s << endl;
	}
} W1, W2;

struct worker_3 {
	double x1=23e9, x2=-23e9;
	int c1=0, c2=0;
	
	void insert(double x) {
		if (x<x1) { x1=x; c1=0; }
		if (abs(x, x1)<=1e-9) c1++;
		if (x>x2) { x2=x; c2=0; }
		if (abs(x, x2)<=1e-9) c2++;
	}
} W3;

int n, m;

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n+m; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		W1.insert(x, y);
		W2.insert(x, -y);
		W3.insert(x);
		
		if (i>=n) {
			if (abs(W3.x1, W3.x2)<=1e-9) printf("%d\n", W3.c1);
			else printf("%d\n", W3.c1 + W3.c2
			+ ((int)W1.Set.size()-2) + ((int)W2.Set.size()-2));
		}
		
		/*cout << W1.Set.size() << " " << W2.Set.size() << endl;
		W1.show("W1");
		W2.show("W2");*/
	}
}

