#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define mod 1000000007

ll giaithua[105], inv[105], f[105][105][11], d[105][11], G[105], F[105];

class DengklekCountingFormations { 
	public: 
	int numFormations(int n, int m, int k) {
		init(n, m, k);
		F[0] = 1;
		F[1] = G[1];
//		cout << F[1] << endl;
		for(int i = 2; i <= n; i++){
			F[i] = 0;
			for(int j = 1; j <= i; j++){
				ll A = F[i - j] * G[j] % mod;
				if(j & 1) add(F[i], A);
				else add(F[i], mod - A);
			}
			F[i] = F[i] * mu(i, mod - 2) % mod;
//			cout << i << " " << F[i] << endl;
		}
		return F[n] * giaithua[n] % mod;
	} 
	
	void init(int n, int m, int k){
		giaithua[0] = 1;
		inv[0] = 1;
		for(int j = 1; j < 11; j++) d[0][j] = 1;
		for(int i = 1; i < 105; i++) {
			giaithua[i] = giaithua[i - 1] * i % mod;
			inv[i] = mu(giaithua[i], mod - 2);
			d[i][1] = inv[i];
			for(int j = 2; j < 11; j++) d[i][j] = d[i][j - 1] * inv[i] % mod;
		}

		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) f[0][0][i] = 1;
		G[0] = 1;
		for(int t = 1; t <= n; t++){
			for(int i = 1; i <= k; i++) for(int j = 0; j <= m; j++) for(int l = 0; l <= j; l++){
				add(f[i][j][t], f[i - 1][l][t] * d[j - l][t] % mod);
			}
			G[t] = f[k][m][t] * mu(giaithua[m], t) % mod;
//			cout << t << " " << G[t] << endl;
		}

	}

	void add(ll &x, ll y){
		x += y;
		if(x >= mod) x -= mod;
	}

	ll mu(ll x, ll k){
		if(k == 0) return 1;
		if(k & 1) return mu(x, k - 1) * x % mod;
		ll t = mu(x, k >> 1);
		return t * t % mod;
	}

 
};

int main(){
	freopen("in.txt", "r", stdin);
	DengklekCountingFormations X;
	int a, b, c;
	while(cin >> a >> b >> c){
		cout << X.numFormations(a, b, c) << endl;
	}
}
