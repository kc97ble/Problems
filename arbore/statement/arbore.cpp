#define TuTTy "Cosmin-Mihai Tutunaru"
#include<cstdio>
#include<vector>
#include<algorithm>
#define infile "arbore.in"
#define outfile "arbore.out"
#define nMax 100013
#define modulo 666013
#define ll long long

using namespace std;

vector <int> v[nMax];
int sum[nMax];
int fact[nMax];
int dp[nMax];
int n;

int myPow(int x, int k) {
  if(!k) return 1;
  if(k == 1) return x;
  if(k&1) return ((ll)x * myPow(x, k-1)) % modulo;
  ll y = myPow(x, k>>1);
  return (y*y) % modulo;
}

int comb(int n, int k) {
  return ((ll)fact[n] * myPow(((ll)fact[k] * fact[n-k]) % modulo, modulo - 2)) % modulo;
}

void read() {
  scanf("%d\n", &n);
  for(int i = 2; i <= n; ++i) {
    int x, y;
    scanf("%d %d\n", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
}

void init() {
  fact[0] = fact[1] = 1;
  for(int i = 2; i <= n; ++i)
    fact[i] = ((ll)fact[i-1] * i) % modulo;
}

void dfs(int x, int f) {
  sum[x] = dp[x] = 1;

  for(unsigned i = 0; i < v[x].size(); ++i)
    if(v[x][i] != f) {
      dfs(v[x][i], x);
      sum[x] += sum[v[x][i]];
    }

  int tot = sum[x];
  for(unsigned i = 0; i < v[x].size(); ++i)
    if(v[x][i] != f) {
      dp[x] = ((ll)dp[x] * dp[v[x][i]]) % modulo;
      dp[x] = ((ll)dp[x] * comb(tot - 1, sum[v[x][i]])) % modulo;
      tot -= sum[v[x][i]];
    }
}

void write() {
  printf("%d\n", dp[1]);
}

int main() {
  freopen(infile, "r", stdin);
  freopen(outfile, "w", stdout);

  read();
  init();
  dfs(1, 0);
  write();

  fclose(stdin);
  fclose(stdout);
  return 0;
}
