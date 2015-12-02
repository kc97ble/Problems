// Robert Hasna
#include <cstdio>
#define Nmax 300000
#define eps 0.00000000001L

using namespace std;

inline long double abs(long double x) { return x < 0 ? -x : x; }

struct Punct {
	long double x, y;
	Punct() : x(0), y(0) {  }
	Punct(long double vx, long double vy) : x(vx), y(vy) {  }
	bool operator<(const Punct &p) { return (x < p.x) || (abs(x - p.x) < eps && y < p.y); }
} pct[Nmax];

int sus[Nmax], jos[Nmax], vfS, vfJ;

inline bool colin(Punct &p1, Punct &p2, Punct &p3) {
	return abs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y)) < eps;
}

inline bool stanga(Punct &p1, Punct &p2, Punct &p3) {
	if (colin(p1,p2,p3)) return true;
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y) > 0;
}

inline bool dreapta(Punct &p1, Punct &p2, Punct &p3) {
	if (colin(p1,p2,p3)) return true;
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y) < 0;
}

int N, M;

void qsort(int st, int dr) {
	int i = st, j = dr;
	Punct mij = pct[(st + dr) >> 1];

	while (st < dr) {
		while (pct[st] < mij) ++st;
		while (mij < pct[dr]) --dr;
		if (st <= dr) {
			Punct temp = pct[st]; pct[st] = pct[dr]; pct[dr] = temp;
			++st; --dr;
		}
	}

	if (i < dr) qsort(i, dr);
	if (st < j) qsort(st, j);
}

int main() {
	freopen("terenuri.in", "r", stdin);
	freopen("terenuri.out", "w", stdout);

	scanf("%d %d\n", &N, &M);

	for (int i = 0; i < N; ++i) {
		scanf("%Lf %Lf\n", &pct[i].x, &pct[i].y);
	}

	qsort(0, N-1);
	
	++M;
	while (M--) {
		sus[0] = 0;
		sus[1] = 1;
		vfS = 2;
		for (int i = 2; i < N; ++i) {
			sus[vfS++] = i;
			while (vfS > 2 && !(dreapta(pct[sus[vfS-3]], pct[sus[vfS-2]], pct[sus[vfS-1]]))) {
				--vfS;
				sus[vfS - 1] = sus[vfS];
			}
		}
	
		jos[0] = 0;
		jos[1] = 1;
		vfJ = 2;
		for (int i = 2; i < N; ++i) {
			jos[vfJ++] = i;
			while (vfJ > 2 && !(stanga(pct[jos[vfJ-3]], pct[jos[vfJ-2]], pct[jos[vfJ-1]]))) {
				--vfJ;
				jos[vfJ - 1] = jos[vfJ];
			}
		}
		
		printf("%d\n", vfS + vfJ - 2);
		if (M == 0) break;
		Punct temp;
		scanf("%Lf %Lf\n", &temp.x, &temp.y);
		++N;
		int i;
		for (i = N-2; i >= 0 && temp < pct[i]; --i) pct[i+1] = pct[i];
		pct[i+1] = temp;
		
	}

	return 0;
}

