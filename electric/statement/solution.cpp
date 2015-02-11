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
#define maxp 25
using namespace std;

int m,n,p,Q;
pair<int,int> plant[maxp];
int cnt[105];

struct line {
    int fx,ya,yb,sign;
    inline line(int _fx,int _ya,int _yb,int _sign) {
        fx = _fx;
        ya = _ya;
        yb = _yb;
        sign = _sign;
    }
};

inline bool cmp(line A,line B) {
    return A.fx < B.fx;
}

inline long long countLess(int xa,int ya,int xb,int yb,int range) {
    if (xa > xb || ya > yb) return 0;
    if (range <= 0) return 0;
    vector<int> cordY;
    vector<line> cordX;

    cordX.push_back(line(0,0,0,0));
    for (int i = 0; i < p; i++) {
        int pa = max(xa,plant[i].first - range);
        int pb = min(xb,plant[i].first + range);
        int qa = max(ya,plant[i].second - range);
        int qb = min(yb,plant[i].second + range);
        if (pa > pb || qa > qb) continue;
        cordX.push_back(line(qa,pa,pb + 1,1));
        cordX.push_back(line(qb + 1,pa,pb + 1,-1));
        cordY.push_back(pa);
        cordY.push_back(pb + 1);
    }
    sort(cordX.begin(),cordX.end(),cmp);
    sort(cordY.begin(),cordY.end());
    cordY.erase(unique(cordY.begin(),cordY.end()),cordY.end());
    long long ans = 0;
    for (int i = 1; i < cordX.size(); i++) {
        int gap = cordX[i].fx - cordX[i - 1].fx,add = 0;
        if (gap) for (int j = 0; j < cordY.size(); j++) if (cnt[j]) add += cordY[j + 1] - cordY[j];
        ans += 1LL * gap * add;

        for (int j = 0; j < cordY.size(); j++)
          if (cordX[i].ya <= cordY[j] && cordY[j] < cordX[i].yb) cnt[j] += cordX[i].sign;
    }
    for (int i = 0; i < p; i++)
      if (xa <= plant[i].first && plant[i].first <= xb && ya <= plant[i].second && plant[i].second <= yb) ans--;
    return ans;
}

long long countEqual(int xa,int ya,int xb,int yb,int range) {
    return countLess(xa,ya,xb,yb,range) - countLess(xa,ya,xb,yb,range - 1);
}

void solve(long long number) {
    int low,high,ourColor = -1,ourRow = -1,ourCol = -1;
    low = 1;  high = max(m,n);
    while (low <= high) {
        int mid = (low + high)/2;
        if (countLess(1,1,m,n,mid) >= number) {
            ourColor = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    number -= countLess(1,1,m,n,ourColor - 1);
    low = 1;  high = m;
    while (low <= high) {
        int mid = (low + high)/2;
        if (countEqual(1,1,mid,n,ourColor) >= number) {
            ourRow = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    number -= countEqual(1,1,ourRow - 1,n,ourColor);
    low = 1;  high = n;
    while (low <= high) {
        int mid = (low + high)/2;
        if (countEqual(ourRow,1,ourRow,mid,ourColor) >= number) {
            ourCol = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    printf("%d %d\n", ourRow, ourCol);
}

int main() {
    while (1) {
        scanf("%d %d %d", &m, &n, &p);
        if (!m && !n && !p) return 0;
        for (int i = 0; i < p; i++) scanf("%d %d", &plant[i].first, &plant[i].second);
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            long long number;
            scanf("%lld", &number);
            solve(number);
        }
        printf("-\n");
    }
}
