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

int f[100002][25];
int n,level[25],amount;
queue< pair<int,int> > q;

int main() {
  freopen("cylinders.in","r",stdin);
  freopen("cylinders.out","w",stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &level[i]);
  scanf("%d", &amount);
  if (!amount) {
    printf("0\n");  return 0;
  }
  for (int i = 0; i < n; i++) if (level[i] == amount) {
    printf("1\n");  return 0;
  }

  memset(f,-1,sizeof(f));
  f[0][0] = 0;
  q.push(make_pair(0,0));
  while (!q.empty()) {
    int fu = q.front().first,fv = q.front().second;
    q.pop();
    if (fu == amount || level[fv] == amount) {
      printf("%d\n", f[fu][fv]);
      return 0;
    }
    // pour water to the first cylinder
    for (int i = 0; i < n; i++) if (f[level[i]][fv] < 0) {
      f[level[i]][fv] = 1 + f[fu][fv];
      q.push(make_pair(level[i],fv));
    }
    // pour water to the second cylinder
    for (int i = 0; i < n; i++) if (f[fu][i] < 0) {
      f[fu][i] = 1 + f[fu][fv];
      q.push(make_pair(fu,i));
    }
    // pour water from two cylinders
    for (int i = 0; i < n; i++) if (i != fv) {
      int fx = fu - (level[i] - level[fv]);
      if (fx >= 0 && fx <= level[n - 1] && f[fx][i] < 0) {
        f[fx][i] = 1 + f[fu][fv];
	q.push(make_pair(fx,i));
      }
    }
  }
  printf("IMPOSSIBLE\n");  
}