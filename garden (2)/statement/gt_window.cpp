#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include "random.h"

using namespace std;

typedef long long i64;

#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
struct Point {
	double x, y;
	void init(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void print() {
		printf("%.1lf %.1lf\n", x, y);
	}
};
int main(int nargs, char* args[]) {
	if (nargs != 3 && nargs != 4) {
		printf("m s [seed]\nN = (m + 1) * s, K = m * 4 + 1\n");
		return 0;
	}
	i64 s;
	int m, seed;
	sscanf(args[1], "%d", &m);
	sscanf(args[2], lld, &s);
	if (nargs == 4) {
		sscanf(args[3], "%d", &seed);
	} else {
		seed = Time();
	}
	i64 n = (m + 1) * s;
	int k = m * 4 + 1;
	vector<Point> p(k);
	p[0].init((m - 1) * s * 0.5 + s, (m - 1) * s * 0.5 + s);
	for (int i = 1; i <= m; i++) {
		p[i].init(s * i + s * 0.5, s * 0.5);
		p[i + m].init(s * i - s * 0.5, n - s * 0.5);
		p[i + m + m].init(n - s * 0.5, s * i + s * 0.5);
		p[i + m + m + m].init(s * 0.5, s * i - s * 0.5);
	}
	initrand(seed);
	randomShuffle(p.begin(), p.end());
	cout << n << ' ' << n << ' ' << k << endl;
        fprintf(stderr, "Один большой и много единичных квадратов, w=h=" lld ", n=%d", n, k);
	for (size_t i = 0; i < p.size(); i++) {
		p[i].print();
	}
	return 0;
}
