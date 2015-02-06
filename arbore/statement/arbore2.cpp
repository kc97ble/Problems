//Hasna Robert
#include <cstdio>
#include <vector>

#define Nmax 100001
#define mod 666013

using namespace std;

vector<int> G[Nmax], G2[Nmax];
int N, v[Nmax], uz[Nmax], fact[Nmax], inv[Nmax];

int comb(int n, int k) {
	return (int)((long long)fact[n] * (long long)inv[n-k] * (long long)inv[k] % mod);
}

int getRez(int x) {
	if (v[x] == 1) return 1;
	int rez = 1;
	int nr = v[x] - 1;

	for (int i = 0; i < G[x].size(); ++i) {
		rez = ((long long)rez * (long long)comb(nr, v[G[x][i]] ) * (long long)getRez(G[x][i])) % mod;
		nr -= v[ G[x][i] ];
	}

	return rez;
}

int pow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	int temp = pow(a, b >> 1);
	temp = ((long long)temp * (long long)temp) % mod;
	if (b & 1) {	
		temp = ((long long)temp * (long long)a) % mod;
	}
	return temp;
}

void buildArbore(int x) {
	uz[x] = 1;
	for (int i = 0; i < G2[x].size(); ++i)
		if (!uz[G2[x][i]]) {
			G[x].push_back(G2[x][i]);
			buildArbore(G2[x][i]);
		}
}

void dfs(int x) {
	if (G[x].empty()) {
		v[x] = 1;
		return;
	}
	
	for (int i = 0; i < G[x].size(); ++i) {
		dfs(G[x][i]);
		v[x] += v[ G[x][i] ];
	}
	++v[x];
}


int main() {
	freopen("arbore.in", "r", stdin);
	freopen("arbore.out", "w", stdout);
	
	scanf("%d\n", &N);
	for (int i = 0; i < N-1; ++i) {
		int x, y;
		scanf("%d %d\n", &x, &y);
		G2[x].push_back(y);
		G2[y].push_back(x);
	}


	fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = ((long long)fact[i-1] * i) % mod;
	
	inv[0] = 1;
	for (int i = 1; i < N; ++i)
		inv[i] = pow(fact[i], mod - 2);


	buildArbore(1);
	dfs(1);
	printf("%d\n", getRez(1));
	return 0;
}

