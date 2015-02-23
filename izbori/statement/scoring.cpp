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

int n[10];
vector<int> expect[10],output[10];

string convert(int x) {
  stringstream w;  w << x;  return w.str();
}

int main() {
  freopen("detail.data","w",stdout);
  for (int i = 0; i < 10; i++) {
    const char* ga = ("izbori.in." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    int x;
    fscanf(fa,"%d %d", &x, &n[i]);
  }
  for (int i = 0; i < 10; i++) {
    const char* ga = ("izbori.expect." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    int x;
    while (fscanf(fa,"%d", &x) == 1) expect[i].push_back(x);
  }
  for (int i = 0; i < 10; i++) {
    const char* ga = ("izbori.out." + convert(i)).c_str();
    FILE* fa = fopen(ga,"r");
    int x;
    while (fscanf(fa,"%d", &x) == 1) output[i].push_back(x);
  }

  int score = 0;
  for (int i = 0; i < 10; i++) {
    printf("Test %d\n", i);
    if (expect[i].size() != output[i].size()) {
      printf("Incorrect output format\n");
      continue;
    }
    bool part1 = true,part2 = true;
    printf("Part 1: ");
    for (int j = 0; j < n[i]; j++) if (expect[i][j] != output[i][j]) {
      part1 = false;
      printf("Wrong answer on number %d: expected %d, found %d\n", j, expect[i][j], output[i][j]);
      break;
    }
    if (part1) printf("OK\n");
    printf("Part 2: ");
    for (int j = n[i]; j < 2 * n[i]; j++) if (expect[i][j] != output[i][j]) {
      part2 = false;
      printf("Wrong answer on number %d: expected %d, found %d\n", j - n[i], expect[i][j], output[i][j]);
    }
    if (part2) printf("OK\n");

    if (part1) score += 2;
    if (part2) score += 8;
  }
  fprintf(stderr, "Total score: %d\n", score);
}
