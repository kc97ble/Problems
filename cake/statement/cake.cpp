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
#define maxn 6002
using namespace std;

int cap[1000002];
int A[102][102],B[102][102],total,edge;
vector< pair<int,int> > adj[maxn];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int start,end;

struct FoxAndCake {
  string ableToDivide(int n, int m, vector <int> x, vector <int> y) {
    x.push_back(n);
    y.push_back(m);
    x = refine(x);
    y = refine(y);

    total = 0;  edge = 0;
    memset(cap,0,sizeof(cap));
    for (int i = 0; i < maxn; i++) adj[i].clear();

    n = x[7];  m = y[7];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        A[i][j] = total++;
	B[i][j] = total++;
	if (i != x[0] || j != y[0]) add(A[i][j],B[i][j],1);
      }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = 0; k < 4; k++) {
	  int gi = i + dx[k],gj = j + dy[k];
	  if (gi <= 0 || gi > n || gj <= 0 || gj > m) continue;
	  add(B[i][j],A[gi][gj],1);
	}
    
    start = total++;
    end = total++;
    for (int i = 1; i < 4; i++) add(start,A[x[i]][y[i]],1);
    for (int i = 4; i < 7; i++) add(B[x[i]][y[i]],end,1);
    return (maxFlow() == 3) ? "Yes" : "No";
  }

  void add(int u,int v,int g) {
    adj[u].push_back(make_pair(v,edge));
    adj[v].push_back(make_pair(u,edge + 1));
    cap[edge] = g;
    edge += 2;
  }

  int maxFlow() {
    int trace[maxn],edgetrace[maxn];
    int ret = 0;
    while (1) {
      for (int i = 0; i < total; i++) trace[i] = -1;
      trace[start] = -2;
      queue<int> q;
      q.push(start);

      while (!q.empty()) {
        int u = q.front();  q.pop();
	for (int i = 0; i < adj[u].size(); i++) {
	  int v = adj[u][i].first,idx = adj[u][i].second;
	  if (cap[idx] <= 0 || trace[v] != -1) continue;
	  trace[v] = u;
	  edgetrace[v] = idx;
	  q.push(v);
	}
      }
     
      if (trace[end] == -1) return ret;
      ret++;
      for (int v = end,u = trace[v]; v != start; v = u,u = trace[v]) {
        int idx = edgetrace[v];
	cap[idx]--;
	cap[idx ^ 1]++;
      }
    }    
  }

  vector<int> refine(vector<int> a) {
    vector<int> store;
    store.push_back(-100);
    for (int i = 0; i < a.size(); i++)
      for (int j = -3; j <= 3; j++)
        if (a[i] + j > 0 && a[i] + j <= a[a.size() - 1]) store.push_back(a[i] + j);
    sort(store.begin(),store.end());
    vector<int> _store;
    for (int i = 0; i < store.size(); i++)
      if (!i || store[i] > store[i - 1]) _store.push_back(store[i]);
    vector<int> b = a;
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < _store.size(); j++) if (a[i] == _store[j]) b[i] = j;
    return b;
  }
};

