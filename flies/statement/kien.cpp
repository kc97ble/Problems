#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, t;
double F[5003][5003];
short FF[5003][5003];

inline double f(int n, int A, int B) {
	if (n==0) return 1.0;
	if (FF[A][B]!=t) FF[A][B]=t; else return F[A][B];
	double Sum = f(n-1, A+1, B) * (k-A-B) / k;
	if (A) Sum += f(n-1, A-1, B+1) * A / k;
	return F[A][B] = Sum;
}

main() {
	while (scanf("%d%d", &n, &k) > 0) {
		t++;
		(cout << fixed).precision(6);
		if (n>=3*k) cout << 1.0 << endl;
		else cout << 1-f(n, 0, 0) << endl;
	}
}
