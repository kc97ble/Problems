#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 51;
const int oo = 0x3c3c3c3c;
int n, a[N], b[N];

short F[25000][51][26];
bool FF[25000][51][26];
#define C y][n][r

//#define return(x) { printf("f(%d, %d, %d) = %d\n", y, n, r, x); return x; }

int f(int y, int n, int r) {
	if (n==0) return ((y==0 && r==0) ? 0 : oo);
	if (FF[C]++) return (F[C]==-1 ? oo : F[C]);
	int Min = f(y, n-1, r);
	if (y>=b[n] && r!=0)
		Min = min(Min, f(y-b[n], n-1, r-1)+a[n]);
	F[C] = (Min==oo ? -1 : Min);
	return (Min);
}

int sum(int a[], int n) {
	int Sum = 0;
	for (int i=1; i<=n; i++)
		Sum += a[i];
	return Sum;
}

main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);

	int SumA = sum(a, n);
	int SumB = sum(b, n);
	double Min = 9e23;

	for (int y=0; y<=SumB; y++)
	if (2*y<=SumB) {
		int x = f(y, n, n/2);
		if (x>=oo) continue;
		Min = min(Min, 1.*x/y+1.*(SumA-x)/(SumB-y));
	}
	cout.precision(17);
	cout << Min << endl;
}

