#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000000
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)
#define linf (ll)(1e18 + 5)
#define maxv 10005
#define maxe 100005
int dr[4] = {-1, +1, 0, 0};
int dc[4] = {0, 0, +1, -1};

struct MincostFlow {
    int n, s, t, E, adj[maxe], next[maxe], last[maxv], which[maxv];
    ll totalCost, totalFlow, cap[maxe], flow[maxe], cost[maxe], pot[maxe], dist[maxv];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        ms(cap, 0); ms(pot, 0); ms(dist, 0); ms(which, 0);
        ms(last, -1); E = 0;
    }

    void add(int u, int v, ll ca, ll co) {
        adj[E] = v; cap[E] = ca; flow[E] = 0; cost[E] = +co; next[E] = last[u]; last[u] = E++;
        adj[E] = u; cap[E] =  0; flow[E] = 0; cost[E] = -co; next[E] = last[v]; last[v] = E++;
    }

    void bellman() {
        bool stop = false;
        ms(pot, 0);

        while (!stop) {
            stop = true;
            Rep(u, n) for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
                int v = adj[e];
                if (pot[v] > pot[u] + cost[e]) {
                    pot[v] = pot[u] + cost[e];
                    stop = false;
                }
            }
        }
    }

    bool dijkstra() {
        typedef pair<ll, int> node;
        priority_queue<node, vector<node>, greater<node> > que;

        Rep(u, n) dist[u] = linf;
        dist[s] = 0;
        que.push(mp(0, s));

        while (!que.empty()) {
            ll dnow = que.top().fi;
            int u = que.top().se;
            que.pop();

            if (dnow > dist[u]) continue;

            for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
                int v = adj[e];
                ll dnext = dnow + cost[e] + pot[u] - pot[v];

                if (dist[v] > dnext) {
                    dist[v] = dnext;
                    which[v] = e;
                    que.push(mp(dnext, v));
                }
            }
        }

        return dist[t] < linf;
    }

    bool maxflow(ll desireFlow = linf) {
        totalCost = totalFlow = 0;
        bellman();

        while (totalFlow < desireFlow) {
            if (!dijkstra()) return false;

            ll delta = desireFlow - totalFlow;
            for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v])
                delta = min(delta, cap[e] - flow[e]);

            for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v]) {
                flow[e] += delta;
                flow[e ^ 1] -= delta;
            }

            totalFlow += delta;
            totalCost += delta * (dist[t] - pot[s] + pot[t]);

            Rep(u, n) pot[u] += dist[u];
        }

        return true;
    }
} mcf;

int n, m, k, a[105][105];

bool inside(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}

int cal(int r, int c, int id){
    return (r * m + c) * 2 + id;
}


void solve(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	while(cin >> n >> m >> k){
		Rep(i, n) Rep(j, m) cin >> a[i][j];

		int num = n * m * 2;
		mcf.init(num + 4, num, num + 1);
		mcf.add(num, num + 2, k, 0);
		mcf.add(num + 3, num + 1, k, 0);

		Rep(i, n) Rep(j, m) {
			mcf.add(cal(i, j, 0), cal(i, j, 1), 1, 0);
			if((i + j) & 1){
				mcf.add(num + 2, cal(i, j, 0), 1, 0);
				Rep(h, 4){
					int r = i + dr[h], c = j + dc[h];
					if(inside(r, c)){
						mcf.add(cal(i, j, 1), cal(r, c, 0), 1, -a[i][j] * a[r][c]);
					}
				}
			}
			else{
				mcf.add(cal(i, j, 1), num + 3, 1, 0);
			}
		}

		mcf.maxflow();
		cout << -mcf.totalCost << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    gen();

    solve();

    return 0;
}
