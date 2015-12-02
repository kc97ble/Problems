#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include "random.h"

using namespace std;

typedef long long i64;

const int max_n = 1000010, max_s = 1010;
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
bool a[max_s][max_s];
struct Cell {
	int i, j;
	void init(int i, int j) {
		this->i = i;
		this->j = j;
	}
} cells[max_s * max_s];
int main(int nargs, char* args[]) {
	if (nargs != 3 && nargs != 4) {
		printf("n maxSide [seed]\n");
		return 0;
	}
	int n, smax, seed;
	sscanf(args[1], "%d", &n);
	sscanf(args[2], "%d", &smax);
	if (nargs == 4) {
		sscanf(args[3], "%d", &seed);
	} else {
		seed = Time();
	}
	initrand(seed);
	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cells[m++].init(i, j);
		}
	}
	randomShuffle(cells, cells + m);
	int k = 0;
	for (int z = 0; z < m; z++) {
		int i = cells[z].i, j = cells[z].j;
		if (a[i][j]) continue;
		int s = 1;
		for (; s < smax; s++) {
			bool g = 1;
			for (int k = 0; k <= s; k++) {
				if (i + s >= n || j + s >= n || a[i + s][j + k] || a[i + k][j + s]) {
					g = 0;
					break;
				}
			}
			if (!g) break;
		}
		for (int di = 0; di < s; di++) {
			for (int dj = 0; dj < s; dj++) {
				a[i + di][j + dj] = 1;
			}
		}
		p[k++].init(i + s * 0.5, j + s * 0.5);
	}
	randomShuffle(p, p + k);
	cout << n << ' ' << n << ' ' << k << endl;
        fprintf(stderr, "Случайное разбиение первого вида, w=h=%.0lf, n=%d", (double)n, k);
	for (int i = 0; i < k; i++) {
		p[i].print();
	}
	return 0;
}
