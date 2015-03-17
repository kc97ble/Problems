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

int main(int argc,char **argv) {
//  freopen("verdict","w",stdout);
  FILE* fa = fopen(argv[1],"r");
  FILE* fb = fopen(argv[2],"r");
  double sa,sb;
  fscanf(fa,"%lf",&sa);
  fscanf(fb,"%lf",&sb);
  if (abs(sa - sb) <= 1e-3) printf("OK\n"); else printf("Wrong answer\n");
}
