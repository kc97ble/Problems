#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string input = "0.in";
FILE* fa;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void randomWalk(int m,int n) {
  char maze[75][75];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) maze[i][j] = '#';
  int sx = rand() % m,sy = rand() % n;
  maze[sx][sy] = '.';
  for (int iter = 0; iter < 1e7; iter++) {
    int dir = rand() % 4;
    int fx = sx + dx[dir],fy = sy + dy[dir];
    if (fx < 0 || fx >= m || fy < 0 || fy >= n) continue;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      int zx = fx + dx[i],zy = fy + dy[i];
      if (zx >= 0 && zx < m && zy >= 0 && zy < n && maze[zx][zy] == '.') cnt++;
    }
    if (cnt == 1) maze[fx][fy] = '.';
    sx = fx;  sy = fy;
  }

  vector< pair<int,int> > access;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) if (maze[i][j] == '.') access.push_back(make_pair(i,j));
  int as = rand() % access.size(),at;
  while (1) {
    at = rand() % access.size();
    if (at != as) break;
  }
  maze[access[as].first][access[as].second] = 'S';
  maze[access[at].first][access[at].second] = 'E';

  fprintf(fa,"%d %d\n", m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) fprintf(fa,"%c",maze[i][j]);
    fprintf(fa,"\n");
  }
}

int main() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
    fa = fopen(input.c_str(),"w");
    input[0]++;
    fprintf(fa,"10\n");
    for (int ntest = 0; ntest < 10; ntest++) {
      int K = rand() % 19 + 2,L = (int) floor(45.0/sqrt(K)),R = floor(70.0/sqrt(K));
      fprintf(fa,"%d\n", K);
      for (int j = 0; j < K; j++) {
        int m = rand() % (R - L) + L,n = rand() % (R - L) + L;
	randomWalk(m,n);
      }
    }
  }
}
