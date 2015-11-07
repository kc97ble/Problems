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

ll n = 1000000000;
//ll n = 100;
#define maxn 10005

bool have[10005][10005];

void init(){
	ms(have, 0);
	for(int i = 1; i < maxn; i++) for(int j = i; j <= maxn; j++) if(!have[i][j]){
		for(int u = i + i, v = j + j; v <= maxn; u += i, v += j){
			have[u][v] = 1;
		}
	}
}

void solve(){
	freopen("in.txt", "r", stdin);

	init();

	while(cin >> n){
		int d = (int)(sqrt(n + 0.5));
		ll res = 0;
		for(ll i = 1; i <= d; i++) for(ll j = i; j <= d; j++) if(!have[i][j]){
			ll A = (i + j) * (i + j), B = j * j;
			ll C = i * i * j * j +  (i * i + j * j) * (i * i + j * j + 2 * i * j);
			ll d = n / A / B;
	//    	cout << i << " " << j << " " << d << endl;
			res += C * (d) * (d + 1) / 2;
		}
		cout << res << endl;
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
//    cout << clock() << endl;

    return 0;
}

