#include <stdio.h>
#include <assert.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define it(a) (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
#define all(a) a.begin(), a.end()
#define N 20004
const int oo = 0x3c3c3c3c;
int n, m, x[N], y[N], z[N];
char c[N];
int Num[N], Low[N], Color[N], Time=0; //
vector<int> Prime, a[N]; //

inline int le(int u, int k) 
	{ return u*32+k+1; }
inline int ge(int u, int k)
	{ return N-le(u, k-1); }
void edge(int u, int v) {
	a[u].push_back(v);
	a[N-v].push_back(N-u);
}

stack<int> st;

void visit(int u) {
	Num[u]=Low[u]=++Time; 
	st.push(u);
	for it(a[u]) { int v=*it;
		if (Num[v]) Low[u]=min(Low[u], Num[v]);
		else { visit(v); Low[u]=min(Low[u], Low[v]); }
	}
	if (Low[u]==Num[u]) { int v;
		Color[u]=++Time;
		do {
			v=st.top(); st.pop();
			Color[v]=Color[u];
			Num[v]=Low[v]=oo;
		} while (v!=u);
	}
}

int times(int n, int p) {
	int c=0;
	while (n%p==0) 
	{ c++; n/=p; }
	return c;
}

bool solve(int p) {
	for (int i=0; i<n; i++)
	for (int j=0; j<31; j++) {
		int u=le(i, j);
		Num[u]=Low[u]=Color[u]=0;
		Num[N-u]=Low[N-u]=Color[N-u]=0;
		a[u].clear();
		a[N-u].clear();
	}
	for (int i=0; i<n; i++)
		for (int j=0; j+1<31; j++)
		edge(le(i, j), le(i, j+1));
	for (int i=1; i<=m; i++) {
		int k = times(z[i], p);
		if (c[i]=='G') {
			if (k!=0) {
				edge(N-ge(x[i], k), ge(x[i], k));
				edge(N-ge(y[i], k), ge(y[i], k));
			}
			if (k+1<=31) {
				edge(ge(x[i], k+1), le(y[i], k));
				edge(ge(y[i], k+1), le(x[i], k));
			}
		} else {
			if (k!=31) {
				edge(N-le(x[i], k), le(x[i], k));
				edge(N-le(y[i], k), le(y[i], k));
			}
			if (k-1>=0) {
				edge(le(x[i], k-1), ge(y[i], k));
				edge(le(y[i], k-1), ge(x[i], k));
			}
		}
	}
	for (int i=0; i<n; i++)
	for (int j=0; j<31; j++) {
		int u=le(i, j);
		if (Num[u]==0) visit(u);
		if (Num[N-u]==0) visit(N-u);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<31; j++)
		if (Color[le(i, j)]==Color[N-le(i, j)])
		return false;
	}
	return true;
}

main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf(" %c%d%d%d", &c[i], &x[i], &y[i], &z[i]);
	for (int i=1; i<=m; i++) {
		int t = z[i];
		for (int j=2; j*j<=t; j++)
		while (t%j==0) {
			Prime.push_back(j);
			t/=j;
		}
		if (t!=1) Prime.push_back(t);
	}
	sort(all(Prime));
	Prime.erase(unique(all(Prime)), Prime.end());
	
	bool All = true;
	for it(Prime) {
		All &= solve(*it);
		if (!All) break;
	}
	if (All) cout << "Solution exists" << endl;
	else cout << "Solution does not exist" << endl;
}
