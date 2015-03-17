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
#define maxn 1005
using namespace std;

bool forbid[maxn][maxn];
pair<int,int> D[maxn][maxn],R[maxn][maxn],DR[maxn][maxn];
int T,n,k;

int main() {
//    freopen("d.in.1","r",stdin);
//    freopen("d.expect.1","w",stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        memset(forbid,false,sizeof(forbid));
        for (int i = n - k; i <= n + k; i++)
          for (int j = n - k; j <= n + k; j++) forbid[i][j] = true;
        int m = n + n;
        for (int i = 0; i <= m; i++)
          for (int j = 0; j <= m; j++) D[i][j] = R[i][j] = DR[i][j] = make_pair(-1,-1);

        for (int i = m - 1; i >= 0; i--)
          for (int j = 0; j <= m; j++) {
              if (forbid[i][j]) D[i][j].first = 0; else if (D[i + 1][j].first >= 0) D[i][j].first = 1 + D[i + 1][j].first;
              if (D[i + 1][j].second >= 0) D[i][j].second = 1 + D[i + 1][j].second; else if (forbid[i][j]) D[i][j].second = 0;
          }
        for (int j = m - 1; j >= 0; j--)
          for (int i = 0; i <= m; i++) {
              if (forbid[i][j]) R[i][j].first = 0; else if (R[i][j + 1].first >= 0) R[i][j].first = 1 + R[i][j + 1].first;
              if (R[i][j + 1].second >= 0) R[i][j].second = 1 + R[i][j + 1].second; else if (forbid[i][j]) R[i][j].second = 0;
          }
        for (int i = m - 1; i >= 0; i--)
          for (int j = m - 1; j >= 0; j--) {
              if (forbid[i][j]) DR[i][j].first = 0; else if (DR[i + 1][j + 1].first >= 0) DR[i][j].first = 1 + DR[i + 1][j + 1].first;
              if (DR[i + 1][j + 1].second >= 0) DR[i][j].second = 1 + DR[i + 1][j + 1].second; else if (forbid[i][j]) DR[i][j].second = 0;
          }

        int ret = 0;
        for (int i = 0; i <= m; i++)
          for (int j = 0; j <= m; j++) if (!forbid[i][j]) {
              ret += min(m - j,m - i);
              int lower = maxn,higher = -maxn;
              if (D[i][j].first >= 0) lower = min(lower,D[i][j].first);
              if (R[i][j].first >= 0) lower = min(lower,R[i][j].first);
              if (DR[i][j].first >= 0) lower = min(lower,DR[i][j].first);
              if (D[i][j].second >= 0) higher = max(higher,D[i][j].second);
              if (R[i][j].second >= 0) higher = max(higher,R[i][j].second);
              if (DR[i][j].second >= 0) higher = max(higher,DR[i][j].second);
              higher = min(higher,min(m - j,m - i));
              lower = max(lower,1);
              if (higher >= lower) ret -= (higher - lower + 1);
          }
        printf("%d\n", ret);
    }
}
