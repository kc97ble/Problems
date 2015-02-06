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
 
long long f[55][1 << 17];
int N,L;
bool check[1 << 17];
string ans;
 
struct AlienDictionary
{
        vector<string> getWords(int _N,vector<string> forbid,vector<int> query)
        {
                N = _N;
                L = (forbid.empty()) ? 0 : forbid[0].size();
                
                memset(check,true,sizeof(check));
                for (int mask = 0; mask < (1 << L); mask++)
                  for (int i = 0; i < forbid.size(); i++)
                  {
                    bool flag = true;
                    for (int j = 0; j < L; j++)
                    {
                        if ((mask & (1 << j)) == 0 && forbid[i][j] == 'B') flag = false;
                        if ((mask & (1 << j)) && forbid[i][j] == 'A') flag = false;
                    }
                    if (flag) check[mask] = false;
                  }
                  
                memset(f,-1,sizeof(f));
                vector<string> ret;
                for (int i = 0; i < query.size(); i++)
                {
                        ans.clear();
                        call(0,0,query[i] + 1);
                        if (ans.empty()) ret.push_back("NO PAGE"); else ret.push_back(ans);
                }
                return ret;
        }
        
        long long rec(int pos,int hash)
        {
                if (pos >= L && !check[hash]) return 0;
                if (pos >= N) return 1;
                if (f[pos][hash] >= 0) return f[pos][hash];
                
                int h1,h2;
                if (!L) h1 = h2 = 0; else
                {
                        h1 = (pos < L) ? hash : (hash/2);
                        h2 = (pos < L) ? (hash + (1 << pos)) : (hash/2 + (1 << (L - 1)));
                }
                return f[pos][hash] = rec(pos + 1,h1) + rec(pos + 1,h2);
        }
        
        void call(int pos,int hash,int rem)
        {
                if (pos >= N) return;
                if (rec(pos,hash) < rem)
                {
                        ans.clear();  return;
                }
 
                int h1,h2;
                if (!L) h1 = h2 = 0; else
                {
                        h1 = (pos < L) ? hash : (hash/2);
                        h2 = (pos < L) ? (hash + (1 << pos)) : (hash/2 + (1 << (L - 1)));               
                }
                
                if (rec(pos + 1,h1) >= rem)
                {
                        ans += "A";
                        call(pos + 1,h1,rem);
                }
                else
                {
                        ans += "B";
                        call(pos + 1,h2,rem - rec(pos + 1,h1));
                }
        }
};