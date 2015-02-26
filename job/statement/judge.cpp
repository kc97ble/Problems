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

int main() {
  int nTest = 0;
  for (int i = 1; i <= 12; i++) {
    const char* ga = ("job." + convert(i) + ".out").c_str();
    FILE* fa = fopen(ga,"r");
    long long aa;
    fscanf(fa,"%lld", &aa);
    const char* gb = ("job." + convert(i) + ".ans").c_str();
    FILE* fb = fopen(gb,"r");
    long long ab;
    fscanf(fb,"%lld", &ab);

    printf("Test %d: ", i);
    if (aa == ab) {
      printf("OK\n");
      nTest++;
    }
    else printf("Wrong answer: Expected %lld, Found %lld\n", aa, ab);
  }
  fprintf(stderr,"%.2lf\n", 1.0 * nTest/12 * 100);
}
