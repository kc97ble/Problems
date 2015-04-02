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
#define mod 10007
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

#define maxn 70005

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
int somu[] = {9, 6, 4, 4, 3, 3, 3, 3};

int f[maxn][2];
int n, a[maxn];
vector<int> V[505];
int mu[11][11];
int d[11];
vector<int> T[maxn];

int calP(int n2, int n3, int n5, int n7, int n11, int n13, int n17, int n19){
	return n2 * d[1] + n3 * d[2] + n5 * d[3] + n7 * d[4] + n11 * d[5] + n13 * d[6]
				+ n17 * d[7] + n19 * d[8];
}

vector<int> calV(int x){
	vector<int> res;
	for(int i = 1; i <= 8; i++){
		res.pb(x / d[i]);
		x %= d[i];
	}
	return res;
}

bool isprime(int x){
	for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
	return true;
}

void add(int &x, int y){
	x += y;
	if(x >= mod) x -= mod;
}

void solve(){
	Rep(i, 505) V[i].clear();
	ms(f, 0);
	For(i, 1, n) cin >> a[i];
	For(i, 1, n){
		bool flag = false;
		for(int j = 20; j <= 500; j++) if(isprime(j) && a[i] % j == 0){
			flag = true;
			V[j].pb(a[i] / j);
			break;
		}
		if(!flag) V[1].pb(a[i]);
	}

	f[0][0] = 1;
	for(int i = 1; i <= 500; i++) if(sz(V[i])){
		for(int j = 0; j < sz(V[i]); j++){
			int u = V[i][j];
			int r[8]; ms(r, 0);
			for(int k = 0; k < 8; k++){
				while(u % prime[k] == 0){
					u /= prime[k];
					r[k]++;
				}
			}
			for(int t = d[0] - 1; t >= 0; t--) for(int k = 1; k >= 0; k--) if(f[t][k]){
				int ret = 1, rr[8];
				Rep(h, 8){
					int A = max(0, r[h] - T[t][h]);
					rr[h] = max(r[h], T[t][h]);
					ret = ret * mu[h][A] % mod;
				}
				if(!k) ret = ret * i % mod;
				int A = calP(rr[0], rr[1], rr[2], rr[3], rr[4], rr[5], rr[6], rr[7]);
				add(f[A][1], ret * f[t][k] % mod);
			}
		}
		Rep(j, d[0]){
			add(f[j][0], f[j][1]);
			f[j][1] = 0;
		}
	}

	int res = 0;
	Rep(i, d[0]){
		add(res, f[i][0]);
	}
	cout << (res + mod - 1) % mod << endl;
}

void sol(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    ms(mu, 0);
    for(int i = 0; i < 8; i++){
    	mu[i][0] = 1;
    	for(int j = 1; j < 11; j++) mu[i][j] = mu[i][j - 1] * prime[i] % mod;
    }
    d[8] = 1; for(int i = 7; i >= 0; i--) d[i] = d[i + 1] * somu[i];
    Rep(i, d[0]){
    	T[i] = calV(i);
    }
    while(cin >> n){
    	solve();
    }
}

bool flag[555];
void gen(){
	freopen("in.txt", "w", stdout);

	Rep(run, 20){
		ms(flag, 0);
		n = rand() % ((run + 1) * 5) + 1;
		For(i, 1, n){
			while(true){
				a[i] = rand() % ((run + 1) * 25) + 1;
				if(!flag[a[i]]){
					flag[a[i]] = 1;
					break;
				}
			}
		}
		cout << n << endl;
		For(i, 1, n) cout << a[i] << " "; cout << endl;
	}
}

int main(){
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    gen();
    sol();
//    cout << clock() << endl;

    return 0;
}

