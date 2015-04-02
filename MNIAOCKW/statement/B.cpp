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

int a[15], r[15], x[15];

class TheSwap {
public:
    int findMax(int n, int k) {
        int res = 0;

        int num = 0;
        while(n){
        	x[num++] = n % 10;
        	n /= 10;
        }

        Rep(i, num) a[i] = x[num - 1 - i];
        if(num == 1){
        	if(k) return -1;
        	return a[0];
        }

        if(num == 2 && a[1] == 0){
        	if(k) return -1;
        	return a[0] * 10 + a[1];
        }

        Rep(i, num) r[i] = i;
        do{
        	vector<int> V;
        	Rep(i, num) V.pb(r[i]);
        	if(cal(V, k)){
        		int ret = 0;
        		Rep(i, num){
        			ret = ret * 10 + a[r[i]];
        		}
        		res = max(res, ret);
        	}
        }while(next_permutation(r, r + num));
        if(res == 0) return -1;
        return res;
    }

    bool cal(vector<int> V, int k){
    	int n = sz(V);
    	if(a[V[0]] == 0) return false;
    	int number = 0;
    	Rep(i, n) if(V[i] != i){
    		number++;
    		For(j, i + 1, n - 1) if(V[j] == i){
    			swap(V[i], V[j]);
    			break;
    		}
    	}
    	if(number <= k && (k - number) % 2== 0) return true;
    	return false;
    }


};

TheSwap T;

int main(){
	freopen("in.txt", "r", stdin);
	ll n, k;
	while(cin >> n >> k){
		cout << T.findMax(n, k) << endl;
	}
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
