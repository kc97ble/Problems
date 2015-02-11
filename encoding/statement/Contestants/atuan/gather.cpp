#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define fi first
#define se second
#define oo 2000000000
#define maxn 100111

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;
long long ss = 0, res = oo, cc[maxn], f[maxn], d[maxn], c[maxn];
pair<int, int> p [maxn];
vector<vii> e;

void dfs(int u)
{
	if(c[u]) cc[u] = c[u];
	for(int i = 0; i < e[u].size(); i++)
	{
		ii v = e[u][i];
		if(p[u].fi != v.fi)
		{
			p[v.fi] = ii(u, i);
			dfs(v.fi);
			cc[u] += cc[v.fi];
			d[u] += cc[v.fi] * v.se + d[v.fi];
		}
	}
}

void cal(int u)
{
	int tmp = 0;
	if(p[u].fi == -1) f[u] = d[u];
	else
	{
		ii v = p[u];
		f[u] = (f[v.fi] - (cc[u] * e[v.fi][v.se].se + d[u])) + (ss - cc[u]) * e[v.fi][v.se].se;
		f[u] += d[u];
	}
	res = min(f[u], res);
	for(int i = 0; i < e[u].size(); i++)
	{
		ii  v = e[u][i];
		if(p[u].fi != v.fi)
		cal(v.fi);
	}
}

void process()
{
	res = oo;
	p[0] = ii(-1, -1);
	dfs(0);
	cal(0);
	cout << res;
}

int main()
{
//	freopen("a.inp", "r", stdin);
	cin >> n;
//	cout << n << endl;
	e.assign(n, vii());
	for(int i = 0; i < n; i++) {scanf("%lld", &c[i]); ss += c[i];}
	for(int i = 0; i < n-1; i++)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		e[u-1].push_back(ii(v-1, w));
		e[v-1].push_back(ii(u-1, w));
	}
	process();
	return 0;
}

