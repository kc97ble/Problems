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

long long a[10];

string convert(int x) {
  stringstream w;
  w << x;
  return w.str();
}

int main() {
  freopen("points.txt","r",stdin);
  for (int it = 1; cin >> a[0] ; it++) {
    for (int j = 1; j < 10; j++) cin >> a[j];
    FILE* fa = fopen((convert(it) + ".in").c_str(),"w");
    for (int j = 0; j < 9; j++) fprintf(fa,"%lld ", a[j]);
    FILE* fb = fopen((convert(it) + ".out").c_str(),"w");
    fprintf(fb,"%lld\n", a[9]);
  }
}
