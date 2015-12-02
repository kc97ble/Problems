#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include "random.h"

using namespace std;

typedef long long i64;

const int max_n = 1000010, max_s = 5010;
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
	if (nargs != 2 && nargs != 3) {
		printf("m [seed]\n");
		printf("N = m^2+m+1, K = 4m + 2\n");
		return 0;
	}
	int m, seed;
	sscanf(args[1], "%d", &m);
	if (nargs == 4) {
		sscanf(args[3], "%d", &seed);
	} else {
		seed = Time();
	}
	initrand(seed);
	int k = 0;
	i64 s = i64(m) * m + 1;
	p[k++].init(m * 0.5, m * 0.5);
	p[k++].init(m + s * 0.5, m + s * 0.5);
	for (i64 i = 0; i < m; i++) {
		p[k++].init(m + 0.5, 0.5 + i);
		//p[k++].init(m + s - 0.5, 0.5 + i);
		p[k++].init(0.5 + i, m + 0.5);
		//p[k++].init(0.5 + i, m + s - 0.5);
		p[k++].init((i + 1) * m + 1 + 0.5 * m, 0.5 * m);
		p[k++].init(0.5 * m, (i + 1) * m + 1 + 0.5 * m);
	}
	i64 n = m + s;
	cout << n << ' ' << n << ' ' << k << endl;
        fprintf(stderr, "Шаблон против квадратичного решения, w=h=%.0lf, n=%d", (double)n, k);
	randomShuffle(p, p + k);
	for (int i = 0; i < k; i++) {
		p[i].print();
	}
	return 0;
}
