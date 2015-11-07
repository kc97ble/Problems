#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long
const int N = 100005;
int m, n, k;
char a[N], b[N];
long a1[N], b1[N], M[N];
map<long, int> Map;

void hash_init(char a[], int n, long H[]) 
	{ for (int i=1; i<=n; i++) H[i]=H[i-1]*M[1]+a[i]; }
long hash_range(long H[], int L, int R)
	{ return H[R] - H[L-1] * M[R-L+1]; }
inline bool maximize(int &a, int b)
	{ if (a<b) a=b; else return false; return true; }

bool hash_cmp(long H[], int x, int y, int r) {
	int ll=1, rr=r, mm=(ll+rr)/2;
	while (ll!=rr) {
		long H1 = hash_range(H, x, x+mm-1);
		long H2 = hash_range(H, y, y+mm-1);
		if (H1==H2) ll=mm+1; else rr=mm;
		mm=(ll+rr)/2;
	}
	return b[x+mm-1]<b[y+mm-1];
}

int f(int r, bool Tracing=false) {
	int Max = 0;
	Map.clear();
	for (int i=1; i<=m-r+1; i++)
		Map[hash_range(a1, i, i+r-1)]=0;
	for (int i=1; i<=n-r+1; i++) {
		long H = hash_range(b1, i, i+r-1);
		if (Map.count(H))
		Max = max(Max, ++Map[H]);
	}
	if (Tracing) {
		int dx=-1;
		for (int i=1; i<=n-r+1; i++) {
			long H = hash_range(b1, i, i+r-1);
			if (Map.count(H) && Map[H]>=k)
			if (dx==-1 || hash_cmp(b1, i, dx, r))
			dx=i;
		}
		return dx;
	}
	return Max;
}

main() {
//	freopen("gattaca.inp", "r", stdin);
//	freopen("gattaca.out", "w", stdout);
	
	M[0]=1; M[1]=2309; for (int i=2; i<N; i++) M[i]=M[i-1]*M[1];
	scanf("%d%d%d", &m, &n, &k);
	scanf("%s%s", a+1, b+1);
	hash_init(a, m, a1);
	hash_init(b, n, b1);
	
	int ll=1, rr=m, mm=(ll+rr)/2;
	while (ll!=rr) {
		if (f(mm)>=k) ll=mm; else rr=mm-1;
		mm=(ll+rr+1)/2;
	}
	printf("%.*s\n", mm, b+f(mm, true));
}
