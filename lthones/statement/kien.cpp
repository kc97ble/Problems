#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int A[64], B[64], k, F[64];
long G[64][2][2][64];
bool GG[64][2][2][64];
#define C n][Less][More][Count

int f(int n) {
	if (n==1) return 0;
	return 1 + f(__builtin_popcount(n));
}

long g(int n, bool Less, bool More, int Count) {
	if (n==0) return F[Count]==k-1;
	if (GG[C]++) return G[C];
	long Sum = 0;
	for (int i=0; i<=1; i++)
	if (Less || i<=B[n-1])
	if (More || i>=A[n-1])
	Sum += g(n-1, Less || i<B[n-1], More || i>A[n-1], Count+i);
	return G[C] = Sum;
}

main() {
	long AA, BB;
	cin >> AA >> BB >> k;
	if (k==0) {
		cout << (AA==1 ? 1 : 0) << endl;
		return 0;
	} else {
		if (AA==1) AA=2;
	}

	for (int i=1; i<=63; i++)
		F[i] = f(i);
	for (int i=0; i<63; i++)
		A[i] = (1LL<<i) & AA ? 1 : 0;
	for (int i=0; i<63; i++)
		B[i] = (1LL<<i) & BB ? 1 : 0;
	//for (int i=0; i<63; i++) printf("%d", A[i]); puts("A");
	//for (int i=0; i<63; i++) printf("%d", B[i]); puts("B");
	cout << g(63, 0, 0, 0) << endl;
}

