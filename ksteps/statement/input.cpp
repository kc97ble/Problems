#include <bits/stdc++.h>
using namespace std;

#define long long long

int Test=0;
int c[123][123];

void openfile(const char fmt[], int Index) {
	char fn[128];
	sprintf(fn, fmt, Index);
	fprintf(stderr, "%s\n", fn);
	freopen(fn, "w", stdout);
}

unsigned long rand32()
	{ return rand()<<16 | rand(); }
unsigned long rand64()
	{ return rand32()<<32 | rand32(); }
long bw(long a, long b) 
	{ return a+rand64()%(b-a+1); }
	
void gen(int Count, int MaxN, long MaxK) {
	for (; Count--; Test++) {
		int n = bw(1, MaxN);
		int S=bw(1, n), T=bw(1, n);
		long k = bw(1, MaxK);
		int Threshold=rand();
		
		openfile("%d.in", Test);
		printf("%d %d %d %lld\n", n, S, T, k);
		
		memset(c, 0, sizeof c);
		for (int i=1; i<=n; i++)
			for (int j=1; j<i; j++)
			c[i][j]=c[j][i]=(rand() <= Threshold);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
			printf(j==n ? "%d\n" : "%d ", c[i][j]);
	}
}

main() {
	gen(5, 5, 20);
	gen(5, 30, 1e5);
	gen(5, 30, 1e12);
	gen(5, 30, 1e18);
}
