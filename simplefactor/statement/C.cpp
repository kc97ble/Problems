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

ll f[maxn][16], mu3[16];
bool isprime[maxn];
int n;

void solve(){
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	ms(f, 0);
	ms(isprime, 1);
	isprime[1] = 0;
	for(int i = 2; i * i < maxn; i++) if(isprime[i]){
		for(int j = i * i; j < maxn; j += i) isprime[j] = 0;
	}

	mu3[1] = 1; for(int i = 2; i < 16; i++) mu3[i] = mu3[i - 1] * 3;
	for(int i = 0; i < 16; i++) f[0][i] = 1;
	for(int i = 1; i < maxn; i++){
		for(int j = 1; j < 16; j++){
			if(i & 1){
				f[i][j] = f[i][j - 1];
				if(i >= mu3[j]) f[i][j] += f[i - mu3[j]][j - 1];
				if(f[i][j] > 1) f[i][j] = 2;
			} else f[i][j] = f[i >> 1][j];
		}
	}

	while(cin >> n){
		ll res = 0;
		for(int i = 2; i < n; i++) if(isprime[i] && f[i][15] == 1){
			res += i;
		}
		cout << res << endl;
	}
}

void gen(){
	freopen("in.txt", "w", stdout);
	Rep(run, 20){
		n = rand() % 1000 * 2000 + rand() % 2000 + 1;
		cout << n << endl;
	}
}

int main(){

	solve();
//	gen();

    return 0;
}
