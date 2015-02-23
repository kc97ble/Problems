#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define N 202
const int oo = 0x3c3c3c3c;
const long ooLL = 1LL*oo*oo;
int Seat, n, m, a[N], b[N], Least[N];
int U, mm;

inline long ceil(long a, long b)
	{ return (a+(b-1))/b; }

//#define return(x) { printf("f(%d, %d, (%d, %d)) = %lld\n", u, m, U, mm, x); return x; }

long F[N][N];
int FF[N][N], t;

long f(int u, long m) {
	if (FF[u][m]==t) return F[u][m];
	if (m<0) m=0LL;
	if (u==n+1) return (m==0 ? 0LL : ooLL);
	if (u==U) return (f(u+1, m-mm) + a[u]);

	long Gain = ((1LL*a[u]*(mm+1))-(u>U)) / a[U];
	if (a[u]*20LL<Seat) Gain=0LL;
	long Min = f(u+1, m-Gain) + a[u];

	if (a[u]*20LL<Seat) {
		long New = ceil(Seat, 20LL);
		long Gain = ((1LL*New*(mm+1))-(u>U)) / a[U];
		Min = min(Min, f(u+1, m-Gain) + New);
	}

	for (int i=Gain+1; i<=m; i++) {
		long New = ceil(1LL*a[U]*i+(u>U), mm+1);
		if (New*20LL<Seat) continue;
		Min = min(Min, f(u+1, m-i) + New);
	}
	FF[u][m]=t;
	return (F[u][m]=Min);
}

long solve(int i, int j) {
	U=i; mm=j; t++;
	//printf("solve(%d, %d) = %lld\n", i, j, f(i, m));
	return f(1, m);
}

int winner() {
	int u=0;
	for (int i=1; i<=n; i++)
		if (1LL*a[i]*20 >= Seat)
		if (u==0 || 1LL*a[i]*b[u]>1LL*a[u]*b[i]) u=i;
	return u;
}

long compute(int u) {
	int Used=0;
	for (int i=1; i<=n; i++)
		Used += a[i];
	a[u]+=Seat-Used;
	for (int i=1; i<=n; i++)
		b[i]=1;
	for (int i=1; i<=m; i++)
		b[winner()]++;
	a[u] -= Seat-Used;
	return b[u]-1;
}

main(){
	scanf("%d%d%d", &Seat, &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		printf(i==n ? "%d\n" : "%d ", compute(i));
	for (int i=1; i<=n; i++) {
		if (a[i]*20LL<Seat)
			Least[i] = 0;
		else {
			int ll=0, rr=m, mm=(ll+rr)/2;
			while (ll<rr) {
				if (solve(i, mm)<=Seat) rr=mm; else ll=mm+1;
				mm=(ll+rr)/2;
			}
			Least[i]=mm;
		}
	}
	for (int i=1; i<=n; i++)
		printf(i==n ? "%d\n" : "%d ", Least[i]);
}
