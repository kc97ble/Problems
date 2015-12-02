#include <cstdio>
#include <cstdlib>

#include "random.h"

const int maxK = 200000;

int k;
long long x[maxK], y[maxK];

void gen( long long x0, long long y0, long long w, long long h, int p, bool need = false ) {
//  fprintf(stderr, "%.0lf %.0lf\n", (double)w, (double)h);
  if (w > h) {
    gen(x0, y0, h, h, p);
    gen(x0 + h, y0, w - h, h, p);
  } else if (w < h) {
    gen(x0, y0, w, w, p);
    gen(x0, y0 + w, w, h - w, p);
  } else {
    if (w <= 3 || (!need && R(0, 999) < p)) {
      assert(k < maxK);
      x[k] = 2 * x0 + w;
      y[k] = 2 * y0 + h;
      k++;
    } else {
      if (R(0, 1) == 0) {
        long long t = R(1ll, w - 1);
        gen(x0, y0, t, h, p);
        gen(x0 + t, y0, w - t, h, p);
      } else {
        long long t = R(1ll, h - 1);
        gen(x0, y0, w, t, p);
        gen(x0, y0 + t, w, h - t, p);
      }
    }
  }
}

int main( int argc, char *argv[] ) {
  assert(argc == 5);
  long long nx = atoll(argv[1]);
  long long ny = atoll(argv[2]);
  int p = atoi(argv[3]);
  int rs = atoi(argv[4]);
  initrand(rs);
  k = 0;
  gen(0, 0, nx, ny, p, true);
  printf("%.0lf %.0lf %d\n", (double)nx, (double)ny, k);
  for (long long i = 0; i < k; i++) {
    printf("%.1lf %.1lf\n", 0.5 * x[i], 0.5 * y[i]);
  }
  fprintf(stderr, "Случайное разбиение, w=%.0lf, h=%.0lf, n=%d", (double)nx, (double)ny, k);
  return 0;
}
