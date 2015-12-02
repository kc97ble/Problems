#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <limits>
#include <bitset>
#include <locale>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector <int> vi;
vi prev [111], next [111];
int n, in [111], out [111];
bool mark [111];

void dfs (const int &u, vi adj [], int cnt [])
{
	++cnt [u]; mark [u] = 1;
	for (int i = 0; i < adj [u].size (); ++i)
	{
		int v = adj [u][i];
		if (!mark [v]) dfs (v, adj, cnt);
	}
}

int main ()
{
	int m;
	scanf ("%d%d", &n, &m);
	while (m--)
	{
		int u, v; scanf ("%d%d", &u, &v);
		next [u].push_back (v);
		prev [v].push_back (u);
	}
	for (int i = 1; i <= n; ++i)
	{
		memset (mark, 0, sizeof mark); dfs (i, next, in);
		memset (mark, 0, sizeof mark); dfs (i, prev, out);
	}
	//for (int i = 1; i <= n; ++i) printf ("%d ", in [i]); printf ("\n");
	//for (int i = 1; i <= n; ++i) printf ("%d ", out [i]); printf ("\n");
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		cnt += (in [i] + out [i] == n + 1);
	printf ("%d\n", cnt);
	return 0;
}
