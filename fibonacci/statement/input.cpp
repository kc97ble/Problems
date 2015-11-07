#include <bits/stdc++.h>
using namespace std;

#define long long long
const long M = 1000000007; // modulo
map<long, long> F;

long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

long ns[]={
	50,50,50,50,50,50,50,50,
	1e6,1e6,1e6,1e6,1e6,1e6,
	1e12,1e12,1e12,1e12,1e12,1e12,
	0
};

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

main(){
	F[0]=F[1]=1;
	
	for (int i=0; ns[i]; i++) {
		openfile("%d.in", i);
		long n=bw(1, ns[i]);
		cout << n << endl;
		
		openfile("%d.ans", i);
		cout << f(n-1) << endl;
	}
}
