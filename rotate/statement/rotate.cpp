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
#define maxn 302
#define mod 100000
using namespace std;

int m,n;
string oper;
string s[maxn];
int sum[maxn * maxn][350],next[maxn * maxn][350];
int ret[maxn * maxn];
int location[maxn][maxn];

int binary[350],fmodulo,maxIter;

void bigIntOperation() {
    int d[105];
    memset(d,0,sizeof(d));
    reverse(oper.begin(),oper.end());
    for (int i = 0; i < oper.size(); i++) d[i] = oper[i] - '0';
    int round = (m - 1) * (n - 1);
    fmodulo = 0;
    for (int i = 99; i >= 0; i--) {
        fmodulo = fmodulo * 10 + d[i];
        fmodulo %= round;
    }
    for (int i = 99; i >= 0; i--) {
        if (i) d[i - 1] += 10 * (d[i] % round);
        d[i] /= round;
    }
    for (int iter = 0; iter < 350; iter++) {
        bool rem = false;
        binary[iter] = d[0] % 2;
        for (int i = 99; i >= 0; i--) {
            if (d[i]) rem = true;
            if (i) d[i - 1] += 10 * (d[i] % 2);
            d[i] /= 2;
        }
        if (!rem) {
            maxIter = iter;
            return;
        }
    }
}

void swapClockwise(int i,int j) {
    int tmp = location[i][j];
    location[i][j] = location[i + 1][j];
    location[i + 1][j] = location[i + 1][j + 1];
    location[i + 1][j + 1] = location[i][j + 1];
    location[i][j + 1] = tmp;
}

void swapCounterClockwise(int i,int j) {
    int tmp = location[i][j];
    location[i][j] = location[i][j + 1];
    location[i][j + 1] = location[i + 1][j + 1];
    location[i + 1][j + 1] = location[i + 1][j];
    location[i + 1][j] = tmp;
}

int main() {
    scanf("%d %d", &m, &n);
    cin >> oper;
    for (int i = 0; i + 1 < m; i++) cin >> s[i];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) location[i][j] = i * n + j,sum[i * n + j][0] = 0;

    for (int i = 0; i + 1 < m; i++)
      for (int j = 0; j + 1 < n; j++) {
          sum[location[i][j]][0]++;
          if (s[i][j] == 'L') swapCounterClockwise(i,j);
          else if (s[i][j] == 'R') swapClockwise(i,j);
      }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) next[location[i][j]][0] = i * n + j;
    bigIntOperation();
    for (int iter = 1; iter < maxIter; iter++)
      for (int i = 0; i < m * n; i++) {
          next[i][iter] = next[next[i][iter - 1]][iter - 1];
          sum[i][iter] = (sum[i][iter - 1] + sum[next[i][iter - 1]][iter - 1]) % mod;
      }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) location[i][j] = i * n + j;
    for (int i = 0; i < m * n; i++) ret[i] = 0;
    for (int i = 0; i < m * n; i++) {
        int x = i;
        for (int iter = maxIter - 1; iter >= 0; iter--) if (binary[iter]) {
            ret[i] = (ret[i] + sum[x][iter]) % mod;
            x = next[x][iter];
        }
        location[x/n][x % n] = i;
    }
    for (int i = 0; i + 1 < m; i++)
      for (int j = 0; j + 1 < n; j++) if (fmodulo > 0) {
          fmodulo--;
          ret[location[i][j]] = (ret[location[i][j]] + 1) % mod;
          if (s[i][j] == 'L') swapCounterClockwise(i,j);
          else if (s[i][j] == 'R') swapClockwise(i,j);
      }
    for (int i = 0; i < m * n; i++) printf("%d\n", ret[i]);
}
