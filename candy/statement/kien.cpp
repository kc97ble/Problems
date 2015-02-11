#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<double, long> lfll;
#define X first
#define Y second

#define N 100005
const int oo = 0x3c3c3c3c;
int m, n, a[N];
lfll ss[N]; long s[N];

lfll operator + (lfll a, lfll b)
	{ return lfll(a.X+b.X, a.Y+b.Y); }

lfll f(long m, int u){
	int L=n-u+1; long S=s[n]-s[u-1];
	if (m<0) return lfll(9e23, 9LL*oo*oo);
	if (m/L > a[u]) return lfll(9e23, 9LL*oo*oo);
	if (m%L && m/L+1 > a[n-m%L+1]) return lfll(9e23, 9LL*oo*oo);
	double x = 1.*(m/L)*(m/L)*(L-m%L) + 1.*(m/L+1)*(m/L+1)*(m%L);
	long y = 1LL*(m/L)*(m/L)*(L-m%L) + 1LL*(m/L+1)*(m/L+1)*(m%L);
	//printf("f(%lld, %d) = %lf, %lld\n", m, u, x, y);
	return lfll(x, y);
}

main(){
	scanf("%d%d", &m, &n);
	f1(i,n) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	f1(i,n) s[i] = s[i-1] + a[i];
	f1(i,n) ss[i] = ss[i-1] + lfll(1.*a[i]*a[i], 1LL*a[i]*a[i]);
	lfll Min = lfll(9e23, 9LL*oo*oo);
	for (int i=1; i<=n; i++)
	Min = min(Min, f(s[n]-m-s[i-1], i) + ss[i-1]);
	//cout << Min.X << " " << Min.Y << endl;
	cout << Min.Y << endl;
}
