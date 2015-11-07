#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 123;
int n, m, Tens[N];
bool FF[N][N];
long F[N][N];

long f(int L, int R, int x) {
	if (L>R) return x==0;
	if (FF[L][x]++) return F[L][x];
	
	long Sum = 0;
	for (int i=(L==1 ? 1 : 0); i<=9; i++) {
		int y = (L==R ? Tens[n-L] : Tens[n-L] + Tens[n-R]) * i;
		Sum += f(L+1, R-1, (x+y)%m);
	}
	//printf("f(%d, %d, %d) = %d\n", L, R, x, Sum);
	return F[L][x] = Sum;
}

main() {
//	freopen("palinn.inp", "r", stdin);
//	freopen("palinn.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	Tens[0]=1; Tens[1]=10; 
	for (int i=2; i<N; i++) 
	Tens[i] = Tens[i-1] * Tens[1] % m;
	cout << f(1, n, 0) << endl;
	
	char s[N]; long k; cin >> k;
	for (int L=1, R=n, x=0; L<=R; L++, R--) {
		for (int i=(L==1 ? 1 : 0); i<=9; i++) {
			int y = (L==R ? Tens[n-L] : Tens[n-L] + Tens[n-R]) * i;
			long fx = f(L+1, R-1, (x+y)%m);
			if (fx<k) k -= fx;
			else { x=(x+y)%m; s[L]=s[R]=(i+'0'); break; }
		}
	}
	s[n+1]=0; puts(s+1);
}
