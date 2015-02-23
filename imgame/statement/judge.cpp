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
  int score = 0;
  int T = 153;
  vector<long long> expect,output;
  for (int i = 0; i < T; i++) {
    const char* ga = ("imgame.expect." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    long long ret;
    fscanf(fa,"%lld", &ret);
    expect.push_back(ret);
  }

  for (int i = 0; i < T; i++) {
    const char* ga = ("imgame.out." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    long long ret;
    fscanf(fa,"%lld", &ret);
    output.push_back(ret);
  }

  for (int i = 0; i < T; i++) {
    printf("Test %d: ", i);
    if (expect[i] == output[i]) {
      score++;
      printf("OK\n");
    }
    else printf("Wrong answer: expected %lld, found %lld\n", expect[i], output[i]);
  }
  fprintf(stderr,"Total score: %.2lf\n", 100.0 * score/T);
}
