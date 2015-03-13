#include <cstdio>
#include <vector>
#include <climits>
#include <set>

using namespace std;

#define fi first
#define se second
#define pb push_back

#define INF INT_MAX
#define N_MAX 100000 + 10
#define REP(i, n) for( int i = 0, _n = (n); i < _n; ++i )
#define TR(v, it) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; ++it )

typedef pair <int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

//---------------------------------------------------------------------------------------------------------------------------------
int n, c[N_MAX];
vvii g;
//---------------------------------------------------------------------------------------------------------------------------------

void input() {
	scanf( "%d", &n );
	REP(i, n) scanf( "%d", &c[i] );
	int u, v, l;
	g.resize(n);
	REP(i, n-1) {
		scanf( "%d %d %d", &u, &v, &l );
		--u; --v;
		g[u].push_back(ii(v,l));
		g[v].push_back(ii(u,l));
	}
}

void dijkstra( vvii & g, int d[], int x ) {
	int du, u, v, l;
	set<ii> f; f.clear(); f.insert(ii(0,x));
	REP(i,n) d[i] = INF; d[x] = 0;
	while (!f.empty()) {
		du = f.begin()->fi; u = f.begin()->se;
		f.erase(f.begin());
		if ( du > d[u] ) continue;
		TR( g[u], it ) {
			v = it->fi, l = it->se;
			if ( du + l < d[v] ) {
				d[v] = du + l;
				f.insert( ii( d[v], v ) );
			}
		}
	}
}

void solve() {
	int d[N_MAX];
	int res = INF, sum;
	REP(x, n-1) {
		sum = 0;
		dijkstra( g, d, x );
		REP(i, n) sum += (c[i] * d[i]);
		if ( sum < res ) res = sum;
	}
	printf( "%d\n", res );
}

int main() {
	input();
	solve();
    return 0;
}
