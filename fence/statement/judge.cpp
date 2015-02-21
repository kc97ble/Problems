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
  for (int i = 1; i <= 15; i++) {
    const char* ga = ("fence." + convert(i) + ".out").c_str();
    FILE* fa = fopen(ga,"r");
    int aa;
    fscanf(fa,"%d", &aa);
    const char* gb = ("fence." + convert(i) + ".ans").c_str();
    FILE* fb = fopen(gb,"r");
    int ab;
    fscanf(fb,"%d", &ab);

    printf("Test %d: ", i);
    if (aa == ab) {
      printf("OK\n");
      nTest++;
    }
    else printf("Wrong answer: Expected %d, Found %d\n", aa, ab);
  }
  fprintf(stderr,"%.2lf\n", 1.0 * nTest/15 * 100);
}
