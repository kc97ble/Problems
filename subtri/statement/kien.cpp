#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int n, a[N][N], s[N][N];
#define s(i, l, r) (s[i][r]-s[i][l-1])

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	for (int j=1; j<=2*i-1; j++) {
		scanf("%d", &a[i][j]);
		s[i][j] = s[i][j-1] + a[i][j];
	}
	
	int Max = -0x3c3c3c3c;
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=2*i-1; j++)
	if (j&1) {
		int L=j, R=j, S=0;
		for (int k=i; k<=n; k++, R+=2) {
			S += s(k, L, R);
			Max = max(Max, S);
		}
	}
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=2*i-1; j++)
	if (~j&1) {
		int L=j, R=j, S=0;
		for (int k=i; k>=1 && L>=1 && R<=2*k-1; k--, L-=2) {
			S += s(k, L, R);
			Max = max(Max, S);
		}
	}
	cout << Max << endl;
}

