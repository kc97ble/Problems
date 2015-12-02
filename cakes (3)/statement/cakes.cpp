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

pair<int,int> v[100010];
int n,m,k;
int pos[100010],posbig[100010],total = 0;
int x[250010],y[250010];
int f[360][100010];
vector<int> adj[100010];
bool exist[100010];

long long calc_small(int fx,int fy)
{
    long long ans = 0;
    int amount = max(v[fx].first,v[fy].first);
    for (int i = 0,j = 0; i < adj[fx].size() && j < adj[fy].size(); )
    {
        if (adj[fx][i] >= min(fx,fy) || adj[fy][j] >= min(fx,fy)) break;
        if (adj[fx][i] < adj[fy][j]) i++;
          else if (adj[fx][i] > adj[fy][j]) j++;
          else
          {
                ans += amount;  i++;  j++;
            }
    }
    return ans;
}

void update(int u)
{
    posbig[u] = total;
    memset(exist,false,sizeof(exist));
    for (int i = 0; i < adj[u].size(); i++) exist[adj[u][i]] = true;
    for (int i = 0; i < n; i++) if (exist[i])
      for (int j = 0; j < adj[i].size() && adj[i][j] < min(u,i); j++) 
        if (exist[adj[i][j]]) f[total][i] += max(v[u].first,v[i].first);
    total++;
}

long long calc_big(int fx,int fy)
{
    if (adj[fx].size() < k) swap(fx,fy);
    if (posbig[fx] < 0) update(fx);
    return f[posbig[fx]][fy];
}

int main()
{
//    freopen("cia9b.in","r",stdin);
//    freopen("cakes.ou","w",stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].first);  v[i].second = i;
    }
    sort(v,v + n);
    for (int i = 0; i < n; i++) pos[v[i].second] = i;   
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &x[i], &y[i]);  
        x[i]--;  y[i]--; 
        x[i] = pos[x[i]];  y[i] = pos[y[i]]; 
        adj[x[i]].push_back(y[i]);  adj[y[i]].push_back(x[i]);
    }
    for (int i = 0; i < n; i++) sort(adj[i].begin(),adj[i].end());
    
    k = (int) sqrt(2 * n) + 3;
    int cnt = 0;
    for (int i = 0; i < n; i++) if (adj[i].size() >= k) cnt++;
    if (cnt > 350) k = n - 4;
        
    memset(posbig,-1,sizeof(posbig));
    long long ret = 0;
    for (int i = 0; i < m; i++)
      if (adj[x[i]].size() < k && adj[y[i]].size() < k) ret += calc_small(x[i],y[i]);
      else ret += calc_big(x[i],y[i]);      
    cout << ret << endl;
}

