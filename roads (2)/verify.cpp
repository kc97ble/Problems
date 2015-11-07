#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

const int maxn = 20010;
const int maxm = 100010;

int n, m, k;
map<int, int> Hash;
int edge[maxm][3];
int father[maxn];

int find(int x) {
  if (father[x] == 0) return x;
  father[x] = find(father[x]);
  return father[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  father[x] = y;
}

int main(int argc, char* argv[]) {

  if(argc!=3) {
    printf("usage: verify [input] [output]\n");
    return 0;
  }

  ifstream fin(argv[1]);
  ifstream fout(argv[2]);
  fin >> n >> m >> k;
  Hash.clear();
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    fin >> u >> v >> c;
    Hash[u * maxn + v] = c + 1; 
    edge[i][0] = u;
    edge[i][1] = v;
    edge[i][2] = c;
  }
  for (int i = 1; i <= n; ++i) father[i] = 0;
  for (int i = 1; i <= m; ++i) {
    int u = edge[i][0];
    int v = edge[i][1];
    int c = edge[i][2];
    if (c == 1) merge(u, v);
  }
  int k1 = -1;
  for (int i = 1; i <= n; ++i) if (father[i] == 0) ++k1;
  for (int i = 1; i <= n; ++i) father[i] = 0;
  for (int i = 1; i <= m; ++i) {
    int u = edge[i][0];
    int v = edge[i][1];
    int c = edge[i][2];
    if (c == 0) merge(u, v);
  }
  int k2 = n;
  for (int i = 1; i <= n; ++i) if (father[i] == 0) --k2;
  //cout << k1 << " " << k2 << endl;
  if (k1 <= k && k <= k2) {
    bool ok = true;
    for (int i = 1; i <= n; ++i) father[i] = 0;
    for (int i = 1; i <= n - 1; ++i) {
      int u, v, c;
      fout >> u >> v >> c;	
      if (u < 1 || u > n)  {
	ok = false;
	break;
      }
      if (v < 1 || v > n)  {
	ok = false;
	break;
      }
      if (Hash[u * maxn + v] != c + 1) {
	ok = false;
	break;
      }
      if (c == 0) --k;
      merge(u, v);
    }
    int y = 0;
    for (int i = 1; i < n; ++i) if (father[i] == 0) ++y;
    if (y > 1 || k != 0) ok = false;
    if (ok) {
      cout << "Correct" << endl;
    }
    else {
      cout << "Incorrect" << endl;
    }
  }
  else {
    string tmp;
    fout >> tmp;
    if (tmp[0] == 'n') {
      cout << "Correct" << endl;
    }
    else {
      cout << "Incorrect" << endl;
    }
  }
  return 0;
}
