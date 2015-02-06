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

char expect[55][105],output[55][105];

int main() {
  freopen("detail.data","w",stdout);
  for (int i = 1; i <= 55; i++) {
    string A = convert(i);
    const char* ga = (A + ".a").c_str();
    FILE* fa = fopen(ga,"r");

    fscanf(fa,"%s", &expect[i]);
  }

   for (int i = 1; i <= 55; i++) {
    string A = convert(i);
    const char* ga = (A + ".out").c_str();
    FILE* fa = fopen(ga,"r");

    fscanf(fa,"%s", &output[i]);
  } 

  int score = 0;
  for (int i = 1; i <= 55; i++) {
    printf("Test %d: ", i);
    if (expect[i] != output[i]) printf("Wrong answer: Expected %s, Found %s\n", expect[i], output[i]);
    else {
      score++;
      printf("OK\n");
    }
  }
  fprintf(stderr,"%.2lf\n", 100.0 * score/55);
}
