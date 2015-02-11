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

string convert(int x) {
  stringstream w;  w << x;  return w.str();
}

vector<string> trans(string s) {
  string store = "";
  vector<string> v;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
      if (store.empty()) continue;
      v.push_back(store);
      store.clear();
    }
    else store += s[i];
  return v;
}

int main() {
  freopen("errant.data","r",stdin);
  for (int it = 0; it < 75; it++) {
    string a,b,c;
    cin >> a >> b >> c;
    vector<string> fa = trans(a);
    vector<string> fb = trans(b);
    
    FILE* aa = fopen((convert(it) + ".in").c_str(),"w");
    fprintf(aa,"%d\n", fa.size());
    for (int i = 0; i < fa.size(); i++) {
      for (int j = 0; j < fa[i].size(); j++) fprintf(aa,"%c",fa[i][j]);
      fprintf(aa," ");
    }
    fprintf(aa,"\n");
    for (int i = 0; i < fb.size(); i++) {
      for (int j = 0; j < fb[i].size(); j++) fprintf(aa,"%c",fb[i][j]);
      fprintf(aa," ");
    }

    FILE* ab = fopen((convert(it) + ".out").c_str(),"w");
    for (int i = 0; i < c.size(); i++) fprintf(ab,"%c",c[i]);
    fprintf(ab,"\n");
  }
}
