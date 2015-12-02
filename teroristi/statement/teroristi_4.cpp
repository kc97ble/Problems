/* Author: Tiberiu Savin
 * Expected score: 100
 */
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 1000005
#define SMAX 28
#define INF 0x3f3f3f3f
#define PRINT_DEBUG false

char s[NMAX];
int N, M, D, S;
int C[SMAX * SMAX][SMAX * SMAX], F[SMAX * SMAX][SMAX * SMAX];
vector<int> V[SMAX * SMAX];
vector<int> H[SMAX * SMAX];
int TT[SMAX * SMAX];
int cd[SMAX * SMAX];
bool viz[SMAX * SMAX];
vector<int> letterCards[NMAX];

inline int letter(int c) {
  return c - 'a' + 1;
}

inline int card(int c1, int c2) {
  if (c1 > 30) {
    c1 = letter(c1);
  }

  if (c2 > 30) {
    c2 = letter(c2);
  }
  return (c1 + 1) * SMAX + c2;
}

bool BFS() {
  int sz = 1;
  int i;
  cd[1] = S;
  memset(viz, 0, sizeof(viz));
  for (i = 1; i <= sz; i++) {
    if (viz[D]) {
	break;
    }
    int nod = cd[i];

    // Super tzaraneala
    for (int V = 0; V < SMAX * SMAX; V++) {
      if (C[nod][V] > F[nod][V] && !viz[V]) {
        cd[++sz] = V;
        viz[V] = true;
        TT[V] = nod;
      }
    }
  }

  return viz[D];
}

void maxFlow() {
  while (BFS()) {
    int nod = D;
    int fmin = INF;
    while (nod != S) {
      fmin = min(fmin, C[TT[nod]][nod] - F[TT[nod]][nod]);
      nod = TT[nod];
    }

    nod = D;
    while (nod != S) {
      F[TT[nod]][nod] += fmin;
      F[nod][TT[nod]] -= fmin;
      nod = TT[nod];
    }
  }
}

int main() {
  freopen("teroristi.in", "r", stdin);
  freopen("teroristi.out", "w", stdout);

  scanf("%d %d\n", &N, &M);
  scanf("%s\n", s);

  S = 0;
  D = SMAX * SMAX - 1;
  int i;
  for (i = 0; i < N; i++) {
    C[S][letter(s[i])]++;
  }

  char c1, c2;
  for (i = 1; i <= M; i++) {
    scanf("%c %c\n", &c1, &c2);
    if (PRINT_DEBUG) {
      printf("%c %c\n", c1, c2);
    }
    if (c1 > c2) {
      swap(c1, c2);
    }
    c1 = letter(c1);
    c2 = letter(c2);
    C[card(c1, c2)][D]++;
    V[card(c1, c2)].push_back(i);
  }

  for (i = 'a'; i <= 'z'; i++) {
    int x;
    for (x = 'a'; x <= 'z'; x++) {
      C[letter(i)][card(letter(i), letter(x))] = INF;
      C[letter(i)][card(letter(x), letter(i))] = INF;
      if (PRINT_DEBUG) {
        printf("%c %c%c -> %d\n", i, i, x, C[card(i, x)][D]);
        printf("%c %c%c -> %d\n", i, x, i, C[card(x, i)][D]);
      }
    }
  }

  maxFlow();
  for (i = 'a'; i <= 'z'; i++) {
    int x, y;
    for (x = 'a'; x <= 'z'; x++) {
      for (y = 'a'; y <= 'z'; y++) {
        int cnt = F[letter(i)][card(x, y)];
        if (cnt > 0 && PRINT_DEBUG) {
          printf("%c %c%c %d\n", i, x, y, cnt);
        }
        for (; cnt && V[card(x, y)].size() > 0; cnt--) {
          letterCards[letter(i)].push_back(V[card(x, y)].back());
          V[card(x, y)].pop_back();
        }
        F[letter(i)][card(x, y)] = 0;
      }
    }
  }

  for (i = 0; i < N; i++) {
    if (letterCards[letter(s[i])].size() > 0) {
      printf("%d ", letterCards[letter(s[i])].back());
      letterCards[letter(s[i])].pop_back();
    }
  }

  return 0;
}
