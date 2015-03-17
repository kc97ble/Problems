#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int n, k, m;
int F[2][202][202];
int GX[2][202][202];
int GY[2][202][202];
#define C n&1][x][y

long f(int n, int x, int y, bool Solved=true);

long gx(int n, int x, int y, bool Solved=true) {
	if (x==0) return 0;
	if (Solved) return GX[C];
	if (x>y) return 832756;
	assert(0<=n && n<=::n && 1<=x && x<=k && x<=y && y<=k);
	long Sum = f(n, x, y);
	Sum += gx(n, x-1, y);
	return GX[C] = Sum % m;
}

long gx(int n, int x1, int x2, int y) {
	if (x1>x2) return 0;
	return gx(n, x2, y) - gx(n, x1-1, y);
}

long gy(int n, int x, int y, bool Solved=true) {
	if (y==0) return 0;
	if (Solved) return GY[C];
	if (x>y) return 324823;
	assert(0<=n && n<=::n && 1<=x && x<=k && x<=y && y<=k);
	long Sum = f(n, x, y);
	Sum += gy(n, x, y-1);
	return GY[C] = Sum % m;
}

long gy(int n, int x, int y1, int y2) {
	if (y1>y2) return 0;
	return gy(n, x, y2) - gy(n, x, y1-1);
}

long f(int n, int x, int y, bool Solved) {
	if (n==0) return 1;
	if (Solved) return F[C];

	long Sum = gx(n-1, 1, x, y);
	if (x<y) Sum += gy(n-1, x, x+1, y);

	/*
	long Sum = 0;
	for (int i=1; i<=x; i++)
		Sum += f(n-1, i, y);
	for (int i=x+1; i<=y; i++)
		Sum += f(n-1, x, i);
	*/
	return F[C] = Sum % m;
}

main(){
	scanf("%d%d%d", &n, &k, &m);
	for (int i=0; i<=n; i++)
	for (int x=1; x<=k; x++)
	for (int y=x; y<=k; y++) {
		f(i, x, y, false);
		gx(i, x, y, false);
		gy(i, x, y, false);
	}
	cout << (f(n, k, k)+m)%m + 1 << endl;
}

