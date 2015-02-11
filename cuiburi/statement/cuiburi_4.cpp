// Paul Baltescu
// Solutie O(N^2)

#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

const int MAXN = 2010;
const int MAXV = 30000;

int N, Sol;
int x[MAXN], y[MAXN], r[MAXN], p[MAXN];
int lx[MAXN], ly[MAXN], rx[MAXN], ry[MAXN];
char tip[MAXN];
int c[MAXN];

double getArea(int i) {
	if (tip[i] == '0')
		return (rx[i]-lx[i]) * (ry[i]-ly[i]);

	return r[i]*r[i]*M_PI;
}

int cmp(int i, int j) {
	return getArea(i) > getArea(j);
}

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int isInside(int i, int j) {
	if (tip[i] == '0' && tip[j] == '0')
		return lx[j] <= lx[i] && rx[i] <= rx[j] && ly[i] <= ly[j] && ry[j] <= ry[i];

	if (tip[i] == '1' && tip[j] == '1')
		return dist(x[i], y[i], x[j], y[j]) + r[i] <= r[j];

	if (tip[i] == '1' && tip[j] == '0')
		return lx[j] <= x[i]-r[i] && x[i]+r[i] <= rx[j] && ly[j] <= y[i]-r[i] && y[i]+r[i] <= ry[j];

	return dist(x[j], y[j], lx[i], ly[i]) <= r[j] && dist(x[j], y[j], lx[i], ry[i]) <= r[j] &&
		dist(x[j], y[j], rx[i], ry[i]) <= r[j] && dist(x[j], y[j], rx[i], ly[i]) <= r[j];
}

int main() {
	ifstream fin("cuiburi.in");
	ofstream fout("cuiburi.out");

	fin >> N;
	assert(1 <= N && N <= 2000);

	for (int i = 1; i <= N; ++i) {
		fin >> tip[i];
		assert('0' <= tip[i] && tip[i] <= '1');

		if (tip[i] == '0') {
			fin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
			assert(1 <= lx[i] && lx[i] <= rx[i] && rx[i] <= MAXV);
			assert(1 <= ly[i] && ly[i] <= ry[i] && ry[i] <= MAXV);
		} else {
			fin  >> x[i] >> y[i] >> r[i];
			assert(1 <= r[i] && r[i] <= MAXV);
			assert(1 <= x[i] && x[i] <= MAXV);
			assert(1 <= y[i] && y[i] <= MAXV);
		}
		p[i] = i;
	}

	sort(p+1, p+N+1, cmp);

	for (int i = 1; i <= N; ++i) {
		c[i] = 1;

		for (int j = 1; j < i; ++j)
			if (isInside(p[i], p[j]) && c[j]+1>c[i])
				c[i] = c[j]+1;
	}

	for (int i = 1; i <= N; ++i)
		Sol = max(Sol, c[i]);

	fout << Sol << endl;

	return 0;
}
