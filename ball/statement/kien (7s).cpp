#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=2003, M=1000000007;
int n;
int FF[N][N], t; //
long F[N][N];

inline long f(int L, int Used) {
	if (L==n && Used==2*L) return 1;
	if (FF[L][Used]!=t) FF[L][Used]=t; else return F[L][Used];
	long Sum=0;
	if (L<n)
		Sum += f(L+1, Used+1)*4;
	if (2*L!=Used)
		Sum += (2*L-Used) * f(L, Used+1);
	return F[L][Used] = Sum % M;
}

main() {
	scanf("%d", &t);
	do {
		scanf("%d", &n);
		for (int L=n; L>=1; L--)
		for (int Used=L*2; Used>=L; Used--)
		f(L, Used);
		printf("%d\n", int(f(1, 1)*2%M));
	} while (--t);
}
