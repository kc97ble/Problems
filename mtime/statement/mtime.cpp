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
#include <vector>
using namespace std;

int n;
pair <int, int> task [1111];

bool ok (int x)
{
	for (int i = 1; i <= n; ++i)
	{
		if (x + task [i].second > task [i].first) return 0;
		x += task [i].second;
	}
	return 1;
}

int main (int argc, char **argv)
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) scanf ("%d%d", &task [i].second, &task [i].first);
	sort (task + 1, task + n + 1);
	
	if (!ok (0))
	{
		printf ("-1\n");
		return 0;
	}
	int l = -1, r = 1e6 + 10;
	while (l < r)
	{
		int m = (l + r) >> 1;
		if (ok (m)) l = m;
		else r = m - 1;
	}
	printf ("%d\n", l);
	return 0;
}
