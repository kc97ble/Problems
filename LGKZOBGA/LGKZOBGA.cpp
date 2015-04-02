#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

const double PI = 2 * acos(0);

ll const mod = 1000000007;

ll f[3005][55][2];

class LittleElephantAndPermutationDiv1 {
public:
    int getNumber(int n, int k) {

      int sum = n * (n + 1) / 2;

      ms(f, 0);
      f[sum][0][0] = 1;

      For(run, 1, n){
        Rep(i, 3005) Rep(j, 55){
          f[i][j][1] = f[i][j][0];
          f[i][j][0] = 0;
        }

        Rep(i, 3005) Rep(j, 55) if(f[i][j][1]){
          if(j){
            f[i + run][j - 1][0] = (f[i + run][j - 1][0] + f[i][j][1] * j * j) % mod;
          }
          f[i][j][0] = (f[i][j][0] + f[i][j][1] * (1 + j + j)) % mod;
          f[i - run][j + 1][0] = (f[i - run][j + 1][0] + f[i][j][1]) % mod;
        }
      }

        ll res = 0;

        for(int run = sum; run < 3005; run++){
          if(run >= k){
            res = (res + f[run][0][0]) % mod;
          }
        }

        for(int i = 1; i <= n; i++) res = (res * i) % mod;

        return res;
    }


}A;

int main(){
//	freopen("in.txt", "r", stdin);
	int n, k;
	while(cin >> n >> k){
		if(n == 0 && k == 0) break;
		cout << A.getNumber(n, k) << endl;
	}

	cout << clock() << endl;
}
