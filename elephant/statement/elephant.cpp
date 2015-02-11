#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

class RearrangeFurniture
{
	public: int lowestEffort(vector<int>,vector<int>);
};

int RearrangeFurniture::lowestEffort(vector<int> cost,vector<int> fin)
{
	int ret = 0;
	bool a[60];
	memset(a,true,sizeof(a));
	int mincost = cost[0];
	for (int i = 1; i < cost.size(); i++) mincost = min(mincost,cost[i]);
	for (int i = 0; i < cost.size(); i++) if (a[i])
	{
		int ele = 1;  a[i] = false;  int t = fin[i];  
		int minarr = cost[i],sumarr = cost[i];
		while (a[t])
		{
			ele++;  a[t] = false;  
			minarr = min(minarr,cost[t]);  sumarr += cost[t];
			t = fin[t];
		};
		ret += min(sumarr + (ele - 2) * minarr,sumarr + minarr + (ele + 1) * mincost);
	};
	return ret;
};