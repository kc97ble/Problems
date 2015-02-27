#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int N = (int) 1e5;
vector<pair<int, int> > graph[N];
vector<int> path;
int parent[N];
int depth[N];
bool avoid[N];
int n;

void dfs1(int u) {
    for (int i = 0; i < (int) graph[u].size(); ++i) {
        int v = graph[u][i].first;
        int c = graph[u][i].second;
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + c;
        dfs1(v);
    }
}

void dfs2(int u) {
    int toAvoid = -1;
    path.push_back(u);
    for (int i = 0; i < (int) graph[u].size(); ++i) {
        int v = graph[u][i].first;
        if (v == parent[u]) continue;
        if (avoid[v]) {
            toAvoid = v;
        } else {
            dfs2(v);
            path.push_back(u);
        }
    }
    if (toAvoid != -1) dfs2(toAvoid);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int answer = 0;
    for (int i = 1; i < n; ++i) {
        int u; cin >> u; --u;
        int v; cin >> v; --v;
        int c; cin >> c;
        answer += 2 * c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }
    parent[0] = -1;
    dfs1(0);
    int u = max_element(depth, depth + n) - depth;
    answer -= depth[u];
    while (u != -1) {
        avoid[u] = true;
        u = parent[u];
    }
    dfs2(0);
    printf("%d\n", answer);
    printf("%d\n", (int) path.size());
    for (int i = 0; i < (int) path.size(); ++i) {
        if (i > 0) printf(" ");
        printf("%d", path[i] + 1);
    }
    printf("\n");
    return 0;
}

