#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> :: iterator iii_p;
typedef vector<int> :: iterator int_p;
#define X first
#define Y second

const int N = 100005;
int n, Color[N], P[20][N], Level[N];
int Anc[N], F[N];
vector<iii> List;
vector<int> a[N], With[N];

void previsit(int u, int p, int l) {
	P[0][u]=p; Level[u]=l;
	for (int i=0; int v=a[u][i]; i++)
	if (v!=p) previsit(v, u, l+1);
}

int lca(int x, int y) {
	#define k(x) P[k][x]
	for (int k=19; k>=0; k--) if (Level[k(x)] >= Level[y]) x=k(x);
	for (int k=19; k>=0; k--) if (Level[k(y)] >= Level[x]) y=k(y);
	for (int k=19; k>=0; k--) if (k(x)!=k(y)) x=k(x), y=k(y);
	while (x!=y) { x=P[0][x], y=P[0][y]; }
	return x;
}

void visit(int u, int p) {
	F[u] = Anc[u];
	for (int i=0; int v=a[u][i]; i++) if (v!=p) {
		visit(v, u);
		if (Level[F[v]]<Level[F[u]]) F[u] = F[v];
	}
}

main(){
	scanf("%d", &n); n-=2;
	for (int i=1; i<=n; i++) {
		int x, y, z;
		scanf("%d%d%d%d", &x, &y, &z, &Color[i]);
		With[Color[i]].push_back(i);
		#define push_iii(x, y, z) push_back(iii(ii(x, y), z))
		List.push_iii(min(x, y), max(x, y), i);
		List.push_iii(min(y, z), max(y, z), i);
		List.push_iii(min(z, x), max(z, x), i);
	}
	sort(List.begin(), List.end());
	for (iii_p it=List.begin()+1; it!=List.end(); it++) {
		iii_p jt = it-1;
		if (it->X==jt->X) {
			a[it->Y].push_back(jt->Y);
			a[jt->Y].push_back(it->Y);
		}
	}
	for (int i=1; i<=n; i++)
		a[i].push_back(0);
	previsit(1, 0, 1);
	for (int k=1; k<=19; k++)
		for (int i=1; i<=n; i++)
		P[k][i] = P[k-1][P[k-1][i]];

	for (int i=0; i<N; i++)
	if (With[i].size()) {
		int u = With[i].front();
		for (int_p it=With[i].begin()+1; it!=With[i].end(); it++)
			u = lca(u, *it);
		for (int_p it=With[i].begin(); it!=With[i].end(); it++)
			Anc[*it] = u;
	}
	visit(1, 1);
	int Count = 0;
	for (int i=1; i<=n; i++)
		if (F[i]==i) Count++;
	cout << Count-1 << endl;
}

