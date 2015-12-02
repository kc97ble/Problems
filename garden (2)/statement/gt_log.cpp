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
const int max_n = 1000010;
struct Point {
	double x, y;
	void init(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void print() {
		printf("%.1lf %.1lf\n", x, y);
	}
} p[max_n];
int main(int nargs, char* args[]) {
	if (nargs != 3 && nargs != 4) {
		printf("log s [seed]\nMaxSide = s << log, MinSize = s\n");
		return 0;
	}
	i64 smax;
	int h, seed;
	sscanf(args[1], "%d", &h);
	sscanf(args[2], lld, &smax);
	if (nargs == 4) {
		sscanf(args[3], "%d", &seed);
	} else {
		seed = Time();
	}
	initrand(seed);

	i64 dx = 0;
	smax <<= h;
	for (int i = 0; i < h; i++) {
		dx += smax >> (i + 1);
	}
	i64 n = dx + smax + dx;
	i64 A = smax, s = smax;
	int k = 0;
	p[k++].init(dx + smax * 0.5, dx + smax * 0.5);
	int m = 1;
	for (int iter = 0; iter < h; iter++) {
		s >>= 1;
		A += s + s;
		dx -= s;
		m += m + 2;
		m--;
		for (int i = 1; i <= m; i++) {
			p[k++].init(dx + s * i + s * 0.5, dx + s * 0.5);
			p[k++].init(dx + s * i - s * 0.5, dx + A - s * 0.5);
			p[k++].init(dx + A - s * 0.5, dx + s * i + s * 0.5);
			p[k++].init(dx + s * 0.5, dx + s * i - s * 0.5);
		}
		m++;
	}
	randomShuffle(p, p + k);
	cout << n << ' ' << n << ' ' << k << endl;
        fprintf(stderr, "Фрактальное двоичное разбиение, w=h=" lld ", n=%d", n, k);
	for (int i = 0; i < k; i++) {
		p[i].print();
	}
	return 0;
}
