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
  freopen("detail.data","w",stdout);
  int T = 119;
  double score = 0;
  for (int i = 0; i < T; i++) {
    printf("Test %d: ", i);
    vector<long long> ma,mb;
    long long x;
    
    const char* ga = ("pickup.expect." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    while (fscanf(fa, "%lld", &x) == 1) ma.push_back(x);

    const char* gb = ("pickup.out." + convert(i)).c_str();
    FILE* fb = fopen(gb,"r");
    while (fscanf(fb, "%lld", &x) == 1) mb.push_back(x);

    if (ma.size() != mb.size()) printf("Wrong output format\n"); else {
      printf("Optimal score: ");
      if (ma[0] != mb[0]) printf("Expected %lld, Found %lld\n", ma[0], mb[0]); {
        score += 0.4;
	printf("OK\n");
      }
      printf("Line up: ");
      bool ok = true;
      for (int j = 1; j < ma.size(); j++) if (ma[j] != mb[j]) {
        ok = false;
	printf("Wrong number %d: Expected %lld, Found %lld\n", j, ma[j], mb[j]);
	break;
      }
      if (ok) {
        printf("OK\n");
	score += 0.6;
      }
    }
  }
  fprintf(stderr,"%.2lf\n", 100.0 * score/T);
}
