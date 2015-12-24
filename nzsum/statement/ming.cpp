#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef vector <vi> matrix;

const int mod = 1000000007;

matrix unit(int sz) {
    matrix c(sz, vi(sz, 0));
    ff(i, 0, sz - 1) c[i][i] = 1;
    return c;
}

matrix operator *(const matrix& a, const matrix& b) {
    int m = a.size(), n = a[0].size(), p = b[0].size();
    matrix c(m, vi(p, 0));
    ff(i, 0, m - 1) ff(j, 0, n - 1) ff(k, 0, p - 1)
        c[i][k] = (c[i][k] + 1ll * a[i][j] * b[j][k]) % mod;
    return c;
}

matrix operator ^(matrix a, ll b) {
    matrix c = unit(a.size());
    while (b) {
        if (b & 1) c = c * a;
        a = a * a;
        b >>= 1;
    }
    return c;
}

int f[10], s[10];

int main(void) {
    f[0] = 1;
    ff(i, 1, 9) ff(j, 0, i - 1) {
        f[i] = (f[i] + f[j]) % mod;
        s[i] = (s[i] + 10ll * s[j] + 1ll * (i - j) * f[j]) % mod;
    }
    matrix a(18, vi(18, 0)), b(18, vi(1, 0)), c;
    ff(i, 0, 8) b[i][0] = f[i+1];
    ff(i, 9, 17) b[i][0] = s[i-8];
    ff(i, 0, 7) a[i][i+1] = 1;
    ff(i, 0, 8) a[8][i] = 1;
    ff(i, 9, 16) a[i][i+1] = 1;
    ff(i, 9, 17) a[17][i] = 10;
    ff(i, 0, 8) a[17][i] = 9 - i;
    ll N;
    while (cin >> N) {
        if (N < 10) cout << s[N] << "\n";
        else {
            N -= 9;
            c = (a ^ N) * b;
            cout << c[17][0] << "\n";
        }
    }
    return 0;
}
