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
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}
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

ll a[maxn];
int n;

ll sqr(ll x){
	return x * x;
}

void solve(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while(cin >> n){
		For(i, 1, n) cin >> a[i];
		sort(a + 1, a + n + 1);
		ld res = 0;
		For(i, 1, n){
			ld t = (i - 1) * (ld)(1.0) / sqr(a[i] * 2 + 1);
			res += t + t + 1;
		}
		cout << fixed << setprecision(6) << res << endl;
	}
}

void gen(){
	freopen("in.txt", "w", stdout);
	Rep(run, 20){
		n = rand() + 1;
		for(int i = 1; i <= n; i++){
			if(rand() % 2) a[i] = rand() % 100 + 1;
			else a[i] = rand() + 1;
		}
		cout << n << endl;
		For(i, 1, n) cout << a[i] << " "; cout << endl;
	}
}

int main(){

	solve();
//	gen();

    return 0;
}
