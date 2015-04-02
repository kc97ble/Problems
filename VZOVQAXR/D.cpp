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

const double PI = 2 * acos(0);

bool isPrime[100005];

class Underprimes {
public:
    int howMany(int A, int B) {
        int res = 0;

        init();
        For(i, A, B) if(cal(i)) res++;

        return res;
    }

    void init(){
    	ms(isPrime, 1);
    	for(int i = 2; i <= 1000; i++) if(isPrime[i]){
    		for(int j = i + i; j < 100005; j += i) isPrime[j] = 0;
    	}
    	isPrime[1] = 0;
    }

    bool cal(int x){
    	int res = 0;
    	for(int i = 2; i * i <= x; i++) if( x % i == 0){
    		while(x % i == 0){
    			res++;
    			x /= i;
    		}
    	}
    	if(x > 1) res++;
    	return isPrime[res];
    }


};

Underprimes T;
int main(){
	freopen("in.txt", "r", stdin);
	ll x, y;
	while(cin >> x >> y){
		cout << T.howMany(x, y) << endl;
	}
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
