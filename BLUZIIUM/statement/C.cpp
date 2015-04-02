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
const double PI = 2 * acos(0);

class PouringWater {
public:
    int getMinBottles(int N, int K) {
        int res;

        for(int i = N;; i++){
        	if(cntbit(i) <= K){
        		return i - N;
        	}
        }

        return res;
    }


};

PouringWater T;

int main(){
	freopen("in.txt", "r", stdin);
	ll n, k;
	while(cin >> n >> k){
		cout << T.getMinBottles(n, k) << endl;
	}
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
