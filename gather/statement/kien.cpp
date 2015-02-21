#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=100005, oo=0x3c3c3c3c;
int n, Value[N], C[N], P[N], Pop;
vector<int> a[N], b[N];
long F[N], G[N];

void visit1(int u, int p) {
	C[u] = Value[u];
	for (int i=0; int v=a[u][i]; i++) if (v!=p) {
		F[u] += F[v] + 1LL*C[v]*b[u][i];
		C[u] += C[v];
	}
}

void visit2(int u, int p) {
	long Sum = G[u];
	for (int i=0; int v=a[u][i]; i++) if (v!=p)
		Sum += F[v] + 1LL*b[u][i]*C[v];
	for (int i=0; int v=a[u][i]; i++) if (v!=p)
		G[v] = Sum - (F[v] + 1LL*b[u][i]*C[v]) + 1LL*(Pop-C[v])*b[u][i];
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &Value[i]);
		Pop += Value[i];
	}
	for (int i=1; i<=n-1; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(y);
		a[y].push_back(x);
		b[x].push_back(z);
		b[y].push_back(z);
	}
	for (int i=1; i<=n; i++)
		a[i].push_back(0);

	vector<int> Topo;
	Topo.push_back(1); P[1]=1;
	for (int j=0; j<Topo.size();j++) {
		int u = Topo[j];
		for (int i=0; int v=a[u][i]; i++) if (v!=P[u])
		{ Topo.push_back(v); P[v]=u; }
	}

	for (int i=n-1; i>=0; i--)
		visit1(Topo[i], P[Topo[i]]);
	for (int i=0; i<=n-1; i++)
		visit2(Topo[i], P[Topo[i]]);
	/*for (int i=1; i<=n; i++) printf("%d ", F[i]); printf("F:%d\n", n);
	for (int i=1; i<=n; i++) printf("%d ", G[i]); printf("G:%d\n", n);
	for (int i=1; i<=n; i++) printf("%d ", C[i]); printf("C:%d\n", n);
	for (int i=1; i<=n; i++) printf("%d ", P[i]); printf("P:%d\n", n);*/

	long Min = 1LL*oo*oo;
	for (int i=1; i<=n; i++)
		Min = min(Min, F[i] + G[i]);
	cout << Min << endl;
}
