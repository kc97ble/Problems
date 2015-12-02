#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
#define maxn 100005
using namespace std;

int n,a,b;
vector< pair<int,int> > adj[maxn];
int in[maxn],out[maxn],total = 0;
int par[maxn],parLen[maxn];

void DFS(int u,int p) {
  in[u] = total++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].first;
    if (v == p) continue;
    par[v] = u;
    parLen[v] = adj[u][i].second;
    DFS(v,u);
  }
  out[u] = total++;
}

bool isParent(int u,int v) {
  return (in[u] <= in[v] && out[v] <= out[u]);
}

int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i + 1 < n; i++) {
    int u,v,c;
    scanf("%d %d %d", &u, &v, &c);
    adj[u].push_back(make_pair(v,c));
    adj[v].push_back(make_pair(u,c));
  }
  DFS(a,-1);

  int initLen = parLen[b];
  for (int y = b,x = par[y]; y != a; y = x,x = par[y])
    initLen = min(initLen,parLen[y]);

  int maxB = 0;
  for (int i = 0; i < adj[b].size(); i++) {
    int x = adj[b][i].first;
    if (x == a) continue;
    if (isParent(x,b)) maxB = max(maxB,parLen[b] - initLen);
      else maxB = max(maxB,adj[b][i].second);
  }
  int ret = initLen;

  // update on path towards b
  for (int i = 0; i < adj[a].size(); i++) {
    int x = adj[a][i].first;
    if (!isParent(x,b) || x == b) continue;
    ret = max(ret,min(parLen[b],adj[a][i].second));
  }
  // update on an outside path
  for (int i = 0; i < adj[a].size(); i++) {
    int x = adj[a][i].first;
    if (!isParent(x,b)) ret = max(ret,initLen + min(adj[a][i].second,maxB));
  }
  printf("%d\n", ret);
}
