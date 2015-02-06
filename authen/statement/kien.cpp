#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 10104
const int M = 1009419529;
int n, m, t, Next[30][N]; //
char a[N];

int FF[N][102];
char F[N][102];

long f(int u, int m) {
	if (m==n-u) return 1;
	if (m<0) return 0;
	if (F[u][m]==t) return FF[u][m];
	long Sum = 0;
        if (u<n) Sum += f(u+1, m-1) + f(u+1, m);
        if (int x=Next[a[u+1]][u+2]) Sum -= f(x, m-(x-u-1));
//	f1(k,26) if (int x=Next[k][u+1])
//	Sum += f(x, m-(x-u-1));
	//printf("f(%d, %d) = %d\n", u, m, Sum);
	return F[u][m]=t, FF[u][m]=Sum%M;
}

main(){
	//freopen("authen.inp", "r", stdin);
	//freopen("authen.out", "w", stdout);
	cin >> t;
	do {
		scanf("%d%d%s", &n, &m, a+1); n+=m;
		f1(i,n) a[i]-=96;
		f1(k,26) Next[k][n+1]=Next[k][n+2]=0;
		for (int k=26; k>=1; k--)
		for (int i=n; i>=0; i--)
		Next[k][i] = (a[i]==k ? i : Next[k][i+1]);
		for (int i=n; i>=1; i--) f(i, rand()%m+1);
		cout << (f(0, m)+M-1)%M << endl;
	} while (0<--t);
}
