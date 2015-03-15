#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long

#define N 20004
const int oo = 0x3c3c3c3c;
int n, m, b[14], T, Next[14][N];
char a[N]; long M[N], H[N];

void hash(char a[], int n, long H[]) 
	{ H[0]=0; for (int i=1; i<=n; i++) H[i]=H[i-1]*M[1]+a[i]; }
long hash(long H[], int ll, int rr) 
	{ return H[rr]-H[ll-1]*M[rr-ll+1]; }

int F[1<<13]; short FF[1<<13];

int f(int Expect) {
	if (Expect==0) return 1;
	if (FF[Expect]==T) return F[Expect];
	int Min = oo;
	for (int i=1; i<=m; i++)
		if ((1<<i-1)&Expect)
		if (int x = f(Expect ^ (1<<i-1)))
		Min = min(Min, Next[i][x]);
	return FF[Expect]=T, F[Expect]=(Min==oo ? 0 : Min);
}

main(){
	M[0]=1; M[1]=2309; 
	for (int i=2; i<N; i++) 
		M[i]=M[i-1]*M[1];
	scanf("%s%d", a+1, &T); n=strlen(a+1);
	for (int i=1; i<=n; i++) 
		a[N-i]=a[i];
	hash(a, n, H);
	hash(a+N-(n+1), n, H+N-(n+1));
	
	do {
		scanf("%d", &m);
		for (int i=1; i<=m; i++) {
			scanf("%d", &b[i]);
			Next[i][n+1]=oo;
			for (int j=n; j>=1; j--) {
				Next[i][j] = Next[i][j+1];
				if (j+b[i]-1<=n) {
					long H1=hash(H, j, j+b[i]-1);
					long H2=hash(H, N-(j+b[i]-1), N-j);
					if (H1==H2) Next[i][j] = j+b[i];
				}					
			}
		}
		cout << (f((1<<m)-1) ? "YES" : "NO") << endl;
	} while (--T);
}
