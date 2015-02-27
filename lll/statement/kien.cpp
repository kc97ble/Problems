#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 32
int m, n;
char a[N][N];

struct set3 {
	int x, y, z;
	set3(int X, int Y, int Z)
		{ x=X, y=Y, z=Z; }
	inline int size()
		{ return !!x + !!y + !!z; }
	inline int count(int k)
		{ return (x==k) + (y==k) + (z==k); }
	inline void sort() {
		if (x>y) swap(x, y);
		if (y>z) swap(y, z);
		if (x>y) swap(x, y);
	}
};

set3 operator + (set3 Set, int k) {
	if (Set.x==0) return Set.x=k, Set;
	if (Set.y==0) return Set.y=k, Set;
	if (Set.z==0) return Set.z=k, Set;
	return Set;
}

set3 operator - (set3 Set, int k) {
	if (Set.x==k) return Set.x=0, Set;
	if (Set.y==k) return Set.y=0, Set;
	if (Set.z==k) return Set.z=0, Set;
	return Set;
}

int FF[2][N][N][N][N][2][4];
long F[2][N][N][N][N][2][4];
#define C x&1][y][Set.x][Set.y][Set.z][Continue][Remain

inline long f(int x, int y, set3 Set, bool Continue, int Remain);

long g(int x, int y, set3 Set, bool Continue, int Remain) {
	if (x==m+1)
		return !Set.size() && !Continue && !Remain;
	if (y==n+1)
		return Continue ? 0 : f(x+1, 1, Set, false, Remain);
	if (Continue && Set.count(y))
		return 0;
	int scy = Set.count(y);

	if (a[x][y]=='#') {
		if (scy || Continue) return 0;
		return f(x, y+1, Set, Continue, Remain);
	} else {
		long Sum = f(x, y+1, Set, Continue, Remain);
		if (Continue)
			Sum += f(x, y+1, Set, false, Remain);
		else if (scy)
			Sum += f(x, y+1, Set-y, Continue, Remain);
		else if (Remain)
			Sum += f(x, y+1, Set+y, true, Remain-1);
		return Sum;
	}
}

inline long f(int x, int y, set3 Set, bool Continue, int Remain) {
	Set.sort();
	if (FF[C]==x) return F[C]; FF[C]=x;
	F[C] = g(x, y, Set, Continue, Remain);
	//printf("f(%d, %d, %d, %d, %d, %d, %d) = %lld\n",
	//	x, y, Set.x, Set.y, Set.z, int(Continue), Remain, F[C]);
	return F[C];
}

void swap_c_str(char* a, char* b) {
	for (int i=0; a[i]; i++)
	swap(a[i], b[i]);
}

main(){
	while (gets(a[m+1]+1) && a[m+1][1]) m++;
	f0(i,m/2) swap_c_str(a[i+1]+1, a[m-i]+1);
	n=strlen(a[1]+1);
	while (a[1][n]!='.' && a[1][n]!='#') n--;
	//cout << m << " " << n << endl;
	//f1(i,m) printf("'%.*s'\n", n, a[i]+1);

	for (int i=m; i>=1; i--)
	for (int j=n; j>=1; j--)
	f0(p,n+1) f0(q,n+1) f0(w,n+1) f0(x,2) f0(y,4)
	if (p<=q && q<=w) if (!q || p!=q) if (!w || q!=w)
	f(i, j, set3(p, q, w), x, y);

	cout << f(1, 1, set3(0, 0, 0), false, 3) << endl;
}
