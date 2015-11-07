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
#define mod 50515093
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
#define maxn 200005
int n, suml = 0, sumr = 0, resl[maxn], resr[maxn], a[maxn], MAX, vt = -1;
II P[maxn];

void solve(){

	freopen("in.txt", "r", stdin);

	while(cin >> n){
		vt = -1;
		suml = 0; sumr = 0;
		ms(resl, 0); ms(resr, 0); ms(a, 0);

		bool dao = false;
		MAX = 0;
		For(i, 1, n){
			cin >> P[i].fi >> P[i].se;
			suml += P[i].fi;
			sumr += P[i].se;
			if(P[i].fi + P[i].se > MAX){
				MAX = P[i].fi + P[i].se;
				vt = i;
			}
		}

		if(MAX >= suml && MAX >= sumr){
			resl[vt] = 0; resr[vt] = P[vt].fi;
			int runl = P[vt].fi, runr = 0;
			For(i, 1, n) if(i != vt){
				resl[i] = runl; resr[i] = runr;
				runl += P[i].fi; runr += P[i].se;
			}
			cout << MAX << endl;
//			For(i, 1, n) cout << resl[i] << " " << resr[i] << "\n";
			continue;
		}

		if(suml < sumr){
			dao = true;
			swap(suml, sumr);
			For(i, 1, n) swap(P[i].fi, P[i].se);
		}

		For(i, 1, n){
			if(i < n) a[i] = P[i].fi - P[i + 1].se;
			else a[i] = P[n].fi - P[1].se;
		}

		MAX = -1; int run = 0; vt = -1;
		Ford(i, n, 1){
			run += a[i];
			if(run > MAX){
				MAX = run;
				vt = i;
			}
		}

		int root = (vt - 1); if(!root) root = n;
		int u, v;
		int runl = 0, runr = 0;
		for(int i = vt;; i = (i % n) + 1){
			u = i; v = (i % n) + 1;
			resl[u] = runl; runl += P[u].fi;
			if(i != root){
				resr[v] = runr; runr += P[v].se;
			}
			else resr[v] = suml - P[v].se;
			if(i == root) break;
		}
		cout << suml << endl;
//		For(i, 1, n){
//			if(dao) cout << resr[i] << " " << resl[i] << "\n";
//			else cout << resl[i] << " " << resr[i] << "\n";
//		}
	}
}

string toString(int x){
	string res = "";
	res.pb(x / 10 + '0');
	res.pb(x % 10 + '0');
	return res;
}

void make(){
	freopen("in.txt", "w", stdout);
	For(i, 1, 34){
		freopen(("data/" + toString(i)).c_str(), "r", stdin);
		cin >> n;
		cout << n << "\n";
		For(j, 1, n) {
			cin >> P[j].fi >> P[j].se;
			cout << P[j].fi << " " << P[j].se << "\n";
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    make();
    solve();

    return 0;
}

