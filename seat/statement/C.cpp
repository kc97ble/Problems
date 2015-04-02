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
#define mod 100000007
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

#define maxn 1000005

ll fact[maxn], inv[maxn], mu2[maxn];
int n = 1000000;
//int n = 1000;

ll mu(ll x, ll k){
	if(k == 0) return 1;
	if(k & 1) return mu(x, k - 1) * x % mod;
	ll t = mu(x, k >> 1);
	return t * t % mod;
}

void solve(){
    ll res = 0;
    Rep(mask, 4){
    	int t = getbit(mask, 0) + getbit(mask, 1);
    	int num = n - t - 1;
    	for(int n3 = 0; n3 * 3 <= num; n3++) if((num - n3 * 3) % 2 == 0){
    		int n2 = (num - n3 * 3) / 2;
    		int A = n2 + n3 + 1;
    		int B = t + n3;
    		int C = n2 + n3;
    		ll ret = fact[A] * fact[B] % mod * fact[C] % mod;
    		ret = ret * fact[n2 + n3] % mod * inv[n2] % mod * inv[n3] % mod;
    		ret = ret * mu2[n3] % mod;
    		res = (res + ret) % mod;
    	}
    }
    cout << res << endl;
}

void sol(){
    fact[0] = 1; inv[0] = 1; mu2[0] = 1;
    For(i, 1, maxn - 1) {
    	fact[i] = fact[i - 1] * i % mod;
    	inv[i] = mu(fact[i], mod - 2);
    	mu2[i] = mu2[i - 1] * 2 % mod;
    }

    while(cin >> n){
    	solve();
    }
}

void gen(){
	freopen("in.txt", "w", stdout);
	Rep(run, 20){
		n = (rand() % 1000) * 1000 + rand() % 1000 + 1;
		cout << n << endl;
	}
}

int main(){

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(NULL));
//    gen();
    sol();

    return 0;
}
