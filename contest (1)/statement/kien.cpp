#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 402
int m, n, k, a[N][N];
bool b[N][N];

bool ok(int Used){
	f1(i,m) {
		bool Any = false;
		f1(j,n) if ((1<<j-1)&Used)
		if (Any |= b[i][j]) break;
		if (!Any) return false;
	}
	return true;
}

bool solve1() { // n<m
	f0(Used,(1<<n))
	if (__builtin_popcount(Used) <= k)
	if (ok(Used)) return true;
	return false;
}

int d[1<<20], Mask[N]; //

bool solve2() { //m<n
	memset(d, 0, sizeof d);
	memset(Mask, 0, sizeof Mask);
	int S=0, T=(1<<m)-1;
	queue<int> qu;
	qu.push(S); d[S]=1;

	f1(i,m) f1(j,n) // Mask[1..n]
	Mask[j] = Mask[j]*2 + b[i][j];

	while (qu.size()) {
		int u=qu.front(); qu.pop();
		if (u==T) return d[T]-d[S] <= k;
		f1(i,n) if (int v=u|Mask[i])
		if (d[v]==0) {
			d[v]=d[u]+1;
			qu.push(v);
		}
	}
	return false;
}

main(){
	int T; scanf("%d", &T);
	while (T-->0) {
		scanf("%d%d%d", &k, &m, &n);
		f0(i,m) f1(j,n) scanf("%d", &a[i][j]);
		if (m==1) {
			cout << "TAK" << endl;
		} else {
			m--; // 0 .. m
			f1(i,m) f1(j,n) b[i][j]=(a[0][j]>a[i][j]);
			// choose at most k from n to avoid 000000
			bool Result = (n<m ? solve1() : solve2());
			cout << (Result ? "TAK" : "NIE") << endl;
		}
	}
}
