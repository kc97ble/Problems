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

int no(void) { cout << "N" << endl; return 0; }
int yes(void) { cout << "Y" << endl; return 0; }

int main(void) {
    cin >> s;
    int N = s.size();
    if (N & 1) return no();
    int cnt = 0;
    ff(i, 0, N - 1) cnt += (s[i] == '(');
    if (cnt > N / 2) return no();
    ff(i, 0, N - 1) if (s[i] == '?') if (cnt < N / 2) { s[i] = '('; ++cnt; } else s[i] = ')';
    int f = 0;
    ff(i, 0, N - 1) {
        if (s[i] == '(') ++f; else --f;
        if (f < 0) return no();
    }
    return yes();
    return 0;
}
