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
#define maxn 202
using namespace std;

int f[2][maxn][maxn],fa[2][maxn][maxn],fb[2][maxn][maxn];

int main() {
  int n,k,p;
  scanf("%d %d %d", &n, &k, &p);
  for (int i = 1; i <= k; i++) f[0][i][0] = 1;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= k; j++) {
      fa[0][i][j] = fb[0][i][j] = f[0][i][j];
      if (i) fa[0][i][j] = (fa[0][i][j] + fa[0][i - 1][j]) % p;
      if (j) fb[0][i][j] = (fb[0][i][j] + fb[0][i][j - 1]) % p;
    }

  for (int iter = 1; iter < n; iter++) {
    int next = iter % 2;
    int cur = next ^ 1;
    for (int i = 1; i <= k; i++)
      for (int j = 0; j < i; j++) {
        f[next][i][j] = fa[cur][i][j] - fa[cur][j][j];
	if (j) f[next][i][j] += fb[cur][i][j];
	if (f[next][i][j] < 0) f[next][i][j] += p;
	while (f[next][i][j] >= p) f[next][i][j] -= p;
      }
    for (int i = 0; i <= k; i++)
      for (int j = 0; j <= k; j++) {
        fa[next][i][j] = fb[next][i][j] = f[next][i][j];
	if (i) fa[next][i][j] += fa[next][i - 1][j];
	if (fa[next][i][j] >= p) fa[next][i][j] -= p;
	if (j) fb[next][i][j] += fb[next][i][j - 1];
	if (fb[next][i][j] >= p) fb[next][i][j] -= p;
      }
  }
  int ret = 0;
  for (int i = 1; i <= k; i++)
    for (int j = 0; j < i; j++) ret = (ret + f[(n + 1) % 2][i][j]) % p;
  printf("%d\n", ret + 1);
}
