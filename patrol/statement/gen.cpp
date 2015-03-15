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

string co(int i) {
  stringstream w;  w << i;  return w.str();
}

int main() {
  freopen("input.txt","r",stdin);
  string a,b;
  for (int it = 0; cin >> a >> b; it++) {
    for (int i = 0; i < a.size(); i++) if (a[i] == ',') a[i] = ' ';    
    FILE* fa = fopen((co(it) + ".in").c_str(),"w");
    for (int i = 0; i < a.size(); i++) fprintf(fa,"%c", a[i]);
    FILE* fb = fopen((co(it) + ".out").c_str(),"w");
    for (int i = 0; i < b.size(); i++) fprintf(fb,"%c", b[i]);
  }
}
