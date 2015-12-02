#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
#define X first
#define Y second

#define N 2003
int m, n, a[N];

ii operator + (ii a, ii b)
	{ return ii(a.X+b.X, a.Y+b.Y); }

bool maximize(ii &a, ii b)
	{ if (a<b) a=b; else return false; return true; }
int h(int x)
	{ return min(x, 2*n-x+1); }
	
ii FFF[N];
bool F[N];

ii f(int u, bool Tracing=false) {
	ii Max(0, 0);
	int Count=0, d=0;
	bool Bad=false;
	if (!Tracing && F[u]++) return FFF[u];
	
	for (int i=u+1; i<=2*n; i++) {
		if (a[i]==a[u] && (i<=n || i-n>n-u+1))
			{ Count++; Bad=true; }
		if (a[i]>a[u]) {
			ii Cost(Count*a[u]+a[i], -Count-1);
			if (maximize(Max, f(i)+Cost)) d=0;
			if (Max==f(i)+Cost && (d==0 || Bad))
			{ d=i; Bad=false; }
		}
	}
	if (maximize(Max, ii(Count*a[u], -Count))) d=-1;
	
	if (Tracing) {
		if (d==0) {
			;
		} else if (d==-1) {
			for (int i=u+1; i<=2*n; i++)
			if (a[i]==a[u] && (i<=n || i-n>n-u+1))
			printf("%d ", h(i));
		} else {
			for (int i=u+1; i<=2*n && i<d; i++)
			if (a[i]==a[u] && (i<=n || i-n>n-u+1))
			printf("%d ", h(i));
			printf("%d ", h(d)); f(d, true);
		}
	}
	return FFF[u] = Max;
}

main(){
	scanf("%d%d", &m, &n);
	f1(i,m) f1(j,n) {
		int x; scanf("%d", &x);
		a[i+n-j] += x;
	}
	n=m+n-1;
	f0(i,n) a[2*n-i]=a[i+1];
	cout << f(0).X << endl;
	cout << -f(0).Y << endl;
	f(0, true);
}
