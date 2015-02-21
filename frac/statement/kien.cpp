#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

long f(int n, long P, long Q) {
	long Sum = 0;
	while (n-->0) {
		Sum += P*10/Q;
		P=P*10%Q;
	}
	return Sum;
}

long power(long a, long k, int M) {
	long P=1;
	while (k) {
		if (k&1) P=P*a%M;
		k/=2; a=a*a%M;
	}
	return P;
}

long g(int n, long P, long Q) {
	//printf("g(%d, %lld, %lld)\n", n, P, Q);
	long Sum=0;
	while (n && (Q%2==0 || Q%5==0)) {
		Sum+=P*10/Q;
		P=P*10%Q;
		long G=__gcd(P, Q);
		P/=G, Q/=G;
		n--;
	}
	long p=P, Cycle=0;
	do { p=p*10%Q; Cycle++; } while (p!=P);
	Sum += f(Cycle, P, Q) * (n/Cycle);
	return Sum + f(n%Cycle, P, Q);
}

main(){
	int T; cin >> T;
	while (T-->0) {
		long P, Q, x, y, z;
		cin >> P >> Q >> x >> y;
                if (x==0) x=1;
                long M=Q;
		long G=__gcd(P, Q); P/=G, Q/=G;
		P=P*power(10, x-1, Q)%Q; z=y-x+1;

		if (z<=100) {
			cout << f(z, P, Q)%M << endl;
		} else {
			cout << g(z, P, Q)%M << endl;
		}
	}
}
