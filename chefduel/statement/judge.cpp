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

string sa = "0.in",sb = "0.expect",sc = "0.out";
//string sa = "a.in",sb = "a.expect",sc = "a.out";
FILE* fa;
FILE* fb;
FILE* fc;
int T,K[10];
int m[10][30],n[10][30];
char maze[10][30][75][75];
string ans[10];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char type[4] = {'N','E','S','W'};
char encode[100005];

string refine() {
  string t = "";
  for (int i = 0; i < strlen(encode); i++)
    if (encode[i] == 'N' || encode[i] == 'S' || encode[i] == 'E' || encode[i] == 'W') t += encode[i];
  return t;
}

int checkOutput(int idx) {
  if (ans[idx].size() > 10000) {
    printf("Group %d: Output limit exceeded\n", idx);
    return 0;
  }
  vector< pair<int,int> > start;
  for (int i = 0; i < K[idx]; i++) {
    for (int j = 0; j < m[idx][i]; j++)
      for (int k = 0; k < n[idx][i]; k++)
        if (maze[idx][i][j][k] == 'S') start.push_back(make_pair(j,k));
  }
  int endMaze = 0;
  for (int cur = 0; cur < ans[idx].size(); cur++) {
    endMaze = 0;
    int dir = 0;
    for (int i = 0; i < 4; i++) if (ans[idx][cur] == type[i]) dir = i;
    for (int i = 0; i < K[idx]; i++) {
    //  if (i == K[idx] - 1) cout << ans[idx][cur] << ' ' << start[i].first << ' ' << start[i].second << endl;
      int ux = start[i].first,uy = start[i].second;
      if (maze[idx][i][ux][uy] == 'E') {
        endMaze++;  continue;
      }
      int vx = ux + dx[dir],vy = uy + dy[dir];
      if (vx < 0 || vx >= m[idx][i] || vy < 0 || vy >= n[idx][i] || maze[idx][i][vx][vy] == '#') continue;
      start[i] = make_pair(vx,vy);
      if (maze[idx][i][vx][vy] == 'E') endMaze++;
    }
    if (endMaze == K[idx] && cur < ans[idx].size() - 1) {
      printf("Group %d: Better prefix exists\n", idx);
      return 0;
    }
  }
  if (endMaze < K[idx]) {
    printf("Group %d: Some robots were unable to finish\n", idx);
    return 0;
  }
  return ans[idx].size();
}

double scoring() {
  fa = fopen(sa.c_str(),"r");
  fscanf(fa,"%d", &T);
  for (int it = 0; it < T; it++) {
    fscanf(fa,"%d", &K[it]);
    for (int ik = 0; ik < K[it]; ik++) {
      fscanf(fa,"%d %d", &m[it][ik], &n[it][ik]);
      for (int im = 0; im < m[it][ik]; im++)
        for (int in = 0; in < n[it][ik]; in++) {
	  char ch;
	  while (1) {
	    fscanf(fa,"%c", &ch);
	    if (ch == '.' || ch == '#' || ch == 'S' || ch == 'E') break;
	  }
	  maze[it][ik][im][in] = ch;
	}
    }
  }
  fc = fopen(sc.c_str(),"r");
  for (int it = 0; it < T; it++) {
    fscanf(fc,"%s\n", &encode);
    ans[it] = refine();
  }

  int output = 0;
  for (int it = 0; it < T; it++) {
    int tmp = checkOutput(it);
    if (!tmp) return 0;
    output += tmp;
  }

  fb = fopen(sb.c_str(),"r");
  for (int it = 0; it < T; it++) {
    fscanf(fb,"%s\n", &encode);
    ans[it] = refine();
  }

  int official = 0;
  for (int it = 0; it < T; it++) {
    official += ans[it].size();
  }
  return 10.0 * min(1.0,1.0 * official/output);
}

int main() {
  freopen("detail.data","w",stdout);
  double score = 0.0;
  for (int it = 0; it < 10; it++) {
    printf("Test %d\n", it);
    double x = scoring();
    score += x;
    if (x > 0) printf("OK, Score = %.2lf\n", x);
    sa[0]++;  sb[0]++;  sc[0]++;
  }
  fprintf(stderr,"Score: %.2lf\n", score);
}
