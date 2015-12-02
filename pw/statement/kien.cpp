#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
const int N = 200005;
int n, m, k;
vector<ii> a1[N], a2[N];
int Max[4*N], Inc[4*N], Best[4*N];

struct node {
	int ll, rr, id;
	node(int L, int R, int X)
		{ ll=L, rr=R, id=X; access(); }
	node left()
		{ return node(ll, (ll+rr)/2, id*2); }
	node right()
		{ return node((ll+rr)/2+1, rr, id*2+1); }
	void access() {
		if (Inc[id]==0) return ;
		if (ll!=rr) {
			Inc[id*2] += Inc[id];
			Inc[id*2+1] += Inc[id];
		}
		Max[id] += Inc[id];
		Inc[id] = 0;
	}
	
	void increase_range(int L, int R, int X) {
		if (L>rr || ll>R || L>R) return ;
		if (L<=ll && rr<=R) { Inc[id]+=X; access(); return ; }
		left().increase_range(L, R, X);
		right().increase_range(L, R, X);
		Max[id] = max(Max[id*2], Max[id*2+1]);
		Best[id] = Max[id*2] >= Max[id*2+1] ? Best[id*2] : Best[id*2+1];
	}
	
	void init() {
		Best[id]=ll;
		if (ll==rr) return ;
		left().init();
		right().init();
	}
};

void updates(vector<ii> &T, int k) {
	for (int i=0; i<T.size(); i++)
	node(1, n, 1).increase_range(T[i].first, T[i].second, k);
}

main() {
	//freopen("pw.inp", "r", stdin);
	//freopen("pw.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	node(1, n, 1).init();
	for (int i=1; i<=m; i++) {
		int x, y, u, v;
		scanf("%d%d%d%d", &x, &y, &u, &v);
		x=max(1, x-(k-1)); u=min(u, n-(k-1));
		y=max(1, y-(k-1)); v=min(v, n-(k-1));
		
		a1[x].push_back(ii(y, v));
		a2[u+1].push_back(ii(y, v));
	}
	int Max=-1, dx=0, dy=0;
	for (int i=0; i<N; i++) 
	if (a1[i].size() || a2[i].size()) {
		updates(a1[i], +1);
		updates(a2[i], -1);
		if (Max < ::Max[1]) {
			Max = ::Max[1];
			dx=i, dy=Best[1];	
		}
	}
	cout << Max << endl;
	cout << dx << " " << dy << endl;
}

