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
  stringstream w;  w << x;  return w.str();
}

vector<string> parse(string s) {
  vector<string> v;
  string u = "";
  for (int i = 0; i < s.size(); i++) if (s[i] == ',') {
    if (u.empty()) continue;
    v.push_back(u);
    u.clear();
  }
  else u += s[i];
  if (!u.empty()) v.push_back(u);
  return v;
}

int main() {
  freopen("trisub.txt","r",stdin);
  int T = 0;
  string a,b;
  while (cin >> a >> b) {
    T++;
    vector<string> va = parse(a);
    FILE* fa = fopen((convert(T) + ".in").c_str(),"w");
    fprintf(fa,"%d\n", va.size());
    for (int i = 0; i < va.size(); i++) fprintf(fa,"%s\n",va[i].c_str());
    FILE* fb = fopen((convert(T) + ".out").c_str(),"w");
    fprintf(fb,"%s\n",b.c_str());
  }
}
