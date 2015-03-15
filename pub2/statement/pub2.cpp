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

vector<int> point,bonus;
long long f[500010];
long long ss[500010];

long long sum(int x,int y)
{
	if (x > y) return 0;
	return ss[y] - ( (x) ? ss[x - 1] : 0 );
}

vector<int> generate(int n,vector<int> x,int g)
{
	vector<int> result;
	result.push_back(0);
	int k = 0,m = x.size();
	for (int i = 0; i < n; i++)
	{
		result.push_back(x[k]);
		int s = (k + 1) % m;
		x[k] = ( ( x[k] ^ x[s] ) + 13 ) % g;
		k = s;
	}
	result.push_back(0);	
	return result;
}

struct PubTrivia
{
	long long maximumScore(int n,int token,vector<int> p,vector<int> b)
	{		
		point = generate(n,p,1001);  bonus = generate(n,b,10001);	
		for (int i = 1; i <= n + 1; i++) ss[i] = ss[i - 1] + point[i];	
		f[0] = 0;
		long long accom = 0;
		for (int i = 1; i <= n + 1; i++)
		{
			f[i] = f[i - 1] - point[i - 1];
			if (i >= 3) 
			{
				accom = max(accom,f[i - 2] - ss[i - 3]);
				f[i] = max(f[i],accom + ss[i - 2] - point[i - 1]);		
			}
			if (i > token) f[i] = max(f[i],f[i - token] + sum(i - token,i - 1) + bonus[i - 1]);
		}		
		long long ret = 0;
		for (int i = 1; i <= n + 1; i++) ret = max(ret,f[i] + sum(i,n + 1));
		return ret;
	}
};