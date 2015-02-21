#include <cstdio>

#define REP(i, n) for(int i = 0, _n= (n); i < _n; ++i)
#define FOR(i, a, b) for( int i = (a), _b = (b); i <= _b; ++i )
#define INF 1000000007

int n, nrq, res, a[10];

void input() {
	scanf( "%d", &n );
	nrq = 0;
	REP(i, 10) {
		scanf( "%d", &a[i] );
		nrq += a[i];
	}
}

void btr(int k){
	if (n-k < nrq || k == n) return;

	int min = 0; if (!k) min = 1;
	FOR(i, min, 9) {
		int f = 0;
		if(a[i]>0) {
			--a[i]; f=1; --nrq;
		}
		if (nrq <= 0)
			if(++res >= INF) res -= INF;
		btr(k+1);
		if(f) {
			++a[i]; ++nrq;
		}
	}

}

int main() {
//	freopen("number.inp", "r", stdin);
//	freopen("number.out", "w", stdout);
	input();
	res = 0; btr(0);
	printf("%d\n", res);
	return 0;
}
