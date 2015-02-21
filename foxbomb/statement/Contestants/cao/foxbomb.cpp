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

/*-------------------------------template-------------------------------*/

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int n, m, V=1, x[55][55], num[55][55], f[3300][2];
bool check[55][55];
string s[55];
vector<int> a[3300];

bool kt(int u, int v)
{
	int cnt=0;
	fo(i, 0, 3) {
		int a=u+dx[i], b=v+dy[i];
		if(x[a][b]==1) cnt++;
	}
	if(cnt==2) if(x[u+1][v]!=x[u][v+1]) return false;
	return true;
}

void dfs(int u, int v)
{
	if(check[u][v] || x[u][v]==0) return;
	check[u][v]=true;
	num[u][v]=V;
	fo(i, 0, 3) {
		fo(j, 1, 100) {
			int aa=u+dx[i]*j, b=dy[i]*j+v;
			if(check[aa][b] || x[aa][b]==0) break;
			if(!kt(aa, b)) {
				check[aa][b]=true;
				continue;
			}
			else {
				a[num[u][v]].pb(++V);
				//a[V].pb(num[u][v]);
				dfs(aa, b);
			}
		}
	}
}

int getf(int u, int k)
{
	int& res=f[u][k];
	if(res!=-1) return res;
	res=0;
	int aa=0, c=0;
	fo(i, 0, (int)a[u].size()-1) {
		int v=a[u][i];
		aa+=getf(v, 1);
		c+=min(getf(v, 0), getf(v, 1));
	}
	if(k==1) res=c+1;
	else res=aa;
	return res;
}

int main()
{
	//freopen("tmp.inp", "r", stdin);
	cin>>m;
	fo(i, 1, m) {
		cin>>s[i];
		n=s[i].size();
		s[i]=" "+s[i];
		fo(j, 1, n) if(s[i][j]=='.') x[i][j]=1;
	}
	fo(i, 1, m) fo(j, 1, n) dfs(i, j);
	memset(f, -1, sizeof f);
	cout<<min(getf(1, 1), getf(1, 0))<<endl;
	return 0;
}
