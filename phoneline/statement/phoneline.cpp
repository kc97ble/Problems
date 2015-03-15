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

int dp [1111][1111], n;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
vector <ii> adj [1111];

int main ()
{
	int m, p; scanf ("%d%d%d", &n, &m, &p);
	while (m--)
	{
		int u, v, w; scanf ("%d%d%d", &u, &v, &w);
		adj [u].push_back (make_pair (v, w));
		adj [v].push_back (make_pair (u, w));
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp [i][j] = 1e9;
	priority_queue <iii, vector <iii>, greater <iii> > pq;
	pq.push (make_pair (dp [1][p] = 0, make_pair (1, p)));
	while (pq.size ())
	{
		iii tmp = pq.top (); pq.pop ();
		int u = tmp.second.first, s = tmp.second.second;
		if (u == n)
		{
			printf ("%d\n", tmp.first);
			return 0;
		}
		if (tmp.first == dp [u][s])
			for (int i = 0; i < adj [u].size (); ++i)
			{
				int v = adj [u][i].first, w = adj [u][i].second;
				if (dp [v][s] > max (dp [u][s], w))
					pq.push (make_pair (dp [v][s] = max (dp [u][s], w), make_pair (v, s)));
				if (s && dp [v][s - 1] > dp [u][s])
					pq.push (make_pair (dp [v][s - 1] = dp [u][s], make_pair (v, s - 1)));
			}
	}
	printf ("-1\n");
	return 0;
}
