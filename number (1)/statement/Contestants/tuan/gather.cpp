#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long llu;

#define fi first
#define se second
#define mp make_pair
#define oo 2147483647

#define maxn 100000 + 10
int V;
vector <ii> Adlist [maxn];
int c [maxn];
int parent [50 + 10][maxn], loga [maxn];
int value [50+10][maxn];
int high [maxn];

void bfs ()
{
	queue <int> q;
	memset(high, -1, sizeof high);
	high[1] = 0;
	q. push(1);
	while (!q. empty()) {
		int u = q. front(); q. pop();
		for (int i=0; i<Adlist[u]. size(); ++i) {
			ii v = Adlist[u][i];
			if ( high[v.fi] == -1 ) {
				high[v.fi] = high[u] + 1;
				parent[0][v.fi] = u;
				value[0][v.fi] = v.se;
				q. push(v.fi);
			}
		}
	}
}

void init ()
{
	loga[1] = 0;
	for (int i=2; i<=V; ++i)
		if ( i == (1<<(loga[i-1]+1)) ) loga[i] = loga[i-1] + 1;
		else loga[i] = loga[i-1];
	memset(parent, -1, sizeof parent);
	bfs ();
	for (int i=1; i<=loga[V]; ++i)
		for (int j=1; j<=V; ++j)
			if ( parent[i-1][j] != -1 ) {
				parent [i][j] = parent[i-1][parent[i-1][j]];
				value [i][j] = value [i-1][j] + value[i-1][parent[i-1][j]];
			}
}

int LCA (int u, int v)
{
	int res = 0;
	if ( high[u] < high[v] ) swap (u, v);
	for (int i=loga[V]; i>=0; --i)
		if ( high[u] - (1<<i) >= high[v] ) {
			res += value [i][u];
			u = parent[i][u];
		}
	if ( u == v ) return res;
	for (int i=loga[V]; i>=0; --i)
		if ( parent[i][u] != parent[i][v] ) {
			res += value [i][u] + value [i][v];
			u = parent[i][u];
			v = parent[i][v];
		}
	res += value [0][u] + value [0][v];
	return res;
}

void solve ()
{
	init ();
	int res = oo;
	for (int i=1; i<=V; ++i) {
		int tmp = 0;
		for (int j=1; j<=V; ++j)
			tmp += LCA (j, i)*c[j];
		res = min(res, tmp);
	}
	cout << res << endl;
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin >> V;
	for (int i=1; i<=V; ++i) {
		Adlist[i]. clear();
		scanf ("%d",&c[i]);
	}
	for (int i=1; i<V; ++i) {
		int u, v, w;
		scanf ("%d%d%d",&u, &v, &w);
		Adlist[u]. push_back(ii(v, w));
		Adlist[v]. push_back(ii(u, w));
	}
	solve ();
	return 0;
}

