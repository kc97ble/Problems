// Andrei Grigorean - 100 puncte
#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 1000000;
const int NODES = 2 + 26 + 26 * 27 / 2;
const int INF = 0x3f3f3f3f;

int n, m;
char text[MAX_N + 1];
pair<char, char> cards[MAX_N];

int nodeVal[26][26];

int source, sink;
int f[NODES][NODES];
int c[NODES][NODES];
bool vis[NODES];
int father[NODES];

void read() {
  assert(freopen("teroristi.in", "r", stdin) != NULL);
  assert(freopen("teroristi.out", "w", stdout) != NULL);

  assert(scanf("%d %d", &n, &m) == 2);
  assert(1 <= n && n <= MAX_N);
  assert(1 <= m && m <= MAX_N);

  assert(scanf("%s", text) == 1);
  assert(int(strlen(text)) == n);
  for (int i = 0; i < n; ++i)
    assert('a' <= text[i] && text[i] <= 'z');

  for (int i = 0; i < m; ++i) {
    assert(scanf(" %c %c", &cards[i].first, &cards[i].second) == 2);
    assert('a' <= cards[i].first && cards[i].first <= 'z');
    assert('a' <= cards[i].second && cards[i].second <= 'z');
  }
}

void preproc() {
  int count = 0;
  for (int i = 0; i < 26; ++i)
    for (int j = i; j < 26; ++j)
      nodeVal[i][j] = count++;
}

int getNodeVal(char ch) {
  return 1 + ch - 'a';
}

int getNodeVal(pair<char, char> p) {
  char ch1 = min(p.first, p.second);
  char ch2 = max(p.first, p.second);
  return 27 + nodeVal[ch1 - 'a'][ch2 - 'a'];
}

void build_network() {
  /**
   * 0 - source
   * 1..26 - 'a', 'b', ... 'z'
   * 27..377 - ('a', 'a'), ('a', 'b'), ... ('z', 'z')
   * 378 - sink
   */

  preproc();

  source = 0;
  sink = 26 + 26 * 27 / 2 + 1;

  for (int i = 0; i < n; ++i)
    ++c[source][getNodeVal(text[i])];

  for (int i = 0; i < m; ++i)
    ++c[getNodeVal(cards[i])][sink];

  for (char ch1 = 'a'; ch1 <= 'z'; ++ch1)
    for (char ch2 = ch1; ch2 <= 'z'; ++ch2) {
      c[getNodeVal(ch1)][getNodeVal(make_pair(ch1, ch2))] = INF;
      c[getNodeVal(ch2)][getNodeVal(make_pair(ch1, ch2))] = INF;
    }
}

int bfs() {
  memset(vis, false, sizeof(vis));
  queue<int> q;

  q.push(source);
  vis[source] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int i = 1; i <= sink; ++i)
      if (c[node][i] > f[node][i] && !vis[i]) {
        father[i] = node;
        q.push(i);
        vis[i] = true;
      }
  }

  return vis[sink];
}

void solve() {
  build_network();

  int totalFlow = 0;

  // Do the monkey
  while (bfs()) {
    int flow = INF;
    for (int node = sink; node != source; node = father[node])
      flow = min(flow, c[father[node]][node] - f[father[node]][node]);

    totalFlow += flow;

    for (int node = sink; node != source; node = father[node]) {
      f[father[node]][node] += flow;
      f[node][father[node]] -= flow;
    }
  }

  assert(totalFlow == n);
}

void write() {
  vector<int> sol[27];

  for (int i = 0; i < m; ++i) {
    int node_card = getNodeVal(cards[i]);
    int node_letter1 = getNodeVal(cards[i].first);
    int node_letter2 = getNodeVal(cards[i].second);

    if (f[node_letter1][node_card] > 0) {
      sol[node_letter1].push_back(i);
      --f[node_letter1][node_card];
    } else {
      sol[node_letter2].push_back(i);
      --f[node_letter2][node_card];
    }
  }

  for (int i = 0; i < n; ++i) {
    int card = sol[getNodeVal(text[i])].back();
    sol[getNodeVal(text[i])].pop_back();
    printf("%s%d", i == 0 ? "" : " ", card + 1);
  }
  printf("\n");
}

int main() {
  read();
  solve();
  write();
}
