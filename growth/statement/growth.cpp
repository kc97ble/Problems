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
#define point pair<int,int>
using namespace std;

int n;
point a[55];

int crossProduct(point A,point B,point C) {
  int ax = B.first - A.first,ay = B.second - A.second;
  int bx = C.first - B.first,by = C.second - B.second;
  return ax * by - ay * bx;
}

vector< point > convexHull() {
  vector< point > lower,upper;
  lower.push_back(a[0]);
  upper.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    int cross = crossProduct(a[0],a[i],a[n - 1]);
    if (i == n - 1 || cross > 0) {
      while (lower.size() > 1 && crossProduct(lower[lower.size() - 2],lower[lower.size() - 1],a[i]) <= 0) lower.pop_back();
      lower.push_back(a[i]);
    }
    if (i == n - 1 || cross < 0) {
      while (upper.size() > 1 && crossProduct(upper[upper.size() - 2],upper[upper.size() - 1],a[i]) >= 0) upper.pop_back();
      upper.push_back(a[i]);
    }
  }

  for (int i = upper.size() - 2; i > 0; i--) lower.push_back(upper[i]);
  return lower;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].second);
  sort(a,a + n);
  vector< point > p = convexHull();
  double ret = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    ret += 1.0 * (p[i].first * p[j].second - p[j].first * p[i].second);
  }
  printf("%.1lf\n", abs(ret)/2);
}
