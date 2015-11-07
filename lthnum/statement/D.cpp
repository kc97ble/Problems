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
#define mod 1000000123
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

#define maxn 100005

struct matrix{
	ll x[12][12];
	matrix() {ms(x, 0);}

	matrix operator +(matrix A){
		matrix res;
		for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++){
			res.x[i][j] = (x[i][j] + A.x[i][j]) % mod;
		}
		return res;
	}

	matrix operator *(matrix A){
		matrix res;
		for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++) for(int k = 0; k < 12; k++){
			res.x[i][j] = (res.x[i][j] + x[i][k] * A.x[k][j]) % mod;
		}
		return res;
	}

	matrix operator ^(ll k){
		matrix res, mu;
		k--;
		for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++){
			res.x[i][j] = x[i][j];
			mu.x[i][j] = x[i][j];
		}

		while(k){
			if(k & 1) res = res * mu;
			mu = mu * mu;
			k >>= 1;
		}

		return res;
	}
};

ll C[12][12];

matrix process(matrix I, ll num){
	if(num == 1) return I;
	if(num & 1) return (I ^ num) + process(I, num - 1);
	ll m = (num >> 1);
	matrix A = process(I, m);
	return A + (A * (I ^ m));
}

ll call(ll n, int id){
	if(n == 0) return 0;
	ll res = 0;
	for(int i = 0; i <= 5; i++){
		matrix I;
		for(int j = 0; j <= i + 5; j++){
			if(j < i + 5) I.x[j][j + 1] = i + 5 - j;
			if(j) I.x[j][j - 1] = j;
		}
		matrix A = process(I, n);
		res = (res + A.x[5 - id][5 + i] * C[i][5] % mod) % mod;
	}
	return res;
}

ll cal(ll n){
	return (call(n, 0) - call(n - 1, 1) + mod) % mod;
}

void solve(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ll n;

    ms(C, 0);
    Rep(i, 12) C[0][i] = 1;
    For(i, 1, 11) For(j, 1, i) C[j][i] = C[j - 1][i - 1] + C[j][i - 1];

	while(cin >> n){
		cout << cal(n) << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

//    cout << clock() << endl;

    return 0;

}
