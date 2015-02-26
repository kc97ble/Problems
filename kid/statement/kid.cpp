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
#define maxm 200005
using namespace std;

map<int,int> vertices;
set< pair<int,int> > edge;
int n,m,total = 0;
vector<int> adj[maxm];
int depth[maxm],pre[maxm];
bool answer;

int getVertices(int x) {
    if (!vertices.count(x)) vertices[x] = total++;
    return vertices[x];
}

void BFS(int start) {
    if (!answer) return;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v == pre[u]) continue;
            if (depth[v] < 0) {
                pre[v] = u;
                depth[v] = 1 + depth[u];
                q.push(v);
            }
            else if (depth[u] + depth[v] + 1 < n) answer = false;
        }
    }
}

int main() {
    int ntest = 0;
    while (1) {
        scanf("%d %d", &n, &m);
        if (!n) return 0;
        ntest++;
        vertices.clear();
        edge.clear();
        total = 0;
  //      if (ntest == 8) printf("%d %d\n", n, m);
        for (int i = 0; i < m; i++) {
            int u,v;
            scanf("%d %d", &u, &v);
            u = getVertices(u);
            v = getVertices(v);
            if (u > v) swap(u,v);
    //        if (ntest == 8) printf("%d %d\n", u, v);
            edge.insert(make_pair(u,v));
        }
        for (int i = 0; i < total; i++) {
            adj[i].clear();
            depth[i] = -1;
            pre[i] = -1;
        }
        for (set< pair<int,int> >::iterator it = edge.begin(); it != edge.end(); it++) {
            adj[it->first].push_back(it->second);
            adj[it->second].push_back(it->first);
        }
        answer = true;
        for (int i = 0; i < total; i++) if (adj[i].size() > 2) answer = false;
        for (int i = 0; i < total; i++) if (depth[i] < 0) {
            depth[i] = 0;
            BFS(i);
        }
        if (answer) printf("Y\n"); else printf("N\n");
//        if (ntest == 8) return 0;
    }
}
