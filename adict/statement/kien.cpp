#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int n, m, q, M=0;
bool Forbid[1<<17];
long F[52][1<<17];
bool FF[52][1<<17];
#define C u][Last

long f(int u, int Last, int Tracing=-1) {
	if (Forbid[Last] && u>M) return 0LL;
	if (u==n+1) return 1LL;
	if (Tracing==-1 && FF[C]++) return F[C];
	long Sum1 = f(u+1, (Last*2) & (1<<M)-1);
	long Sum2 = f(u+1, (Last*2+1) & (1<<M)-1);
	if (Tracing!=-1) {
		printf(Tracing<Sum1 ? "A" : "B");
		if (Tracing < Sum1)
		f(u+1, (Last*2) & (1<<M)-1, Tracing);
		else
		f(u+1, (Last*2+1) & (1<<M)-1, Tracing-Sum1);
	}
	return F[C] = Sum1 + Sum2;
}

main(){
	char a[123];
	scanf("%d%d", &n, &m);
	while (m-->0) {
		int H=0, G=0;
		scanf("%s", a);
		if (!M) M=strlen(a);
		f0(i,M) {
			H = H*2 + (a[i]=='B');
			G = G*2 + (a[i]!='?');
		}  // done H, G

		f0(i,(1<<M)) if ((i&G)==H)
		Forbid[i]=true;
	}

	long Count = f(1, 0);
	scanf("%d", &q);
	while (q-->0) {
		long x; cin >> x;
		if (x>=Count) printf("NOPAGE\n");
		else { f(1, 0, x); printf("\n"); }
	}
}
