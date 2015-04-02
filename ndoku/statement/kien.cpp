#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
char a[123][123];

main() {
	freopen("ndocu.inp", "r", stdin);
	freopen("ndocu.out", "w", stdout);
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	scanf("%s", a[i]);
	
	for (int i=0; i<n*n; i++) {
		for (int j=0; j<n*n; j++)
		printf("%c", a[(i%n + j/n)%n][(j%n + i/n)%n]);
		printf("\n");
	}
}
