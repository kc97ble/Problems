#include <stdio.h>
#include <string.h>

#define INF 1000000000

int i, j, V, n, w, counter, Q, s, t, d, u, vv, w_u_vv;
int AdjList[1000][1000], weight[1000][1000];
int sz[1000], dist[1000];

struct p {
  int d, u;
};
struct p front;

//====================================================
// Start of Binary Heap implementation  
struct p A[1000];
int BinaryHeapSize;

int smaller(struct p *a, struct p *b) {
  if (a->d != b->d)
    return a->d < b->d;
  else
    return a->u < b->u;
}

int parent(int i) { return i >> 1; } // shortcut for i / 2, round down

int left(int i) { return i << 1; } // shortcut for 2 * i

int right(int i) { return (i << 1) + 1; } // shortcut for 2 * i + 1

void Initialize() {
  A[0].d = A[0].u = 0; // dummy
  BinaryHeapSize = 0;
}

void shiftUp(int i) {
  struct p temp;
  while (i > 1 && smaller(&A[i], &A[parent(i)])) {
    temp = A[i];
    A[i] = A[parent(i)];
    A[parent(i)] = temp;
    i = parent(i);
  }
}

void Enqueue(int _d, int _u) {
  BinaryHeapSize++;
  A[BinaryHeapSize].d = _d;
  A[BinaryHeapSize].u = _u;
  shiftUp(BinaryHeapSize);
}

void shiftDown(int i) {
  struct p minV, temp;
  int min_id;
  while (i <= BinaryHeapSize) {
    minV = A[i]; min_id = i;
    if (left(i) <= BinaryHeapSize && smaller(&A[left(i)], &minV)) {
      minV = A[left(i)];
      min_id = left(i);
    }
    if (right(i) <= BinaryHeapSize && smaller(&A[right(i)], &minV)) {
      minV = A[right(i)];
      min_id = right(i);
    }

    if (min_id != i) {
      temp = A[i];
      A[i] = A[min_id];
      A[min_id] = temp;
      i = min_id;
    }
    else
      break;
  }
}
  
struct p Dequeue() {
  struct p minV = A[1];
  A[1] = A[BinaryHeapSize];
  BinaryHeapSize--; // virtual decrease
  shiftDown(1);
  return minV;
}

int isEmpty() { return BinaryHeapSize == 0; }
// End of Binary Heap implementation  
//====================================================

int main() {
  scanf("%d", &V);
  for (i = 0; i < V; i++) {
    scanf("%d", &n);
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
    Initialize();
    Enqueue(0, s);
    while (!isEmpty()) {
      counter++;
      if (counter > 1000000) {
        printf("TLE because iteration counter > 1000000\n");
        return 1;
      }

      front = Dequeue();
      d = front.d; u = front.u;
      if (d == dist[u]) {
        for (j = 0; j < sz[u]; j++) {
          vv = AdjList[u][j]; w_u_vv = weight[u][j];
          if (dist[u] + w_u_vv < dist[vv]) {
            dist[vv] = dist[u] + w_u_vv;
            Enqueue(dist[vv], vv);
          }
        }
      }
    }

    printf("%d\n", dist[t]);
  }

  printf("The value of counter is: %d\n", counter);
  return 0;
}
