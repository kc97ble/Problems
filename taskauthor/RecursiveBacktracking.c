#include <stdio.h>

#define INF 1000000000

int i, a, b, V, E, counter, X;
int cur[1000], ans[1000], sz[1000];
int AdjList[1000][1000];
int found;






void backtrack(int u, int label) {
  int j, vv;
  int ok[1000];
  if (found) return;

  counter++;
  cur[u] = label; // assign label to u
  if (u == V - 1) { // done
    found = 1;

    for (j = 0; j < V; j++)
      ans[j] = cur[j];
    return;
  }

  // explore neighbors
  for (j = 0; j < X; j++)
    ok[j] = 1;
  for (j = 0; j < sz[u+1]; j++) {
    counter++;
    if (counter > 1000000)
      return;

    vv = AdjList[u+1][j];
    if (cur[vv] != -1)
      ok[cur[vv]] = 0;
  }

  for (j = 0; j < X; j++)
    if (ok[j])
      backtrack(u+1, j);
}

int main() {
  scanf("%d %d", &V, &E);

  for (i = 0; i < E; i++) {
    scanf("%d %d", &a, &b);
    AdjList[a][sz[a]++] = b;
    AdjList[b][sz[b]++] = a;
  }

  found = 0;
  counter = 0;
  for (X = 2; X <= V; X++) {
    for (i = 0; i < V; i++) cur[i] = -1;
    backtrack(0, 0);
    if (found)
      break;

    if (counter > 1000000) {
      printf("TLE\n");
      return 1;
    }
  }

  printf("%d\n", X);
  printf("%d", ans[0]);
  for (i = 1; i < V; i++)
    printf(" %d", ans[i]);
  printf("\n");

  printf("The value of counter is: %d\n", counter);
  return 0;
}
