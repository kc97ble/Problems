#include <bits/stdc++.h>
using namespace std;

#define long long long

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
long bw(long a, long b) 
	{ return a+rand64()%(b-a+1); }
	
const int M=1000000007, N=100005;
int t=0, a[N];

void gen(int MaxN, int MaxM, int MaxAbs) {
	openfile("%d.in", t++);
	int n=bw(1, MaxN), m=bw(1, MaxM);
	cout << n << " " << m << endl;
	for (int i=1; i<=n; i++)
	printf(i==n ? "%d\n" : "%d ", a[i]=bw(-MaxAbs, MaxAbs));
	
	for (int i=1; i<=m; i++) {
		if (rand()&1) {
			int mm=bw(1, n), ll=bw(1, mm), rr=bw(mm, n);
			printf("INC %d %d %d\n", ll, rr, bw(-MaxAbs, MaxAbs));
		} else if (rand()&1) {
			printf("SET %d %d\n", bw(1, n), bw(-MaxAbs, MaxAbs));
		} else {
			int mm=bw(1, n), ll=bw(1, mm), rr=bw(mm, n);
			printf("SUM %d %d\n", ll, rr);
		}
	}
}
	
main() {
	srand(2309);
	for (int i=1; i<=5; i++)
		gen(10, 20, 10);
	for (int i=1; i<=5; i++)
		gen(20, 1000, 100);
	for (int i=1; i<=15; i++)
		gen(100000, 100000, M-1);
}
