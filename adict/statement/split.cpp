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

vector<string> parse(string s) {
  string store = "";
  vector<string> ans;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
      if (!store.empty()) {
        ans.push_back(store);
	store.clear();
      }
    }
    else store += s[i];
  return ans;
}

int main() {
  freopen("adict.txt","r",stdin);
  for (int it = 0; ; it++) {
    string a,b,c,d;
    if (!(cin >> a >> b >> c >> d)) return 0;
    const char* fa = ("adict.in." + convert(it)).c_str();
    FILE* ga = fopen(fa,"w");
    
    fprintf(ga,"%s\n", a.c_str());
    vector<string> hb = parse(b);
    fprintf(ga,"%d\n", hb.size());
    for (int i = 0; i < hb.size(); i++) {
      fprintf(ga,"%s", hb[i].c_str());
      if (i + 1 < hb.size()) fprintf(ga," "); else fprintf(ga,"\n");
    }
    vector<string> hc = parse(c);
    fprintf(ga,"%d\n", hc.size());
    for (int i = 0; i < hc.size(); i++) {
      fprintf(ga,"%s", hc[i].c_str());
      if (i + 1 < hc.size()) fprintf(ga," "); else fprintf(ga,"\n");
    }

    const char* fb = ("adict.expect." + convert(it)).c_str();
    FILE* gb = fopen(fb,"w");
    vector<string> hd = parse(d);
    for (int i = 0; i < hd.size(); i++)
      fprintf(gb,"%s\n", hd[i].c_str());
  }
}
