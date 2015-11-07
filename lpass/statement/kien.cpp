#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, string> is;
#define X first
#define Y second

int n, k, b[123], t;
string a[123];

is operator + (is a, is b)
	{ return is(a.X+b.X, a.Y+b.Y); }

int FF[123][123][9];
is F[123][123][9];

is f(int n, int k, int p) {
	if (n==0 || k==0) return is(p!=0 ? -0x3c3c3c3c : 0, "");
	if (FF[n][k][p]!=t) FF[n][k][p]=t; else return F[n][k][p];
	is Max = f(n-1, k, p);
	Max = max(Max, is(a[n].size(), a[n]) + f(n-1, k-1, (p+b[n])%9));
	//printf("f(%d, %d, %d) = %d, %s\n", n, k, p, Max.X, Max.Y.c_str());
	return F[n][k][p] = Max;
}

bool cmp(string a, string b)
	{ return a+b < b+a; }

main() {
	freopen("lpass.inp", "r", stdin);
	freopen("lpass.out", "w", stdout);
	
	scanf("%d", &t);
	do {
		scanf("%d%d", &n, &k);
		for (int i=1; i<=n; i++)
		cin >> a[i];
		sort(a+1, a+n+1, cmp);
		
		for (int i=1; i<=n; i++) {
			b[i] = 0;
			for (int j=0; j<a[i].size(); j++)
			b[i] = (b[i] + (a[i][j]-'0')) % 9;
			//printf("b[%d] = %d\n", i, b[i]);
		}
		
		is Result = f(n, k, 0);
		if (Result.X <= 0) cout << -1 << endl;
		else cout << Result.Y << endl;
	} while (--t);
}
