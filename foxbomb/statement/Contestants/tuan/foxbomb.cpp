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

#define maxn 50 + 10
char grid [maxn][maxn];
int n, m;
typedef pair <int, ii> i3;
vector <i3> control;
int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};
int mark [maxn][maxn];

bool check (ii x)
{
	return x.fi >=0 && x.fi <n && x.se >=0 && x.se < m && grid[x.fi][x.se] != '#';
}

int cal (ii x)
{
	int sum = 0;
	for (int i=0; i<4; ++i) {
		ii v (x.fi + dx[i], x.se + dy[i]);
		if ( check(v) ) {
			sum++;
			ii t (v.fi + dx[i], v.se + dy[i]);
			while ( check(t) ) {
				sum++;
				t.fi += dx[i];
				t.se += dy[i];
			}
		}
	}
	return sum;
}

void solve ()
{
	control. clear();
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if ( check(ii(i, j)) )
				control. push_back(i3(cal(ii(i, j)), ii(i, j)));
	sort(control. rbegin(), control. rend());
	int res = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if ( grid[i][j] == '.' ) res++;
	int ind = 0;
	memset(mark, 0, sizeof mark);
	while ( res > 0 && ind < control. size() ) {
		int sum = 0;
		ii x = control[ind]. se;
		for (int i=0; i<4; ++i) {
			ii v (x.fi + dx[i], x.se + dy[i]);
			if ( check(v) ) {
				if ( !mark[v.fi][v.se] ) {
					 mark[v.fi][v.se] = 1;
					sum++;
				}
				ii t (v.fi + dx[i], v.se + dy[i]);
				while ( check(t) ) {
					if ( !mark[t.fi][t.se] ) {
						sum++;
						mark[t.fi][t.se] = 1;
					}
					t.fi += dx[i];
					t.se += dy[i];
				}
			}
		}
		res -= sum;
		ind++;
	}
	cout << ind << endl;
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin >> n;
	scanf ("\n");
	for (int i=0; i<n; ++i) {
		cin >> grid[i];
		if ( i==0 ) m = strlen(grid[i]);
	}
	solve ();
	return 0;
}

