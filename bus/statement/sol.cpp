#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef vector<int> vi;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define MP(x, y) make_pair((x), (y))

template<typename T> inline int Size(const T& c) { return (int)c.size(); }

typedef pair<int,int> pii;

int n;
bool a[10][10];
int d[10][10];
map<int,pii> memo;
int b[10];

pii rec(int i) {
  if (i == n) return MP(0, 0);
  int state = 0;
  For(j, i, n-1)
    state = state*4+b[j];
  state = state*n+i;
  if (memo.count(state)) return memo[state];
  pii res = rec(i+1);
  if (b[i] >= 1) {
    For(j, i+1, n-1) {
      if (a[i][j] && b[j] >= 1) {
        --b[i]; --b[j];
        pii cur = rec(i+1);
        cur.first += 1;
        cur.second += d[i][j];
        if (cur.first > res.first || cur.first == res.first && cur.second < res.second) res = cur;
        ++b[i]; ++b[j];
      }
    }
    if (b[i] >= 2) {
      For(j1, i+1, n-1) if (a[i][j1] && b[j1] >= 1) {
        --b[i]; --b[j1];
        For(j2, j1+1, n-1) if (a[i][j2] && b[j2] >= 1) {
          --b[i]; --b[j2];
          pii cur = rec(i+1);
          cur.first += 2;
          cur.second += d[i][j1]+d[i][j2];
          if (cur.first > res.first || cur.first == res.first && cur.second < res.second) res = cur;
          ++b[i]; ++b[j2];
        }
        ++b[i]; ++b[j1];
      }
      if (b[i] == 3) {
        For(j1, i+1, n-1) if (a[i][j1] && b[j1] >= 1) {
          --b[i]; --b[j1];
          For(j2, j1+1, n-1) if (a[i][j2] && b[j2] >= 1) {
            --b[i]; --b[j2];
            For(j3, j2+1, n-1) if (a[i][j3] && b[j3] >= 1) {
              --b[i]; --b[j3];
              pii cur = rec(i+1);
              cur.first += 3;
              cur.second += d[i][j1]+d[i][j2]+d[i][j3];
              if (cur.first > res.first || cur.first == res.first && cur.second < res.second) res = cur;
              ++b[i]; ++b[j3];
            }
            ++b[i]; ++b[j2];
          }
          ++b[i]; ++b[j1];
        }
      }
    }    
  }
  return memo[state] = res;
}


  vi optimalTwinTowns(vi x, vi y, int maxP, int minD) {
    n = Size(x);
    Rep(i, n) Rep(j, n)
      a[i][j] = (d[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j])) >= minD;
    Rep(i, n)
      b[i] = maxP;
    pii res = rec(0);
    vi v;
    v.push_back(res.first);
    v.push_back(res.second);
    return v;
  }

int main() {
	freopen("bus.inp", "r", stdin);
	freopen("bus.out", "w", stdout);
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		int xx, yy;
		cin >> xx >> yy;
		x.push_back(xx);
		y.push_back(yy);
	}
	vector<int> res = optimalTwinTowns(x, y, k, l);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}
