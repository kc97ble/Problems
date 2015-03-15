#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define for_each(it, a) for (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#define X first
#define Y second

const int N = 200005;
int n, m, Time, ll[N], rr[N], P[20][N];
vector<int> a[N];
vector<iii> Update[N];
int Max[4*N], Inc[4*N];

struct node {
	int ll, rr, id;
	node (int L, int R, int X)
		{ ll=L, rr=R, id=X; access(); }
	node left()
		{ return node(ll, (ll+rr)/2, id*2); }
	node right()
		{ return node((ll+rr)/2+1, rr, id*2+1); }
	
	void access() {
		if (Inc[id]) {
			if (ll!=rr) {
				Inc[id*2] += Inc[id];
				Inc[id*2+1] += Inc[id];
			}
			Max[id]+=Inc[id]; Inc[id]=0;
		}
	}
	
	void inc_range(int L, int R, int X) {
		if (ll>R || L>rr || L>R) return ;
		if (L<=ll && rr<=R) { Inc[id]=X; access(); return; }
		left().inc_range(L, R, X);
		right().inc_range(L, R, X);
		Max[id] = max(Max[id*2], Max[id*2+1]);
	}
};

void visit(int u, int p) {
	P[0][u]=p;
	ll[u]=++Time; // printf("%d ", u);
	for (int i=0; int v=a[u][i]; i++)
	if (v!=p) visit(v, u);
	rr[u]=Time; // printf("{%d} ", u);
}

void update(int x, int u, int y, int v, int k) {
	//printf("update(%d, %d, %d, %d, %d)\n", x, u, y, v, k);
	if (x>u || y>v || k==0) return;
	Update[x].push_back(iii(ii(y, v), k));
	Update[u+1].push_back(iii(ii(y, v), -k));
}

int ordo(int x, int y) {
	#define k(x) P[k][x]
	for (int k=19; k>=0; k--)
	if (ll[y]<ll[k(x)] && rr[k(x)]<=rr[y]) 
	x=k(x);
	return x;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i=1; i<=n; i++)
		a[i].push_back(0);
	visit(1, 1);
	
	for (int k=1; k<=19; k++)
	for (int i=1; i<=n; i++)
	P[k][i] = P[k-1][P[k-1][i]];

	scanf("%d", &m);
	for (int i=1; i<=m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (ll[x]>ll[y]) swap(x, y);
		if (ll[x]<ll[y] && rr[y]<=rr[x]) {
			update(ll[y], rr[y], 1, n, z);
			update(1, n, ll[y], rr[y], z);
			int w = ordo(y, x);
			//printf("ordo(%d, %d) = %d\n", y, x, w);
			update(ll[y], rr[y], ll[w], rr[w], -z);
			update(ll[w], rr[w], ll[y], rr[y], -z);
		} else {
			update(ll[x], rr[x], ll[y], rr[y], z);
			update(ll[y], rr[y], ll[x], rr[x], z);
		}
	}
	
	int Max = 0;
	for (int i=1; i<=n; i++) {
		//printf("i=%d\n", i);
		for_each(it, Update[i]) {
			node(1, n, 1).inc_range(it->X.X, it->X.Y, it->Y);
			//printf("inc_range(%d, %d, %d\n", it->X.X, it->X.Y, it->Y);
		}
		Max = max(Max, ::Max[1]);
	}
	cout << Max << endl;
}
