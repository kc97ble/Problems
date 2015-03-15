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
#include <utility>
#include <vector>
using namespace std;

int n,f[55][55];

struct TriviaGame
{
	int maximumScore(vector<int> points,int token,vector<int> bonus)
	{
		n = points.size();
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < token; j++) f[i][j] = -(1 << 28);
		f[0][0] = -points[0];		  
		if (token == 1) f[0][0] = points[0] + bonus[0]; else f[0][1] = points[0];
		
		for (int i = 0; i < n - 1; i++)
		  for (int j = 0; j < token; j++)
		  {
		  	f[i + 1][j] = max(f[i + 1][j],f[i][j] - points[i + 1]);
		  	if (j < token - 1) 
		  	  f[i + 1][j + 1] = max(f[i + 1][j + 1],f[i][j] + points[i + 1]); else f[i + 1][0] = max(f[i + 1][0],f[i][j] + points[i + 1] + bonus[i + 1]);
		  }
		  
		int ret = -(1 << 28);
		for (int j = 0; j < token; j++) ret = max(ret,f[n - 1][j]);
		return ret;
	}
};