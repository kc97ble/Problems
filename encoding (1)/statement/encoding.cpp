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

int f[55][55][2][2];
int n,INF = (1 << 30) - 5;

struct PalindromeEncoding
{
	int getLength(string s)
	{
		n = s.size();		
		for (int i = 0; i < n; i++)
		  for (int j = i; j < n; j++)
		    for (int k = 0; k < 2; k++)
		      for (int t = 0; t < 2; t++) f[i][j][k][t] = INF;
		      		
		for (int i = 0; i < n; i++) f[i][i][s[i] - '0'][s[i] - '0'] = 1;
		for (int len = 2; len <= n; len++)
		  for (int i = 0; i + len - 1 < n; i++)
		  {
		  	int j = i + len - 1;
		  	for (int k = i; k < j; k++)
		  	  for (int a1 = 0; a1 < 2; a1++)
		  	    for (int a2 = 0; a2 < 2; a2++) if (f[i][k][a1][a2] < INF)
		  	      for (int b1 = 0; b1 < 2; b1++)
		  	        for (int b2 = 0; b2 < 2; b2++) if (f[k + 1][j][b1][b2] < INF)
		  	        {
		  	        	if (a2 != b1) f[i][j][a1][b2] = min(f[i][j][a1][b2],f[i][k][a1][a2] + f[k + 1][j][b1][b2]);
		  	        	else
		  	        	{
		  	        		if (f[i][k][a1][a2] > 1) f[i][j][a1][a2] = min(f[i][j][a1][a2],f[i][k][a1][a2]);
		  	        		else f[i][j][b1][b2] = min(f[i][j][b1][b2],f[k + 1][j][b1][b2]);
		  	        	}
		  	        }
		  }
		
		int ret = INF;
		for (int i = 0; i < 2; i++)
		  for (int j = 0; j < 2; j++) ret = min(ret,f[0][n - 1][i][j]);
		return ret;
	}
};