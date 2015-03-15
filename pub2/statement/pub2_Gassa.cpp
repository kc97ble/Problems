#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
 
using namespace std;
const int MaxN = 500010;
 
class PubTrivia
{
private:
 long long x [MaxN], y [MaxN], z [MaxN], f [MaxN] [2];
 int n, t;
 
public:
 long long maximumScore (int N, int tokensNeeded, vector <int> p, vector <int> b)
 {
  int i, k, m, s;
  n = N;
  t = tokensNeeded;
 
  k = 0;
  m = p.size ();
  for (i = 0; i < n; i++)
  {
   x[i] = p[k];
   s = k + 1;
   if (s >= m) s -= m;
   p[k] = ((p[k] ^ p[s]) + 13) % 1001;
   k = s;
  }
 
  z[0] = 0;
  for (i = 1; i <= n; i++)
   z[i] = z[i - 1] + x[i - 1];
 
  k = 0;
  m = b.size ();
  for (i = 0; i < n; i++)
  {
   y[i] = b[k];
   s = k + 1;
   if (s >= m) s -= m;
   b[k] = ((b[k] ^ b[s]) + 13) % 10001;
   k = s;
  }
 
  memset (f, 192, sizeof (f));
  f[0][0] = 0;
  for (i = 1; i <= n; i++)
  {
   f[i][0] = max (f[i - 1][0], f[i - 1][1]) - x[i - 1];
   if (i >= t)
    f[i][0] = max (f[i][0], f[i - t][0] + (z[i] - z[i - t]) + y[i - 1]);
   f[i][1] = max (f[i - 1][0], f[i - 1][1]) + x[i - 1];
  }
 
  return max (f[n][0], f[n][1]);
 }
};

