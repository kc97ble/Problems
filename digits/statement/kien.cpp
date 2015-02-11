#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int x, t;
char a[10], b[10]; // '000000012', '000000321'

long G[10][2][2];
int GG[10][2][2];
#define C u][Less][More

long g(int u, bool Less, bool More) {
	if (a[u]=='\0') return 1;
	if (GG[C]==t) return G[C]; else GG[C]=t;
	long Sum = 0LL;
	for (int i=0; i<=9; i++)
	if (Less || i<=b[u]-'0')
	if (More || i>=a[u]-'0')
	Sum += g(u+1, Less || i<b[u]-'0', More || i>a[u]-'0');
	return G[C]=Sum;
}

long F[10][2][2][2];
int FF[10][2][2][2];
#undef C
#define C u][Less][More][One

long f(int u, bool Less, bool More, bool One) {
	if (a[u]=='\0') return 0;
	if (FF[C]==t) return F[C]; else FF[C]=t;
	long Sum = 0LL;
	for (int i=0; i<=9; i++)
	if (Less || i<=b[u]-'0')
	if (More || i>=a[u]-'0') {
		Sum += f(u+1, Less || i<b[u]-'0', More || i>a[u]-'0', One || i);
		if (i==x && (x || One))
		Sum += g(u+1, Less || i<b[u]-'0', More || i>a[u]-'0');
	}
	return F[C]=Sum;
}

main(){
	for (;;) {
		int A, B; scanf("%d%d", &A, &B);
		sprintf(a, "%09d", A);
		sprintf(b, "%09d", B);
		if (A==0 && B==0) return 0;
		for (x=0; x<=9; x++)
		cout << (++t, f(0, 0, 0, 0)) << " ";
		cout << endl;
	}
}
