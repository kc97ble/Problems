#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5003, oo = 0x3c3c3c3c;
int n, L[N], R[N], Value[N], Child[N];
int F[N][N];
bool FF[N][N];
vector<int> a[N];
#define return(Result) return F[u][x] = (Result)

inline int f(int u, int x) {
	if (FF[u][x]++) return F[u][x];
	if (L[u]==0)
		return (x<=1 ? abs(Value[u]-x) : oo);
	if (R[u]==0)
		return (f(L[u], x) + abs(Value[u]-x));
	int Min = oo;
	for (int i=max(0, x-Child[R[u]]); i<=x && i<=Child[L[u]]; i++)
	if (x-i<=Child[R[u]])
	Min = min(Min, f(L[u], i) + f(R[u], x-i) + abs(Value[u]-x));
	return (Min);
}

void visit(int u, int p) {
	for (int v: a[u]) if (v!=p) {
		(L[u] ? R[u] : L[u]) = v;
		visit(v, u);
		Child[u] += Child[v];
	}
	if (Child[u]==0) Child[u]=1;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d", &Value[i]);
	for (int i=1; i<=n-1; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	visit(1, 0);

	int Min = oo;
	for (int i=0; i<=Child[1]; i++)
	Min = min(Min, f(1, i));
	cout << Min << endl;
}

