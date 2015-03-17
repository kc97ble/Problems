#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 52;
int F[N][N][N];
bool FF[N][N][N];

int f(int m, int n0, int n1, int n2, int k) {
	if (m==0) return k==0;
	#define THIS m][n0][n1
	if (FF[THIS]++) return F[THIS];
	int Sum = f(m-1, n0, n1, n2, k);
	if (k >= 1) {
		if (n0) Sum += f(m-1, n0-1, n1+1, n2, k-1) * n0;
		if (n1) Sum += f(m-1, n0, n1-1, n2+1, k-1) * n1;
	}
	if (k >= 2) {
		if (n0 >= 2) Sum += f(m-1, n0-2, n1+2, n2, k-2) * (n0*(n0-1)/2);
		if (n1 >= 2) Sum += f(m-1, n0, n1-2, n2-2, k-2) * (n1*(n1-1)/2);
		if (n0 && n1) Sum += f(m-1, n0-1, n1, n2+1, k-2) * (n0*n1);
	}
	return F[THIS] = Sum % 10003;
}

main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	cout << f(m, n, 0, 0, k) << endl;
}
