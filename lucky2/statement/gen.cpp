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

int main() {
  freopen("data.txt","r",stdin);
  int T = 0;
  string a,b;
  while (cin >> a >> b) {
    T++;
    vector<string> s;
    string f = "";
    for (int i = 1; i + 1 < a.size(); i++)
      if (a[i] == ',') {
        s.push_back(f);
	f.clear();
      }
      else f += a[i];
    s.push_back(f);
    FILE* fa = fopen((convert(T) + ".in").c_str(),"w");
    fprintf(fa,"%d\n", s.size());
    for (int i = 0; i < s.size(); i++) fprintf(fa,"%s ", s[i].c_str());

    FILE* fb = fopen((convert(T) + ".out").c_str(),"w");
    for (int i = 0; i < b.size(); i++) if (b[i] == ',') b[i] = ' ';
    for (int i = 1; i + 1 < b.size(); i++) fprintf(fb,"%c",b[i]);
  }
}
