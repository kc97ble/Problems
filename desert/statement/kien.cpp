#include <bits/stdc++.h>
using namespace std;

#define long long long
typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 100005;
int n, x[N], y[N];
vector<ii> e;

namespace connection {
	map<int, int> Map;
	int l[N];
	
	bool by_y(int p, int q) 
		{ return y[p] > y[q]; }
	bool better(int u, int v)
		{ return y[u]-x[u] <= y[v]-x[v]; }
	
	void query(int u) {
		auto it = Map.upper_bound(x[u]+y[u]);
		if (it!=Map.begin()) it--; else return;
		e.emplace_back(u, it->second);
	}
	
	void update(int u) {
		auto it = Map.find(x[u]+y[u]);
		if (it!=Map.end()) {
			if (better(u, it->second))
			it->second = u;
		} else {
			it = Map.insert(ii(x[u]+y[u], u)).first;
			if (it!=Map.begin() && better(prev(it)->second, u))
				{ Map.erase(it); return; }
			while (next(it)!=Map.end() && better(u, next(it)->second))
				{ Map.erase(next(it)); }
		}
	}
	
	void connect() {
		Map.clear();
		for (int i=1; i<=n; i++) l[i]=i;
			sort(l+1, l+n+1, by_y);
		for (int i=1; i<=n; i++) {
			query(l[i]);
			update(l[i]);
		}
	}
}

long dist(int p, int q)
	{ return abs(x[p]-x[q]) + 0LL + abs(y[p]-y[q]); }
bool by_dist(ii a, ii b)
	{ return dist(a.X, a.Y) < dist(b.X, b.Y); }
	
struct djs {
	int P[N];
	djs()
		{ for (int i=0; i<N; i++) P[i]=i; }
	void join(int x, int y)
		{ x=at(x); y=at(y); P[x]=y; }
	int at(int x)
		{ return x==P[x] ? x : P[x]=at(P[x]); }
} Label;

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &x[i], &y[i]);
	
	for (int p=1; p<=2; p++) {
		for (int q=1; q<=2; q++) {
			for (int w=1; w<=2; w++) {
				connection :: connect();
				for (int i=1; i<=n; i++) swap(x[i], y[i]);
			}
			for (int i=1; i<=n; i++) x[i]=-x[i];
		}
		for (int i=1; i<=n; i++) y[i]=-y[i];
	}
	
	sort(e.begin(), e.end(), by_dist);
	for (ii t: e) {
		Label.join(t.X, t.Y);
		if (Label.at(1) == Label.at(n)) {
			cout << dist(t.X, t.Y) << endl;
			return 0;
		}
	}
}

