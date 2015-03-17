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

int main() {
  freopen("data.txt","r",stdin);  
  long long a[10],T = 0;
  while (cin >> a[0]) {
    T++;
    for (int i = 1; i < 10; i++) cin >> a[i];
    FILE* fa = fopen((convert(T) + ".in").c_str(),"w");
    for (int i = 0; i < 9; i++) fprintf(fa,"%lld ", a[i]);
    FILE* fb = fopen((convert(T) + ".out").c_str(),"w");
    fprintf(fb,"%lld", a[9]);
  }
}
