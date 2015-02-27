//#pragma comment(linker, "/STACK:16777216")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int a[55],b[55];

struct ChessMatchup
{
	public: int maximumScore(vector<int> us,vector<int> them)
	{
		int ret = 0;
		sort(us.begin(),us.end());  sort(them.begin(),them.end());
		for (int lose = 0; lose < us.size(); lose++)
		{
			for (int i = 0; i < lose; i++)
			{
				a[i] = us[i];  b[i] = them[them.size() - 1 - i];				
			}
			for (int i = lose; i < us.size(); i++)
			{
				a[i] = us[i];  b[i] = them[i - lose];
			}
			int cur = 0;
			for (int i = 0; i < us.size(); i++)
			  if (a[i] > b[i]) cur += 2; else if (a[i] == b[i]) cur++;			  
			ret = max(ret,cur);
		}
		return ret;
	}
};