#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
using namespace std;

const int maxn = 100005;
int n, c [maxn], child [maxn], schild;
vector <pair <int, int> > adj [maxn];
long long up [maxn], down [maxn], res = 1LL << 60;

void dfs (int u, int p) {
	child [u] = c [u];
	for (int i = 0; i < adj [u].size (); ++i) {
		int v = adj [u][i].first, w = adj [u][i].second;
		if (v == p) continue;
		dfs (v, u);
		child [u] += child [v];
		down [u] += down [v] + 1LL * child [v] * w;
	}
}

void dfs1 (int u, int p) {
	long long s = 0;
	for (int i = 0; i < adj [u].size (); ++i) {
		int v = adj [u][i].first, w = adj [u][i].second;
		if (v == p) continue;
		s += down [v] + 1LL * child [v] * w;
	}
	//cerr << u << " " << s << endl;
	for (int i = 0; i < adj [u].size (); ++i) {
		int v = adj [u][i].first, w = adj [u][i].second;
		if (v == p) continue;
		up [v] = up [u] + s - (down [v] + 1LL * child [v] * w) + w * (schild - child [v]);
		//cerr << v << " "<< s - 1LL * child [v] * w << endl;
		//cerr << up [v] << endl;
		dfs1 (v, u);
	}
}


int main (int ac, char **av) {	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c [i];
		schild += c [i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj [u].push_back (make_pair (v, w));
		adj [v].push_back (make_pair (u, w));
	}
	dfs (1, 0);
	dfs1 (1, 0);
//	for (int i = 1; i <= n; ++i) cerr << child [i] << " "; cerr << endl;
//	for (int i = 1; i <= n; ++i) cerr << down [i] << " "; cerr << endl;
//	for (int i = 1; i <= n; ++i) cerr << up [i] << " "; cerr << endl;
	for (int i = 1; i <= n; ++i) res = min (res, up [i] + down [i]);
	cout << res << endl;
	return 0;
}
