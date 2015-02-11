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

long long k;
int m,n;
long long f[22][55];
vector<int> ret;

void track(int pos,int low)
{
    if (pos > m) return;
    long long cur = 0;
    for (int i = low; i <= n; i++)
    {
        cur += f[pos][i];
        if (cur > k)
        {
            cur -= f[pos][i];  k -= cur;  ret.push_back(i);  track(pos + 1,i);  return;
        }
    }
    k -= cur;  ret.push_back(n);  track(pos + 1,n);
}

int main()
{
//    freopen("kos11.in","r",stdin);
//    freopen("bone.ou","w",stdout);
    cin >> m >> n >> k;  k--;
    memset(f,0,sizeof(f));
    for (int i = 1; i <= n; i++) f[m][i] = 1;
    for (int i = m - 1; i; i--)
      for (int j = 1; j <= n; j++)
        for (int t = j; t <= n; t++) f[i][j] += f[i + 1][t];            
           
    track(1,1);
    for (int i = 0; i < ret.size(); i++)
    {
        printf("%d", ret[i]);
        if (i == ret.size() - 1) printf("\n"); else printf(" ");
    }   
}
