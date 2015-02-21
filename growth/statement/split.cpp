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

vector<int> x,y;

string convert(int p) {
  stringstream w;  w << p;  return w.str();
}

vector<int> trans(string s) {
  vector<int> w;
  string store = "";
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
      if (store.empty()) continue;
      stringstream mm;  mm << store;
      int pp;  mm >> pp;
      w.push_back(pp);
      store.clear();
    }
    else store += s[i];
  return w;
}

int main() {
  freopen("growth.dat","r",stdin);
  for (int i = 0; i < 58; i++) {
    string a,b,c;
    cin >> a >> b >> c;
    x = trans(a);  y = trans(b);
    int n = x.size();
    FILE* fa = fopen((convert(i) + ".in").c_str(),"w");
    fprintf(fa,"%d\n", n);
    for (int i = 0; i < n; i++) fprintf(fa,"%d ", x[i]);
    fprintf(fa,"\n");
    for (int i = 0; i < n; i++) fprintf(fa,"%d ", y[i]);
  }
}
