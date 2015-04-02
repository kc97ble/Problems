#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<int, int> ii;
#define X first
#define Y second

#define N 1003
int n, Lim=0, a[N], b[N][64];

int sum(int a[], int n) {
	int S = 0;
	for (int i=1; i<=n; i++)
		S += a[i];
	return S;
}

main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++) { 
		long x; cin >> x;
		a[i]=__builtin_popcountll(x);
		Lim = max(Lim, 64-__builtin_clzll(x));
	}
	if (sum(a, n)&1) 
		{ cout << -1 << endl; return 0; }
	priority_queue<ii> qu;
	for (int i=1; i<=n; i++)
		if (a[i]) qu.push(ii(a[i], i));
	int Cur=0;
	while (qu.size()) {
		if (qu.size()==1) 
			{ cout << -1 << endl; return 0; }
		ii u=qu.top(); qu.pop();
		ii v=qu.top(); qu.pop();
		if (b[u.Y][Cur] || b[v.Y][Cur]) Cur++;
		b[u.Y][Cur]=1; u.X--;
		b[v.Y][Cur]=1; v.X--;
		if (u.X) qu.push(u);
		if (v.X) qu.push(v);
	}
	if (Cur+1>Lim) 
		{ cout << -1 << endl; return 0; }
	for (int i=1; i<=n; i++) {
		long x = 0;
		for (int j=Cur; j>=0; j--)
			x = x*2+b[i][j];
		cout << x << (i==n)[" \n"];
	}
}
