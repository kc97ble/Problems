#line 2 "Topcoder.cpp"
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
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
const double PI = 2 * acos(0);


ll Lon[11] = {0, 1, 10, 102, 1023, 10234, 102345, 1023456, 10234567, 102345678ll, 1023456789ll};
#define linf (1ll << 60)

int a[20], b[20];
ll f[20][1 << 10][2];
int n = 0, k;

class TheInteger {
public:
    long long find(long long _n, int _k) {
        long long res;
        k = _k;
        if(Lon[k] >= _n) return Lon[k];
        n = 0;
        while(_n){
        	b[++n] = _n % 10;
        	_n /= 10;
        }

        For(i, 1, n) a[i] = b[n + 1 - i];
        res = min(cal0(), cal1());

        return res;
    }

    ll cal0(){
    	ms(f, 0x3f);
    	f[0][0][0] = 0;
    	For(i, 0, n - 1) Rep(mask, (1 << 10)) Rep(hon, 2) if(f[i][mask][hon] < linf / 10){
//    		cout << i << " " << mask << " " << hon << " " << f[i][mask][hon] << endl;
    		if(!hon){
//    			cout << i << " " << mask << endl;
    			For(j, a[i + 1], 9){
    				f[i + 1][onbit(mask, j)][j > a[i + 1]] = min(f[i + 1][onbit(mask, j)][j > a[i + 1]], f[i][mask][hon] * 10 + j);
    			}
    		}
    		else{
    			Rep(j, 10){
    				f[i + 1][onbit(mask, j)][hon] = min(f[i + 1][onbit(mask, j)][hon], f[i][mask][hon] * 10 + j);
    			}
    		}
    	}

    	ll res = linf;
    	Rep(mask, (1 << 10)) Rep(hon, 2) if(cntbit(mask) == k) res = min(res, f[n][mask][hon]);

    	return res;
    }

    ll cal1(){
    	ms(f, 0x3f);
    	f[0][2][1] = 1;
    	For(i, 0, n - 1) Rep(mask, (1 << 10)) Rep(hon, 2) if(f[i][mask][hon] < linf / 10){
    		if(!hon){
    			For(j, a[i + 1], 9){
    				f[i + 1][onbit(mask, j)][j > a[i + 1]] = min(f[i + 1][onbit(mask, j)][j > a[i + 1]], f[i][mask][hon] * 10 + j);
    			}
    		}
    		else{
    			Rep(j, 10){
    				f[i + 1][onbit(mask, j)][hon] = min(f[i + 1][onbit(mask, j)][hon], f[i][mask][hon] * 10 + j);
    			}
    		}
    	}

    	ll res = linf;
    	Rep(mask, (1 << 10)) Rep(hon, 2) if(cntbit(mask) == k) res = min(res, f[n][mask][hon]);

    	return res;
    }


};

TheInteger T;

int main(){
	freopen("in.txt", "r", stdin);
	ll n, k;
	while(cin >> n >> k){
		cout << T.find(n, k) << endl;
	}
}



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
