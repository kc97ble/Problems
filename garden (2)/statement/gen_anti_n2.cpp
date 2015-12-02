#include <cstdio>
#include <cstdlib>
#include <cassert>

int main( int argc, char *argv[] ) {
  assert(argc == 2);
  int k = atoi(argv[1]);
  int t = (k - 2) / 2 / 3;
  int n = 2 + t * t + t;
  printf("%d %d %d\n", n, n, t * 6 + 2);
  printf("%.1lf %.1lf\n", t * 0.5, t * 0.5);
  printf("%.1lf %.1lf\n", (t + n) * 0.5, (t + n) * 0.5);
  for (int i = 0; i < t; i++) {
    printf("%.1lf %.1lf\n", t + 0.5, i + 0.5);
    printf("%.1lf %.1lf\n", n - 0.5, i + 0.5);
    printf("%.1lf %.1lf\n", i + 0.5, t + 0.5);
    printf("%.1lf %.1lf\n", i + 0.5, n - 0.5);
    printf("%.1lf %.1lf\n", t * (1.5 + i) + 1, t * 0.5);
    printf("%.1lf %.1lf\n", t * 0.5, t * (1.5 + i) + 1);
  }
  fprintf(stderr, "Универсальный тест против квадратичных решений, w=h=%d, n=%d",
    n, t * 6 + 2);
  return 0;
}
