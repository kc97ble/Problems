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

#define maxn 2005

ll C[maxn][maxn];
int n, k;

void solve(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ms(C, 0);
	Rep(i, maxn) C[0][i] = 1;
	for(int i = 1; i < maxn; i++) for(int j = 1; j <= i; j++) C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % mod;

	while(cin >> n >> k){
		ll res = 0;
		for(int i = 0; i <= n; i++) for(int j = 0; j <= i; j++){
			if(i - j <= k && i - j <= n - i){
				res = (res + C[j][i] * C[i - j][n - i]) % mod;
			}
		}
		cout << res << endl;
	}
}

void gen(){
	freopen("in.txt", "w", stdout);
	Rep(run, 20){
		cout << rand() % 1000 + 1 << " " << rand() % 1000 + 1 << endl;
	}
}

int main(){

	solve();
//	gen();

    return 0;
}
