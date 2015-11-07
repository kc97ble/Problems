#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int M = 1000000123;
int B, C5[]={1, 5, 10, 10, 5, 1};

map<long, long> F[11][11][2][11];
#define C k][kx][Zero][B

long f(long n, int k, int kx, bool Zero) {
	if (n==0) return k==kx && !Zero;
	if (F[C].count(n)) return F[C][n];
	if (n&1) {
		long Sum = 0;
		if (Zero) Sum += f(n-1, k, kx, true);
		if (k>0) Sum += f(n-1, k-1, kx, false) * k;
		if (k<B) Sum += f(n-1, k+1, kx, false) * (B-k-Zero);
		return F[C][n] = Sum % M;
	} else {
		long Sum=0, n1=n/2, n2=n-n1;
		if (Zero)
			Sum += f(n2, k, kx, Zero);
		for (int i=0; i<=B; i++) {
			long F1 = f(n1, k, i, Zero);
			long F2 = f(n2, i, kx, false);
			Sum += F1 * F2 % M;
		}
		return F[C][n] = Sum % M;
	}
}

main() {
	long n;
	while (cin >> n) {
		long Sum = 0;
		for (B=5; B<=10; B++)
		Sum += f(n, B-5, 0, true) * C5[B-5];
		cout << Sum % M << endl;
	}
}

