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

int sum = 0;
int T,num[505];
int p[50005],w[50005];
int bigp[505],bigw[505],start[505],end[505];
int orderbig[505],ordersmall[50005];

int cmp1(int x,int y) {
  return 1.0 * bigp[x]/bigw[x] < 1.0 * bigp[y]/bigw[y];
}

int cmp2(int x,int y) {
  return 1.0 * p[x]/w[x] < 1.0 * p[y]/w[y];
}

int main() {
  scanf("%d", &T);
  for (int i = 0; i < T; i++) scanf("%d", &num[i]);
  for (int i = 0; i < T; i++) sum += num[i];
  for (int i = 0; i < sum; i++) scanf("%d", &p[i]);
  for (int i = 0; i < sum; i++) scanf("%d", &w[i]);
  start[0] = 0;  end[0] = num[0];
  for (int i = 1; i < T; i++) {
    start[i] = end[i - 1];
    end[i] = start[i] + num[i];
  }
  for (int i = 0; i < T; i++)
    for (int j = start[i]; j < end[i]; j++) {
      bigp[i] += p[j];
      bigw[i] += w[j];
    }
  for (int i = 0; i < T; i++) orderbig[i] = i;
  sort(orderbig,orderbig + T,cmp1);

  long long ret = 0,cur = 0;
  vector<int> final;
  for (int i = 0; i < T; i++) {
    int u = orderbig[i];
    for (int j = start[u]; j < end[u]; j++) ordersmall[j] = j;
    sort(ordersmall + start[u],ordersmall + end[u],cmp2);
    for (int j = start[u]; j < end[u]; j++) {
      int v = ordersmall[j];
      final.push_back(v + 1);
      cur += p[v];
      ret += 1LL * cur * w[v];
    }
  }
  cout << ret << endl;
  for (int i = 0; i < final.size(); i++) printf("%d ", final[i]);
}
