#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const int M = 1000000007;
int n, Lim, k;
long F[2][302][302];
#define C u&1][Depth][k

long f(int u, int Depth, int k, bool Solved=true) {
	if (u==n+1) return Depth==0 && k==0;
	if (Solved) return F[C];

	long Sum = 0;
	if (Depth!=Lim && k) { // open
		Sum += f(u+1, Depth+1, k-1);
		Sum += f(u+1, Depth, k-1);
	}
	if (Depth!=0) { // close
		Sum += f(u+1, Depth-1, k);
		Sum += f(u+1, Depth, k);
	}
	//printf("f(%d, %d, %d) = %lld\n", u, Depth, k, Sum);
	return F[C] = Sum%M;
}

main(){
	scanf("%d%d%d", &n, &Lim, &k);

	for (int i=n; i>=1; i--)
	for (int j=0; j<=Lim; j++)
	for (int k=0; k<=::k; k++)
	f(i, j, k, false);

	long Z=1; f1(i,k) Z=Z*i%M;
	printf("%d\n", int(f(1, 0, k)*Z%M));
}
