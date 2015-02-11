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
  vector<double> expect,output;
  for (int i = 0; i < 10; i++) {
    const char* ga = ("ecircle.expect." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    double ret;
    fscanf(fa,"%lf", &ret);
    expect.push_back(ret);
  }

  for (int i = 0; i < 10; i++) {
    const char* ga = ("ecircle.out." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    double ret;
    fscanf(fa,"%lf", &ret);
    output.push_back(ret);
  }

  for (int i = 0; i < 10; i++) {
    printf("Test %d: ", i);
    if (expect[i] == output[i]) {
      score += 10;
      printf("OK\n");
    }
    else printf("Wrong answer: expected %.3lf, found %.3lf\n", expect[i], output[i]);
  }
  fprintf(stderr,"Total score: %d\n", score);
}
