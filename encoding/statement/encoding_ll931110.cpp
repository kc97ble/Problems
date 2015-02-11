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
using namespace std;

int m;
int f[10002];
int pivot[10002];

void recurse(string pre,int rem) {
  if (rem == 1) {
    cout << pre << endl;
    return;
  }  
  recurse(pre + "0",pivot[rem]);
  recurse(pre + "1",rem - pivot[rem]);
}

int main() {
  freopen("binary.in","r",stdin);
  freopen("binary.out","w",stdout);
  scanf("%d", &m);
  if (m == 1) {
    printf("0");
    return 0;
  }
  f[1] = 1;
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j + j <= i; j++) {
      int tmp = f[i - j] + f[j];
      if (!f[i] || f[i] > tmp) {
        f[i] = tmp;
        pivot[i] = j;
      }
    }
    f[i] += i;
  }
  recurse("",m);
}
