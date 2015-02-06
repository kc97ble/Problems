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

char sa[55][55],sb[55][55];
int na,nb;

bool compareChar(char* a,char* b) {
  int la = strlen(a),lb = strlen(b);
  while (la && (a[la - 1] < 'A' || a[la - 1] > 'Z')) la--;
  while (lb && (b[lb - 1] < 'A' || b[lb - 1] > 'Z')) lb--;
  if (la != lb) return false;
  for (int i = 0; i < la; i++) if (a[i] != b[i]) return false;
  return true;
}

string convert(int x) {
  stringstream w;  w << x;  return w.str();
}

int main() {
  freopen("detail.data","w",stdout);
  int correct = 0;
  for (int i = 0; i < 74; i++) {
    const char* fa = ("adict.expect." + convert(i)).c_str();
    FILE* ga = fopen(fa,"r");
    na = nb = 0;
    for (na = 0; ; na++) if (fscanf(ga,"%s\n",&sa[na]) == 1); else break;
    const char* fb = ("adict.out." + convert(i)).c_str();
    FILE* gb = fopen(fb,"r");
    for (nb = 0; ; nb++) if (fscanf(gb,"%s\n",&sb[nb]) == 1); else break;

    printf("Test %d: ", i);
    bool ok = (na == nb);
    if (na != nb) printf("Wrong output format\n"); else
      for (int j = 0; j < na; j++) if (!compareChar(sa[j],sb[j])) {
        ok = false;
	printf("Wrong answer on word %d: expected %s, found %s\n", j, sa[j], sb[j]);
	break;
      }
    if (ok) {
      correct++;
      printf("OK\n");
    }
  }
  fprintf(stderr,"%.2lf\n", 100.0 * correct/74);
}
