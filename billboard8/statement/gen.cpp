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
  stringstream w;   w << x;  return w.str();
}

int main() {
  freopen("data.txt","r",stdin);
  int T = 0;
  string a,b;
  while (cin >> a >> b) {
    T++;
    FILE* fa = fopen((convert(T) + ".in").c_str(),"w");    
    vector<string> grid;
    string c = "";
    for (int i = 0; i < a.size(); i++) if (a[i] == ',') {
      grid.push_back(c);
      c.clear();
    }
    else c += a[i];
    grid.push_back(c);
    fprintf(fa,"%d %d", grid.size(), grid[0].size());
    for (int i = 0; i < grid.size(); i++) fprintf(fa,"%s\n", grid[i].c_str());
    
    FILE* fb = fopen((convert(T) + ".out").c_str(),"w");
    fprintf(fb,"%s\n", b.c_str());
  }
}
