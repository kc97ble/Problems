#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
 
#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
 
using namespace std;
 
typedef long long lli;
 
static const double EPS = 1e-5;
 
const int N = 50 + 1;
const int A = 0, B = 1, C = 2, D = 3;
const int LAST = 4, FIRST = 4;
 
lli memo[FIRST][LAST][N][N][N];
 
const lli mod = 1000000007;
 
lli rec(int first, int last, int a, int b, int c)
{
  lli &ret = memo[first][last][a][b][c];
  if (ret != -1) return ret;
  if (a == 0 && b == 0 && c == 0) {
    return last != first;
  }
 
  lli sum = 0;
 
  if (first == D) {
    if (a) sum = (sum + rec(A, A, a - 1, b, c)) % mod;
    if (b) sum = (sum + rec(B, B, a, b - 1, c)) % mod;
    if (c) sum = (sum + rec(C, C, a, b, c - 1)) % mod;
  } else {
    if (last == A) {
      if (b) sum = (sum + rec(first, B, a, b - 1, c)) % mod;
      if (c) sum = (sum + rec(first, C, a, b, c - 1)) % mod;
    }
    if (last == B) {
      if (a) sum = (sum + rec(first, A, a - 1, b, c)) % mod;
      if (c) sum = (sum + rec(first, C, a, b, c - 1)) % mod;
    }
    if (last == C) {
      if (a) sum = (sum + rec(first, A, a - 1, b, c)) % mod;
      if (b) sum = (sum + rec(first, B, a, b - 1, c)) % mod;
    }
  }
 
  return ret = sum;
}
 
class ColorfulCupcakesDivTwo {
public:
  int countArrangements(string C)
  {
    int a = count(C.begin(), C.end(), 'A');
    int b = count(C.begin(), C.end(), 'B');
    int c = count(C.begin(), C.end(), 'C');
 
    fill(&memo[0][0][0][0][0], &memo[FIRST][0][0][0][0], -1);
    return rec(D, D, a, b, c) % mod;
  }