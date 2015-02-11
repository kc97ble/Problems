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
 
int fmemo[55][55],touch[55][55],n;
 
struct CardRemover
{
        int calculate(vector<string> s)
        {
                n = s.size();
                if (n < 3) return 0;
                
                memset(touch,false,sizeof(touch));
                for (int i = 0; i + 1 < n; i++) touch[i][i + 1] = true;
                for (int len = 3; len <= n; len++)
                  for (int i = 0; i + len - 1 < n; i++)
                  {
                        int j = i + len - 1;
                        if (!can_remove(s[i],s[j])) continue;
                        for (int k = i + 1; k < j; k++) if (touch[i][k] && touch[k][j]) touch[i][j] = true;
                  }                              
                  
                memset(fmemo,-1,sizeof(fmemo));
                return f(0,n - 1);
        }
        
        bool can_remove(string A,string B)
        {
                int ans = 0;
                for (int i = 0; i < 3; i++)
                  for (int j = 0; j < 3; j++) if (A[i] == B[j]) ans++;
                return (ans >= 2);
        }
        
        int f(int x,int y)
        {
                if (touch[x][y]) return fmemo[x][y] = y - x - 1;
                if (fmemo[x][y] >= 0) return fmemo[x][y];
                
                fmemo[x][y] = 0;
                for (int k = x + 1; k < y; k++) fmemo[x][y] = max(fmemo[x][y],f(x,k) + f(k,y));
                return fmemo[x][y];
        }
};