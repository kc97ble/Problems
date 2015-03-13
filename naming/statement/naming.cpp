#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int dp[55][55],n;

struct MagicNaming {
	int maxReindeers(string s) {
		n = s.size();
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < n; j++) dp[i][j] = -1000;
		for (int i = 0; i < n; i++) dp[0][i] = 1;
		for (int i = 0; i < n; i++)
		  for (int j = i; j < n; j++) {
		  	string alpha = s.substr(i,j - i + 1);
		  	for (int k = j + 1; k < n; k++) {
		  		string beta = s.substr(j + 1,k - j);
		  		if ((alpha + beta) <= (beta + alpha)) dp[j + 1][k] = max(dp[j + 1][k],1 + dp[i][j]);
		  	}
		  }
		int ret = 0;
		for (int i = 0; i < n; i++) ret = max(ret,dp[i][n - 1]);
		return ret;
	}
};