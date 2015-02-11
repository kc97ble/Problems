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

string convert(int x) {
  stringstream w;
  w << x;
  return w.str();
}

int main() {
  return 0;
  freopen("data.txt","r",stdin);
  int it = 0,a[5];
  while (cin >> a[0]) {
    it++;
    for (int i = 1; i < 5; i++) cin >> a[i];
    FILE* fa = fopen((convert(it) + ".in").c_str(),"w");
    for (int i = 0; i < 4; i++) fprintf(fa,"%d ", a[i]);
    FILE* fb = fopen((convert(it) + ".out").c_str(),"w");
    fprintf(fb,"%d", a[4]);
  }
}
