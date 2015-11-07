#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 1e5 + 5, INF = 1e9;

string s;

void init(void) {
    cin >> s;
}

void process(void) {
    int N = s.size();
    int cur = 0;
    ll res = 0;
    int last = -1;
    ff(i, 0, N - 1) {
        cur += (s[i] == '(') ? 1 : -1;
        if (cur == 0) {
            //cout << i << endl;
            res += 1ll * (i - last) * (N - last);
            last = i;
        }
    }
    cout << res + 1 << endl;
}

int main(void) {
    init();
    process();
    return 0;
}
