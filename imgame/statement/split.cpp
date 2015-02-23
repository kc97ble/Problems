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

long long toInt(string s) {
  stringstream w;  w << s;  long long x;  w >> x;  return x;
}

string toString(int x) {
  stringstream w;  w << x;  return w.str();
}

vector<string> parse(string s) {
  vector<string> m;
  string store = "";
  for (int i = 0; i < s.size(); i++)
    if ('A' <= s[i] && s[i] <= 'D') store += s[i]; else if (!store.empty()) {
      m.push_back(store);
      store.clear();
    }
  return m;
}

int main() {
  freopen("imgame.data","r",stdin);
  int T = 153;
  for (int it = 0; it < T; it++) {
    string a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];
    vector<string> before = parse(a[1]);
    vector<string> after = parse(a[2]);
    long long n = toInt(a[0]),ret = toInt(a[3]);

    const char* ga = ("imgame.in." + toString(it)).c_str();
    FILE* fa = fopen(ga,"w");
    fprintf(fa,"%lld %d\n", n, (int) before.size());
    for (int i = 0; i < before.size(); i++) {
      for (int j = 0; j < before[i].size(); j++) fprintf(fa,"%c",before[i][j]);
      fprintf(fa," ");
    }
    fprintf(fa,"\n");
    for (int i = 0; i < after.size(); i++) {
      for (int j = 0; j < after[i].size(); j++) fprintf(fa,"%c",after[i][j]);
      fprintf(fa," ");
    }

    const char* gb = ("imgame.expect." + toString(it)).c_str();
    FILE* fb = fopen(gb,"w");
    fprintf(fb,"%lld\n", ret);
  }
}
