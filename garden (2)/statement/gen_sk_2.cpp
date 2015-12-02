/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }
template <class T> inline void relaxMin( T &a, T b ) { a = min(a, b); }
template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

string str( int i ) { char s[100]; sprintf(s, "%d", i); return string(s); }

inline int sign( int x ) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
inline int myAbs( int a ) { return a > 0 ? a : -a; }

#include "random.h"

vector <dbl> x, y;
int p;

void Gen( int lx, int rx, int ly, int ry, int dep )
{
  if ((rx - lx) % 6 != 0 || (dep >= 1 && R(0, 999) < p))
  {
    x.pb((lx + rx) * 0.5);
    y.pb((ly + ry) * 0.5);
    return;
  }
  int dx = (rx - lx) / 6;
  int dy = (ry - ly) / 6;

  #define GEN(a, b, c, d) Gen(lx + dx * (a), lx + dx * (b), ly + dy * (c), ly + dy * (d), dep + 1)

  GEN(0, 1, 0, 1);
  GEN(0, 1, 1, 2);
  GEN(1, 3, 0, 2);
  GEN(0, 2, 2, 4);
  GEN(0, 2, 4, 6);
  GEN(3, 6, 0, 3);
  GEN(2, 3, 2, 3);
  GEN(2, 5, 3, 6);
  GEN(5, 6, 3, 4);
  GEN(5, 6, 4, 5);
  GEN(5, 6, 5, 6);
}

int main( int argc, char *argv[] )
{
  if (argc < 4)
  {
    puts("Usage: <seed for random> <n> <p=0..1000>");
    puts("[seed == 0] => Time()");
    return 0;
  }

  int seed = atoi(argv[1]);
  int n = atoi(argv[2]);
  p = atoi(argv[3]);

  initrand(seed ? seed : Time());

  int N = 1;
  while (n--)
    N *= 6;
  Gen(0, N, 0, N, 0);
  printf("%d %d %d\n", N, N, sz(x));
  forn(i, sz(x))
    printf("%.1lf %.1lf\n", x[i], y[i]);
  fprintf(stderr, "Случайное двоично-фрактальное разбиение второго вида, w=h=%d, n=%d", N, sz(x));
  return 0;
}
