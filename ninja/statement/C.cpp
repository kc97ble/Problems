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


const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
    if (rsz <= 0) {
        ptr = 0;
        rsz = (int) fread(bf, 1, bfsz, stdin);
        if (rsz <= 0)
            return EOF;
    }
    --rsz;
    return bf[ptr++];
}
void ga(char &c) {
    c = EOF;
    while (!isalpha(c))
        c = gc();
}
int gs(char s[]) {
    int l = 0;
    char c = gc();
    while (isspace(c))
        c = gc();
    while (c != EOF && !isspace(c)) {
        s[l++] = c;
        c = gc();
    }
    s[l] = '\0';
    return l;
}
template<class T> bool gi(T &v) {
    v = 0;
    char c = gc();
    while (c != EOF && c != '-' && !isdigit(c))
        c = gc();
    if (c == EOF)
        return false;
    bool neg = c == '-';
    if (neg)
        c = gc();
    while (isdigit(c)) {
        v = v * 10 + c - '0';
        c = gc();
    }
    if (neg)
        v = -v;
    return true;
}

#define maxn 1005
#define maxv 1005
#define maxe 500005

struct HopcroftKarp {
    int nx, ny, E, adj[maxe], next[maxe], last[maxv], run[maxv], level[maxv], que[maxv], matx[maxv], maty[maxv];

    void init(int _nx, int _ny) {
        nx = _nx; ny = _ny;
        E = 0; ms(last, -1);
        ms(matx, -1); ms(maty, -1);
    }

    void add(int x, int y) {
        adj[E] = y; next[E] = last[x]; last[x] = E++;
    }

    bool bfs() {
        int qsize = 0;

        For(x, 1, nx) if (matx[x] != -1) level[x] = -1;
        else {
            level[x] = 0;
            que[qsize++] = x;
        }

        bool found = false;

        Rep(i, qsize) {
            for (int x = que[i], e = last[x]; e != -1; e = next[e]) {
                int y = adj[e];
                if (maty[y] == -1) found = true;
                else if (level[maty[y]] == -1) {
                    level[maty[y]] = level[x] + 1;
                    que[qsize++] = maty[y];
                }
            }
        }

        return found;
    }

    int dfs(int x) {
        for (int &e = run[x]; e != -1; e = next[e]) {
            int y = adj[e];
            if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }

    int maxmat() {
        int total = 0;

        while (bfs()) {
            For(x, 1, nx) run[x] = last[x];
            For(x, 1, nx) if (matx[x] == -1) total += dfs(x);
        }

        return total;
    }
} hopkarp;

int n, m, adj[maxe], last[maxn], next[maxe], E, flag[maxn], a[maxn][maxn], color[maxn], from[maxn * 10], to[maxn * 10];
int adj1[maxe], last1[maxn], next1[maxe];
vector<int> V;
int test, num;

void dfs1(int u){
	flag[u] = 1;
	for(int e = last[u]; e != -1; e = next[e]){
		int v = adj[e];
		if(!flag[v]) dfs1(v);
	}
	V.pb(u);
}

void dfs2(int u){
	flag[u] = num;
	for(int e = last1[u]; e != -1; e = next1[e]){
		int v = adj1[e];
		if(!flag[v]) dfs2(v);
	}
}

void dfs3(int id, int u){
	if(id != u) hopkarp.add(id, u);
	flag[u] = 1;
	for(int e = last[u]; e != -1; e = next[e]){
		int v = adj[e];
		if(!flag[v]) dfs3(id, v);
	}
}

void add(int u, int v){
	adj[E] = v; next[E] = last[u]; last[u] = E;
	adj1[E] = u; next1[E] = last1[v]; last1[v] = E++;
}

void solve(){
	freopen("in.txt", "r", stdin);

	gi(test);
	For(itest, 1, test){
		printf("Case %d: ", itest);
		gi(n); gi(m);
		E = 0;
		ms(last, -1); ms(last1, -1); ms(flag, 0); ms(color, 0);

		Rep(i, m){
			gi(from[i]); gi(to[i]);
			add(from[i], to[i]);
		}

		V.clear();
		For(i, 1, n) if(!flag[i]) dfs1(i);
		ms(flag, 0); num = 0;
		For(i, 1, n) if(!flag[V[n - i]]){
			num++;
			dfs2(V[n - i]);
		}

		hopkarp.init(num, num);

		E = 0; ms(last, -1); ms(a, 0);
		Rep(i, m) if(flag[from[i]] != flag[to[i]] && !a[flag[from[i]]][flag[to[i]]]){
			add(flag[from[i]], flag[to[i]]);
			a[flag[from[i]]][flag[to[i]]] = 1;
		}

		For(i, 1, num){
			ms(flag, 0);
			dfs3(i, i);
		}

		cout << num - hopkarp.maxmat() << endl;
	}
}

int main(){

	solve();
    return 0;

}



