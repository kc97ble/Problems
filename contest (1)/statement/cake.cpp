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
using namespace std;

int n,m,k,T;
int score[402][402];
int beat[402][402],ok[402];
bool signal;

void attempt(int idx,int chosen) {
  if (signal) return;
  if (idx >= k) return;
  attempt(idx + 1,chosen);  // not choose task idx
  if (chosen < n) {
    // request
    bool all = true;
    for (int i = 1; i < m; i++) {
      ok[i] += beat[i][idx];
      if (!ok[i]) all = false;
    }
    if (all) {
      signal = true;  return;
    }
    else attempt(idx + 1,chosen + 1);
    for (int i = 1; i < m; i++) ok[i] -= beat[i][idx];
  }
}

bool solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < k; j++) scanf("%d", &score[i][j]);
  if (m == 1) return true;

  for (int i = 1; i < m; i++)
    for (int j = 0; j < k; j++) beat[i][j] = (score[0][j] > score[i][j]);

  if (m < k) {
    // the number of contestants is not greater than 20
    int reach[1 << 19],mask[402];
    memset(mask,0,sizeof(mask));
    for (int i = 0; i < k; i++)
      for (int j = 1; j < m; j++) if (beat[j][i]) mask[i] |= 1 << (j - 1);
    memset(reach,-1,sizeof(reach));
    reach[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();  q.pop();
      if (reach[u] >= n) break;
      for (int i = 0; i < k; i++) {
        int v = u | mask[i];
	if (reach[v] >= 0) continue;
	reach[v] = 1 + reach[u];
	q.push(v);
      }
      if (reach[(1 << (m - 1)) - 1] >= 0) break;
    }
    return (reach[(1 << (m - 1)) - 1] >= 0);
  }
  else {
    // the number of topics is not greaterer than 20
    signal = false;
    memset(ok,false,sizeof(ok));
    attempt(0,0);
    return signal;
  }
}

int main() {
  scanf("%d", &T);
  while (T--)
    if (solve()) printf("TAK\n"); else printf("NIE\n");
}

