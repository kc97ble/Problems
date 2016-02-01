#include <bits/stdc++.h>
using namespace std;

const int oo = 0x3c3c3c3c;
int n, M;
int a[102];
int F[102][100005];

main() {
	scanf("%d%d", &n, &M);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	for (int x=0; x<M; x++)
	F[0][x] = (x==0 ? 0 : -oo);
	
	for (int i=1; i<=n; i++)
	for (int x=0; x<M; x++)
	F[i][x] = max(F[i-1][x], F[i-1][(x+a[i])%M]+1);
	
	cout << F[n][0] << endl;
}
