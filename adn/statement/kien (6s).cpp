#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define X first
#define Y second

const int oo = 0x3c3c3c3c;

struct powerful_set {
	vector<ii> List;
	vector<int> Actual;
	
	inline int actual(int u) 
		{ return Actual[u]==u ? u : Actual[u]=actual(Actual[u]); }
	
	void assign(const vector<ii> &AList, bool Sorted=false, bool Changed=true) {
		if (Changed) List = AList;
		if (!Sorted) sort(List.begin(), List.end());
		Actual.resize(List.size()+1);
		for (int i=0; i<Actual.size(); i++)
		Actual[i] = i;
	}
	
	#define all(a) a.begin(), a.end()
	inline void erase(int L, int R) {
		int x = actual(R);
		for (int i=L; i!=R; i=actual(i+1))
		Actual[i] = actual(i+1);
	}
	
	inline int lower_bound(int x) { 
		int i = ::lower_bound(all(List), ii(x, -oo)) - List.begin();
		return actual(i);
	}
	
	inline int upper_bound(int x) { 
		int i = ::upper_bound(all(List), ii(x, +oo)) - List.begin();
		return actual(i);
	}
};

const int N = 100005;
int n, m, D;
vector<ii> a[N];
powerful_set Set[N];

int bfs(int S, int T) {
	if (S==T) return 0;
	queue<iii> qu;
	for (ii w: a[S]) qu.emplace(1, w);
	Set[S].erase(0, Set[S].List.size());
	
	while (qu.size()) {
		iii w = qu.front(); qu.pop();
		int du=w.X, u=w.Y.Y, x=w.Y.X;
		if (u==T) return du;
		
		int L = Set[u].lower_bound(x-D);
		int R = Set[u].upper_bound(x+D);
		for (int i=L; i!=R; i=Set[u].actual(i+1))
		qu.emplace(du+1, Set[u].List[i]);
		Set[u].erase(L, R);
	}
	return -1;
}

main() {
	scanf("%d%d%d", &n, &m, &D);
	for (int i=1; i<=m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].emplace_back(z, y);
		a[y].emplace_back(z, x);
	}
	for (int i=1; i<=n; i++)
		sort(all(a[i]));
	int q; scanf("%d", &q);
	for (int k=1; k<=q; k++) {
		for (int i=1; i<=n; i++)
		Set[i].assign(a[i], true, k==1);
		int x, y; scanf("%d%d", &x, &y);
		cout << bfs(x, y) << endl;
	}
}

