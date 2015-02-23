#include <stdio.h>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100
int m, n, k, a[N][N], b[N][N];
int c[N][N], H[N][N], L[N], R[N];

int f(int a[], int n){
	stack<int> st;
	
	for (int i=1; i<=n; i++) {
		while (st.size() && a[st.top()]>a[i])
		{ R[st.top()]=i-1; st.pop(); }
		st.push(i);
	}
	while (st.size()) { R[st.top()]=n; st.pop(); }
	
	for (int i=n; i>=1; i--) {
		while (st.size() && a[st.top()]>a[i])
		{ L[st.top()]=i+1; st.pop(); }
		st.push(i);
	}
	while (st.size()) { L[st.top()]=1; st.pop(); }
	
	int Max=0;
	f1(i,n) Max = max(Max, a[i]*(R[i]-L[i]+1));
	return Max;
}

int g(int m, int n){
	if (m*n==0) return 0;
	f1(i,m) f1(j,n) H[i][j] = (c[i][j] ? H[i-1][j]+1 : 0);
	int Max=0;
	f1(i,m) Max = max(Max, f(H[i], n));
	return Max;
}

int h(int u, int v){
	int x1=max(1, 1-u), x2=min(m, m-u);
	int y1=max(1, 1-v), y2=min(n, n-v);
	for (int i=x1; i<=x2; i++)
	for (int j=y1; j<=y2; j++)	
	c[i-x1+1][j-y1+1] = abs(a[i][j]-b[i+u][j+v])<=k;
	return g(x2-x1+1, y2-y1+1);
}

main(){
	freopen("htab.inp", "r", stdin);
	freopen("htab.out", "w", stdout);
	
	scanf("%d%d%d", &m, &n, &k);
	f1(i,m) f1(j,n) scanf("%d", &a[i][j]);
	f1(i,m) f1(j,n) scanf("%d", &b[i][j]);
	
	int Max = 0;
	for (int i=-m; i<=m; i++)
	for (int j=-n; j<=n; j++)
	Max = max(Max, h(i, j));
	cout << Max << endl;
}
