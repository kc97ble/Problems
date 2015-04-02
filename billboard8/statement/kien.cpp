#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int oo = 0x3c3c3c3c;
int m, n;
char a[12][12], a0[12][12];

void touch(int x, int y) {
	for (int i=-1; i<=1; i++)
	for (int j=-1; j<=1; j++)
	if (a[x+i][y+j]) 
	a[x+i][y+j] ^= ('.'^'*');
}

int f(int A, int B) {
	memcpy(a, a0, sizeof a0);
	int c=0;
	for (int i=1; i<=m; i++)
		if ((1<<i-1) & A)
		{ touch(i, 1); c++; }
	for (int j=1; j<=n; j++)
		if ((1<<j-1) & B)
		{ touch(1, j); c++; }
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	if (a[i][j]=='.') {
		if (i==m || j==n) return oo;
		touch(i+1, j+1); c++;
	}
	return c;
}

main(){
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
	scanf("%s", a0[i]+1);
	
	int Min = oo;
	for (int i=0; i<(1<<m); i++)
	for (int j=0; j<(1<<n); j++)
	Min = min(Min, f(i, j));
	
	if (Min==oo) Min=-1;
	cout << Min << endl;
}
