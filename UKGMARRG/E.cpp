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

class BinaryFlips {
public:
    int minimalMoves(int a, int b, int k) {
        int res;

        if(a == 0) return 0;
        if(k > a + b) return -1;

        for(ll x = 1; x <= a + b; x++){
        	ll r = x * k - a;
        	if(r < 0) continue;
        	if(r % 2 == 1) continue;
        	if(a * ((x - 1) / 2 * 2) + b * (x / 2 * 2) >= r) return x;
        }
        res = -1;

        return res;
    }


};

BinaryFlips T;

int main(){
	ll a, b, c;
	freopen("in.txt", "r", stdin);
	while(cin >> a >> b >> c){
		cout << T.minimalMoves(a, b, c) << endl;
	}
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
