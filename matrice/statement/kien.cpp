#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
#define X first
#define Y second

#define N 310
int n, m;
vector<ii> e[1000006];
vector<int> a[N*N];
int Value[N*N], Level[N*N];
int P[20][N*N], M[20][N*N];
bool Activated[N][N];

struct disjoint_set {
	int P[N*N];
	disjoint_set()
		{ f0(i,N*N) P[i]=i; }
	bool join(int x, int y) 
		{ x=at(x); y=at(y); return x==y ? false : (P[x]=y, true); }
	int at(int x)
		{ return x==P[x] ? x : P[x]=at(P[x]); }
} Label;

void previsit(int u, int p, int l) {
	P[0][u]=p, Level[u]=l;
	M[0][u]=min(Value[u], Value[p]);
	for (int i=0; int v=a[u][i]; i++) if (v!=p)
	previsit(v, u, l+1);
}

void lca_init(){
	f1(k,19) f0(i,N*N) {
		P[k][i] = P[k-1][P[k-1][i]];
		M[k][i] = min(M[k-1][i], M[k-1][P[k-1][i]]);
	}
}

int lca_min(int x, int y){
	#define k(x) P[k][x]
	#define jump(x, k) Min=min(Min, M[k][x]), x=P[k][x];
	int Min = 0x3c3c3c3c;
	for (int k=19; k>=0; k--) if (Level[k(x)]>=Level[y]) jump(x, k);
	for (int k=19; k>=0; k--) if (Level[k(y)]>=Level[x]) jump(y, k);
	for (int k=19; k>=0; k--) if (k(x)!=k(y)) { jump(x, k); jump(y, k); }
	while (x!=y) { jump(x, 0); jump(y, 0); }
	return Min;
}

void try_link(int x, int y) {
	if (Label.join(x, y)) {
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

main(){	
	scanf("%d%d", &n, &m);
	f1(i,n) f1(j,n) {
		scanf("%d", &Value[i*N+j]);
		e[Value[i*N+j]].push_back(ii(i, j));
	}
	int rx[]={-1,0,1,0};
	int ry[]={0,-1,0,1};
	for (int i=1000006-1; i>=0; i--) {
		f0(j,e[i].size()) {
			int x=e[i][j].X, y=e[i][j].Y;
			Activated[x][y] = true;
			f0(k,4) {
				int xx=x+rx[k], yy=y+ry[k];
				if (Activated[xx][yy])
				try_link(x*N+y, xx*N+yy);
			}
		}
	}
	f0(i,N*N) a[i].push_back(0);
	previsit(1*N+1, 1*N+1, 1);
	lca_init();
	
	f1(i,m) {
		int x, y, u, v;
		scanf("%d%d%d%d", &x, &y, &u, &v);
		printf("%d\n", lca_min(x*N+y, u*N+v));
	}
}
