#include <bits/stdc++.h>
using namespace std;

#define long long long

long mul(long a, long b, long k) {
	long a1=a>>20, a2=a&((1<<20)-1);
	return (b*a2 + ((b*a1%k)<<20)) % k;
}

long power(long a, long b, long k) {
	long P=1;
	while (b) {
		if (b&1) P=mul(P, a, k);
		b/=2; a=mul(a, a, k);
	}
	return P;
}

///////////////////////////////

int CountFile=0;
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

void generate(int Count, long A, long B, long M) {
	while (Count-->0) {
		int FileIndex = CountFile++;
		
		openfile("%d.in", FileIndex);
		long a=bw(1, A);
		long b=bw(1, B);
		long m=bw(1, M);
		cout << a << " " << b << " " << m << endl;
		
		openfile("%d.ans", FileIndex);
		cout << power(a, b, m) << endl;
	}
}

main() {
	generate(8, 1e6, 1e6, 1e9);
	generate(6, 1e6, 1e6, 1e12);
	generate(6, 1e12, 1e12, 1e9);
}
