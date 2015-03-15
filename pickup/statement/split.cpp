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

vector<long long> parse(string s) {
  vector<long long> f;
  string store = "";
  for (int i = 0; i < s.size(); i++) if ('0' <= s[i] && s[i] <= '9') store += s[i]; else if (!store.empty()) {
    stringstream w;  w << store;
    long long x;  w >> x;  f.push_back(x);
    store.clear();
  }
  return f;
}

string convert(int x) {
  stringstream w;  w << x;  return w.str();
}

vector<long long> d[120][3];

int main() {
  freopen("pickup.data","r",stdin);
  int T = 119;
  for (int it = 0; it < T; it++) {
    string a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) d[it][i] = parse(a[i]);
  }
  for (int it = 0; it < T; it++) {
    const char* fa = ("pickup.in." + convert(it)).c_str();
    FILE* ga = fopen(fa,"w");
    int n = d[it][0].size();
    fprintf(ga,"%d\n", n);
    for (int i = 0; i < n; i++) fprintf(ga,"%lld %lld\n", d[it][0][i], d[it][1][i]);
  }
  for (int it = 0; it < T; it++) {
    const char* fa = ("pickup.expect." + convert(it)).c_str();
    FILE* ga = fopen(fa,"w");
    int n = d[it][0].size();
    long long diff = 0;
    for (int i = 0; i < n; i++) if (d[it][2][i] == 1) diff += d[it][0][i]; else diff -= d[it][1][i];
    fprintf(ga,"%lld\n", abs(diff));
    for (int i = 0; i < n; i++) fprintf(ga,"%lld ", d[it][2][i]);
    fprintf(ga,"\n");
  }
}
