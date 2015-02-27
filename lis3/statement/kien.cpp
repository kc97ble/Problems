#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const int M = 1000000007;
bool FF[2][60][60][60][60];
long F[2][60][60][60][60];
#define C Done][n][x][y][z

long f(int n, int x, int y, int z, bool Done) {
	if (n==0) return Done;
	if (FF[C]++) return F[C];
	long Sum = 0;
	for (int i=1; i<=x-1; i++)
		Sum += f(n-1, i, y-1, z-1, Done);
	for (int i=x+1; i<=y-1; i++)
		Sum += f(n-1, x, i, z-1, Done);
	for (int i=y+1; i<=z-1; i++)
		Sum += f(n-1, x, y, i, true);
	return F[C] = Sum % M;
}

struct naive {
	int n, a[1003], F[1003], b[1003];
	naive(int n) : n(n)
		{ f1(i,n) a[i]=i; }
	int lis(){
		int m=0;
		for (int i=1; i<=n; i++) {
			F[i] = lower_bound(b+1, b+m+1, a[i]) - b;
			b[F[i]]=a[i];
			m = max(m, F[i]);
		}
		//f1(i,n) printf("%d ", a[i]); printf("lis = %d\n", m);
		return m;
	}
	long solve() {
		long Count = 0;
		do { if (lis()==3) Count++; }
		while (next_permutation(a+1, a+n+1));
		return Count;
	}
};

main(){
	int n; scanf("%d", &n);
	cout << f(n, n+1, n+2, n+3, false) << endl;
	//cout << naive(n).solve() << endl;
}
