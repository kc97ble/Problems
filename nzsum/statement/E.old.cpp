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

#define maxn 2000005

struct matrix{
	ll x[18][18];
	matrix(){ms(x, 0);}
};

matrix mul(matrix A, matrix B){
	matrix res;
	for(int i = 0; i < 18; i++) for(int j = 0; j < 18; j++){
		for(int k = 0; k < 18; k++){
			res.x[i][j] = (res.x[i][j] + A.x[i][k] * B.x[k][j]) % mod;
		}
	}
	return res;
}

matrix mu(matrix A, ll k){
	if(k == 1) return A;
	if(k & 1) return mul(mu(A, k - 1), A);
	matrix T = mu(A, k >> 1);
	return mul(T, T);
}

ll a[10], f[10], hs[20];
ll n;

void solve(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	a[0] = 1; f[0] = 0;
	for(int i = 1; i < 10; i++){
		for(int j = 0; j < i; j++){
			a[i] = (a[i] + a[j]) % mod;
			f[i] = (f[i] + f[j] * 10 + (i - j) * a[j]) % mod;
		}
	}

	matrix I, A;
	for(int i = 0; i < 8; i++) I.x[i + 1][i] = 1;
	for(int i = 0; i < 9; i++) I.x[i][8] = 1;

	for(int i = 9; i < 17; i++) I.x[i + 1][i] = 1;
	for(int i = 0; i < 9; i++) I.x[i][17] = 9 - i;
	for(int i = 9; i < 18; i++) I.x[i][17] = 10;

	for(int i = 0; i < 18; i++){
		if(i < 9) hs[i] = a[i + 1];
		else hs[i] = f[i - 8];
	}

	while(cin >> n){

		if(n < 10) {
			cout << f[n] << endl;
			continue;
		}

		ll res = 0;
		A = mu(I, n);
		for(int j = 0; j < 18; j++) res = (res + hs[j] * A.x[j][17]) % mod;
		cout << res << endl;
	}

}

void gen(){
	//freopen("in.txt", "w", stdout);
	Rep(run, 20){
		ll res = 0;
		for(int i = 0; i < 15; i++) res = res * 10 + rand() % 10;
		res++;
		cout << res << endl;
	}
}

int main(){

	solve();
//	gen();

    return 0;
}
