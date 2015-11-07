#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;
int n, m, Xor[N], Diff[N];
int L[N], R[N];
int Visited[N], Color[N];
vector<int> a[N];

bool visit(int u, int m, int c) {
	if (Visited[u]==m) return Color[u]==c;
	Visited[u]=m; Color[u]=c;
	
	for (int i=0; i<a[u].size(); i++) {
		int k=a[u][i], v=u^Xor[k];
		if (k<=m && !visit(v, m, c^Diff[k]))
		return false;
	}
	return true;
}

bool ok(int m) {
	for (int i=1; i<=n; i++)
	if (Visited[i]!=m && !visit(i, m, 0))
	return false;
	return true;
}

main() {
//	freopen("games.inp", "r", stdin);
//	freopen("games.out", "w", stdout);
	
	#define all(a) a.begin(), a.end()
	vector<int> Pos;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) {
		char s[10]; scanf("%d%d%s", &L[i], &R[i], s);
		Diff[i] = (s[0]=='o' || s[0]=='1');
		Pos.push_back(--L[i]);
		Pos.push_back(R[i]);
	}
	sort(all(Pos)); Pos.erase(unique(all(Pos)), Pos.end());
	n=Pos.size();
	for (int i=1; i<=m; i++) {
		L[i] = lower_bound(all(Pos), L[i]) - Pos.begin() + 1;
		R[i] = lower_bound(all(Pos), R[i]) - Pos.begin() + 1;
		a[L[i]].push_back(i);
		a[R[i]].push_back(i);
		Xor[i] = L[i] ^ R[i];
	}
	
	/*for (int i=1; i<=m; i++) {
		int x, y; char s[10];
		scanf("%d%d%s", &x, &y, s);
		a[x-1].push_back(i);
		a[y].push_back(i);
		Xor[i] = (x-1)^y;
		Diff[i] = (s[0]=='o');
	}*/
	int ll=1, rr=m, mm=(ll+rr)/2;
	while (ll!=rr) {
		if (ok(mm)) ll=mm; else rr=mm-1;
		mm=(ll+rr+1)/2;
	}
	cout << mm << endl;
}
