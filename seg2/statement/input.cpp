#include <bits/stdc++.h>
using namespace std;

#define long long long

int t=0;

void openfile(const char fmt[], int Index) {
	char fn[128];
	sprintf(fn, fmt, Index);
	fprintf(stderr, "%s\n", fn);
	freopen(fn, "w", stdout);
	//cin.ignore(1);
}

unsigned long rand32()
	{ return rand()<<16 | rand(); }
unsigned long rand64()
	{ return rand32()<<32 | rand32(); }
int bw(int a, int b)
	{ return a+rand32()%(b-a+1); }
long bw(long a, long b)
	{ return a+rand64()%(b-a+1); }

void gen(int MaxN, int MaxM, long MaxAbs, long MaxX) {
	openfile("%d.in", t++);
	int n=bw(1, MaxN), m=bw(1, MaxM);
	printf("%d %d\n", n, m);
	for (int i=1; i<=n; i++)
		printf(i==n ? "%lld\n" : "%lld ", bw(1LL, MaxAbs));
	for (int i=1; i<=m; i++) {
		if (rand()&1) {
			int mm=bw(1, n), ll=bw(1, mm), rr=bw(mm, n);
			printf("INC %d %d %lld\n", ll, rr, bw(1LL, MaxAbs));
		} else {
			printf("LWB %d %lld\n", bw(1, n), bw(1LL, MaxX));
		}
	}
}

main() {
	#define loop(n) for (int i=1; i<=n; i++)
	loop(5) gen(10, 10, 10, 100);
	loop(5) gen(100000, 100000, 100000, 1e13);
	loop(10) gen(100000, 100000, 1e9, 1e18);
	loop(5) gen(100000, 100000, 1e12, 1e18);
}
