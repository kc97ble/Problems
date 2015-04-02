#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int m, n; long k;
long F[20][50];
bool FF[20][50];

long f(int m, int s) {
	if (m==0) return 1;
	if (FF[m-1][s-1]++) return F[m-1][s-1];
	long Sum = 0;
	for (int i=s; i<=n; i++)
	Sum += f(m-1, i);
	return F[m-1][s-1] = Sum;
}

main() {
	cin >> m >> n >> k;
	//cout << f(m, 1) << endl;
	
	int j=1;
	for (int i=m; i>=1; i--) {
		while (f(i-1, j) < k) 
		{ k-=f(i-1, j); j++; }
		printf(i==1 ? "%d\n" : "%d ", j);
	}
}
