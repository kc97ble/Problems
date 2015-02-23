#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 3003
int m, n, k, G[N][N];
char a[N], b[N];
#define g(x, y) G[x][y]

int h(int x, int y, int z) {
	int Count = 0;
	Count += g(0, 0)>=x && g(x, x)>=y && g(x+y, x+y)>=z; // x y z
	Count += g(0, 0)>=x && g(x, x+z)>=y && g(x+y, x)>=z; // x z y
	Count += g(0, y)>=x && g(x, 0)>=y && g(x+y, x+y)>=z; // y x z
	Count += g(0, y+z)>=x && g(x, 0)>=y && g(x+y, y)>=z; // y z x
	Count += g(0, z)>=x && g(x, x+z)>=y && g(x+y, 0)>=z; // z x y
	Count += g(0, y+z)>=x && g(x, z)>=y && g(x+y, 0)>=z; // z y x
	//printf("h(%d, %d, %d) = %d\n", x, y, z, Count);
	return !!Count;
}

main(){
	freopen("hstr.inp", "r", stdin);
	freopen("hstr.out", "w", stdout);
	
	scanf("%d%s%s", &k, a, b); m=strlen(a); n=strlen(b);
	for (int i=m-1; i>=0; i--)
	for (int j=n-1; j>=0; j--)
	if (abs((int)a[i]-(int)b[j]) <= k)
	G[i][j]=G[i+1][j+1]+1;
	
	long Sum = 0;
	f1(i,m) f1(j,m) if (i+j<m) 
	Sum += h(i, j, m-i-j);
	cout << Sum << endl;
}
