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

int s[10];

int main() {
  freopen("leastturn.txt","r",stdin);
  for (int it = 1; cin >> s[0]; it++) {
    for (int i = 1; i < 10; i++) cin >> s[i];
    string sa = convert(it) + ".in";
    FILE* fa = fopen(sa.c_str(),"w");
    for (int i = 0; i < 9; i++) fprintf(fa,"%d ", s[i]);
    string sb = convert(it) + ".out";
    FILE* fb = fopen(sb.c_str(),"w");
    fprintf(fb,"%d", s[9]);
  }
}
