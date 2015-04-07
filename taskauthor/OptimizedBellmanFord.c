#include <stdio.h>

#define INF 1000000000

int i, j, u, vv, w_u_vv, V, n, w, Q, counter, s, t;
int dist[1000];
int AdjList[1000][1000];
int weight[1000][1000];
int sz[1000];
int change;





int main() {
  scanf("%d", &V);
  for (i = 0; i < V; i++) {
    scanf("%d", &n);
    sz[i] = 0;
    while (n--) {
      scanf("%d %d", &j, &w);
      AdjList[i][sz[i]] = j;
      weight[i][sz[i]] = w;
      sz[i]++;
    }
  }

  counter = 0;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d %d", &s, &t);
    for (i = 0; i < V; i++) dist[i] = INF;
    dist[s] = 0;

    for (i = 0; i < V-1; i++) {
      change = 0;
      for (u = 0; u < V; u++)
        for (j = 0; j < sz[u]; j++) {
          counter++;
          if (counter > 1000000) {
            printf("TLE because iteration counter > 1000000\n");
            return 1;
          }

          vv = AdjList[u][j];
          w_u_vv = weight[u][j];
          if (dist[u] + w_u_vv < dist[vv]) {
            dist[vv] = dist[u] + w_u_vv;
            change = 1;
          }
        }

      if (!change) // the optimized BellmanFord
        break;
    }

    printf("%d\n", dist[t]);
  }

  printf("The value of counter is: %d\n", counter);
  return 0;
}
