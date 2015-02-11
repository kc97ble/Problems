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
#define maxn 4500
using namespace std;

int T,n,m,ret = 1,num[maxn];
vector<int> adj[maxn];
vector<int> vertices;

void DFS(int u,int pre) {
  num[u] = 1;
  vertices.push_back(u);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == pre) continue;
    if (!num[v]) DFS(v,u); else {
      for (int j = vertices.size() - 2; j >= 0; j--) if (vertices[j] == v)
        ret = max(ret,(int) vertices.size() - j);
    }
  }
  vertices.pop_back();
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
      int u,v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    memset(num,0,sizeof(num));
    ret = 0;
    DFS(1,-1);
    printf("%d\n", ret);
  }
}
