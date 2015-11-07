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
//#define mod 1000000000
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
typedef double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 10000005

ll mu(ll x, ll k){
	if(k == 0) return 1;
	if(k & 1) return mu(x, k - 1) * x;
	ll t = mu(x, k >> 1);
	return t * t;
}

string str[18];

string calStr(ll x){
	string res = "";
	while(x){
		res.pb(x % 10 + '0');
		x /= 10;
	}
	reverse(all(res));
	return res;
}

ll N;
int a[20], n;
ll f[20][20][20][2];
bool can[22][22][10];
II next[22][22][10];

ll cal(int id, int vt, int len, bool behon){
	if(id == 0) return 1;
	ll &res = f[id][vt][len][behon];
	if(res != -1) return res;
	res = 0;
	int l = 0, r = a[id];
	if(behon) r = 9;
	for(int i = l; i <= r; i++){
		if(can[vt][len][i]){
			II P = next[vt][len][i];
			res += cal(id - 1, P.fi, P.se, behon | (i < a[id]));
		}
	}
	return res;
}

ll cal(ll x){
	n = 0;
	while(x){
		a[++n] = x % 10;
		x /= 10;
	}
	ms(f, -1);
	return cal(n, 0, 0, 0) - 1;
}

void init(){

    For(i, 1, 17){
    	str[i] = calStr(mu(11, i));
//    	cout << i << " " << mu(11, i) << endl;
    }

	ms(can, 1);
	For(i, 1, 17) Rep(j, sz(str[i]) - 1) Rep(k, 10){
		string tt = str[i].substr(0, j + 1) + char(k + '0');
		For(t, 1, 17) if(sz(tt) >= sz(str[t]) && tt.substr(sz(tt) - sz(str[t]), sz(str[t])).compare(str[t]) == 0){
			can[i][j][k] = 0;
		}
		next[i][j][k] = mp(0, 0);

		int RR = 0;
		For(t, 1, 17) For(len, 0, min(sz(str[t]), j + 2)) if(len > RR){
			if(tt.substr(sz(tt) - len, len).compare(str[t].substr(0, len)) == 0){
				RR = len;
				next[i][j][k] = mp(t, len - 1);
			}
		}
	}

	next[0][0][1] = mp(1, 0);
	next[0][0][2] = mp(8, 0);
	next[0][0][3] = mp(12, 0);
	next[0][0][4] = mp(15, 0);
	next[0][0][5] = mp(17, 0);
}

void solve(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	while(cin >> N){

		ll l = 1, r = N + N, mid;

		while(l < r){
			mid = (l + r) >> 1;
			if(cal(mid) >= N) r = mid;
			else l = mid + 1;
		}

		cout << l << endl;
	}
}

int main(){

	solve();

    return 0;
}
