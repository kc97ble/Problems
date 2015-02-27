#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstring>
#include <map>
#include <math.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair <int , ii> iii;

#define fi first
#define se second
#define INF 1000000000

int n, total;
vector <int> a;
vector <int> c;
vector <double> r;

void excute()
{
	for (int i = 1; i < n; i++)
	for (int j = 0; j < i; j++)
	{
		    int k = c[i] - c[j];
		    if (c[i] - c[j] == 0)
		    r.push_back(INF);
		    else
		    r.push_back(double (a[i] - a[j]) / k);
	}
	sort(r.begin(), r.end());
	double crr = r[0];
	for (int i = 1; i < r.size(); i++)
	{

		    if (r[i] != crr) crr = r[i];
		    else total--;
	}
	printf("%d", total);
}

main()
{
	 scanf("%d", &n);
	 
	 total  = n * (n - 1) / 2;
	 
	 for (int i = 0; i < n; i++)
	 {
			int x, y;
			scanf("%d%d", &x, &y);
			a.push_back(y);
			c.push_back(x);
	 }
	 excute();
}
