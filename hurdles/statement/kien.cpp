#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 302
const int oo = 0x3c3c3c3c;
int n, m, q, c[N][N];

main(){
	scanf("%d%d%d", &n, &m, &q);
	f1(i,n) f1(j,n) c[i][j] = (i==j ? 0 : oo);
	f1(i,m) {
		int w, x, y;
		scanf("%d%d%d", &x, &y, &w);
		c[x][y]=w;
	}
	f1(k,n) f1(i,n) f1(j,n) 
	c[i][j] = min(c[i][j], max(c[i][k], c[k][j]));
	
	while (q-->0) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", c[x][y]==oo ? -1 : c[x][y]);
	}
}
