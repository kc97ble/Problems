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

ld f[20005], g[20005];
int n, k;

void solve(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(cin >> n >> k){
		ms(f, 0); ms(g, 0);
		f[0] = 1;
		if(n > k + k){
			cout << "1.000000" << endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j + j <= i; j++){
				g[j] = f[j];
				f[j] = 0;
			}
			for(int j = 0; j + j <= i; j++){
				int d = i - j - j;
				f[j] += g[j] * (k - d - j) * (ld)(1.0) / k;
				f[j + 1] += g[j] * (d) * (ld)(1.0) / k;
			}
		}
		ld res = 1;
		for(int i = 0; i + i <= n; i++) res -= f[i];
		cout << fixed << setprecision(6) << res << endl;
	}
}

void gen(){
	freopen("in.txt", "w", stdout);
	Rep(run, 20){
		n = rand() % 3000 + 2000;
		k = rand() % 1000 * 1000 + rand() % 1000 + 1;
		cout << n << " " << k << endl;
	}
}

int main(){

	solve();
//	gen();

    return 0;
}
