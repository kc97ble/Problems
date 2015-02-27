    #include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TheLuckyNumbersLevelThree {
public:
  vector <long long> find(long long, long long);
};

long long f[20][4][7][2][2];
long long s[20][4][7][2][2][10];

vector <long long> TheLuckyNumbersLevelThree::find(long long a, long long b) {
  int i;
  if (a > 1) {
    vector <long long> ret = find(1,b), ret2 = find(1,a-1);
    for (i=0;i<10;i++) ret[i] -= ret2[i];
    return ret;
  }
  vector <long long> ret;
  ret.clear();
  for (i=0;i<10;i++) ret.push_back(0);
  if (b < 4) return ret;
  int kd, d[50];
  kd = 0;
  while (b) {
    d[kd++] = b % 10;
    b /= 10;
  }
  memset(f,0,sizeof(f));
  memset(s,0,sizeof(s));
  f[kd][0][0][0][1] = 1;
  int j4, j7, p, rg, n4, n7, np, c, q, w, nw;
  for (i=kd;i>0;i--)
    for (j4=0;j4<4;j4++)
      for (j7=0;j7<7;j7++)
        for (w=0;w<2;w++)
          for (p=0;p<2;p++)
            if (f[i][j4][j7][w][p]) {
              if (p == 1) rg = d[i-1];
              else rg = 9;
              for (c=0;c<=rg;c++) {
                n4 = (j4*10+c) % 4;
                n7 = (j7*10+c) % 7;
                np = p & (c == rg);
                nw = w | (c > 0);
                f[i-1][n4][n7][nw][np] += f[i][j4][j7][w][p];
                for (q=0;q<10;q++) s[i-1][n4][n7][nw][np][q] += s[i][j4][j7][w][p][q];
                if (nw) s[i-1][n4][n7][nw][np][c] += f[i][j4][j7][w][p];
              }
            }
  for (j4=0;j4<4;j4++)
    for (j7=0;j7<7;j7++)
      if (!j4 || !j7)
        for (w=0;w<2;w++)
          for (p=0;p<2;p++)
            for (q=0;q<10;q++) ret[q] += s[0][j4][j7][w][p][q];
  return ret;
}


//Powered by [KawigiEdit] 2.0!