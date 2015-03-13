#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define fo(i, a, b) for(int i=a, _b=(b); i<=_b; i++)
#define fod(i, a, b) for(int i=a, _b=(b); i>=_b; i--)

#define fi first
#define se second
#define pb push_back

typedef pair<int, int> p;
/*-------------------------------template-------------------------------*/

int n, sum[111000], mul[111000], num[111000], res=INT_MAX, S;
int f[111000];
bool check[111000];
vector<p> a[111000], alist[111000];

void dfs(int u)
{
	check[u]=true;
	sum[u]=mul[u]=num[u];
	if(a[u].size()==1) mul[u]=0;
	fo(i, 0, (int)a[u].size()-1) {
		int v=a[u][i].fi;
		if(!check[v]) {
			alist[u].pb(a[u][i]);
			dfs(v);
			sum[u]+=sum[v];
			mul[u]+=mul[v]+sum[v]*a[u][i].se;
		}
	}
}

void process(int u)
{
	fo(i, 0, (int)alist[u].size()-1) {
		int v=alist[u][i].fi;
		int tmp=f[u]-mul[v]-sum[v]*alist[u][i].se;
		int tmp2=S-sum[v];
		f[v]=tmp+tmp2*alist[u][i].se+mul[v];//cerr<<v<<" "<<f[v]<<endl;
		process(v);
	}
}	

int main()
{
	//freopen("tmp.inp", "r", stdin);
	cin>>n;
	fo(i, 1,  n) {
		scanf("%d", &num[i]);
		S+=num[i];
	}
	fo(i, 1, n-1) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].pb(p(v, w));
		a[v].pb(p(u, w));
	}
	dfs(1);
	f[1]=mul[1];
	process(1);
	fo(i, 1, n) res=min(res, f[i]);
	cout<<res<<endl;
	return 0;
}
	






























































