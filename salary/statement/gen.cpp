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

void create(int n,int k,int p,int idx) {
  const char* ga = ("salary.in." + convert(idx)).c_str();
  FILE* fa = fopen(ga,"w");
  fprintf(fa,"%d %d %d\n", n, k, p);
}

int main() {
  for (int i = 0; i < 10; i++) {
    int n = rand() % 50 + 1;
    int k = rand() % 50 + 1;
    int p = rand() % (int) (1e9) + 1;
    create(n,k,p,i);
  }
  for (int i = 10; i < 20; i++) {
    int n = rand() % 1000 + 1;
    int k = rand() % 200 + 1;
    int p = rand() % (int) (1e9) + 1;
    create(n,k,p,i);
  }
}
