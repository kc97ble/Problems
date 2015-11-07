#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const char ACGT[]="ACGT";
const int N = 50004;
int n, k;
char a[N];

long F[N][10][8];
bool FF[N][10][8];
#define C u][k][Just&7

long f(int u, int k, char Just) {
	if (u==n+1 || k==-1) return u==n+1 && k>=0;
	if (FF[C]++) return F[C];
	long Sum = 0;
	for (int i=0; char c=ACGT[i]; i++)
	if (c==a[u] || a[u]=='N')
	Sum += f(u+1, k-(c<Just), c);
	//printf("f(%d, %d, %c) = %lld\n", u, k, Just, Sum);
	return F[C] = Sum;
}

void trace(long x) {
	string s;
	int k = ::k-1; char Just='A';
	for (int u=1; u<=n+1; u++) {
		for (int i=0; char c=ACGT[i]; i++)
		if (c==a[u] || a[u]=='N') {
			long fv = f(u+1, k-(c<Just), c);
			if (fv>=x) { 
				k-=(c<Just); Just=c; 
				s += c;
				break; }
			else x -= fv;
		}
	}
	cout << s << endl;
}

main() {
	ios :: sync_with_stdio(false);
	long x;
	cin >> n >> k >> x;
	cin >> (a+1);
	cerr << f(1, k-1, 'A') << endl;
	trace(x);
}

