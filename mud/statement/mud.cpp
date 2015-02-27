/* ---------------------------------------------------------------------------------------- */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define rp(i, n) for (int i = 0; i < (n); ++i)
#define rd(i, n) for (int i = (n); i--;)
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define sz(x) (int) (x).size ()

#define MAX  2147483647
#define MIN -2147483647

typedef unsigned long long llu;
typedef long long ll;

typedef pair <int, int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
typedef vector <int> vi;

/* ---------------------------------------------------------------------------------------- */
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int grid[1001][1001];
int n;
int F[1001][1001];

int check(ii a)
{
	return ( a.fi >= 0 && a.fi <= 1000 && a.se >=0 && a.fi <= 1000 && grid[a.fi][a.se] == 0 );
}

int bfs(ii src, ii des)
{
	queue<ii> q;
	rp (i,1001)
		rp (j,1001)
			F[i][j] = MAX;
	
	F[src.fi][src.se] = 0;
	
	q.push(ii(src));
	while (!q. empty()) {
		ii u = q.front(); q.pop();
		rp (i,4) {
			ii v (u.fi + dx[i], u.se+dy[i]);
			if (check(v)) 
				if (F[v.fi][v.se] == MAX) {
					F[v.fi][v.se] = F[u.fi][u.se] + 1;
					if (v==des) return F[v.fi][v.se];
					q. push(v);
				}
			}
		}
	return 0;
}

int main ()
{
//	freopen("tmp.inp","r",stdin);
	ii des;
	cin >> des.fi >> des.se >> n;
	des.fi += 499;
	des.se += 499;
	
	rp (i,1001)
		rp (j,1001)
			grid[i][j] = 0;
	
	rp (i,n) {
		int a,b;
		cin >> a >> b;
		grid[a+499][b+499] = 1;
	}
	
	cout << bfs( ii(499,499), des);
	return 0;
}

