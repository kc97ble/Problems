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
  w << x;  return w.str();
}

vector<string> parse(string s) {
  string u = "";
  vector<string> v;
  for (int i = 0; i < s.size(); i++)
    if ('A' <= s[i] && s[i] <= 'Z') u += s[i]; else if (!u.empty()) {
      v.push_back(u);
      u.clear();
    }
  if (!u.empty()) v.push_back(u);
  return v;
}

int main() {
  freopen("cardrm_testdata.txt","r",stdin);
  int T = 0;
  string a,b;
  while (cin >> a >> b) {
    T++;
    vector<string> fa = parse(a);
    FILE* ga = fopen((convert(T) + ".in").c_str(),"w");
    fprintf(ga,"%d\n", fa.size());
    for (int i = 0; i < fa.size(); i++) fprintf(ga,"%s\n", fa[i].c_str());
    FILE* gb = fopen((convert(T) + ".out").c_str(),"w");
    fprintf(gb,"%s",b.c_str());
  }
}
