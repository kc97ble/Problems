#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

template<class F, class T> T convert(F a, int p = -1) {
    stringstream ss;
    if (p >= 0)
        ss << fixed << setprecision(p);
    ss << a;
    T r;
    ss >> r;
    return r;
}
template<class T> T gcd(T a, T b) {
    T r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template<class T> T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
template<class T> T sqr(T x) {
    return x * x;
}
template<class T> T cube(T x) {
    return x * x * x;
}
template<class T> int getbit(T s, int i) {
    return (s >> i) & 1;
}
template<class T> T onbit(T s, int i) {
    return s | (T(1) << i);
}
template<class T> T offbit(T s, int i) {
    return s & (~(T(1) << i));
}
template<class T> int cntbit(T s) {
    return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);
}

const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
    if (rsz <= 0) {
        ptr = 0;
        rsz = (int) fread(bf, 1, bfsz, stdin);
        if (rsz <= 0)
            return EOF;
    }
    --rsz;
    return bf[ptr++];
}
void ga(char &c) {
    c = EOF;
    while (!isalpha(c))
        c = gc();
}
int gs(char s[]) {
    int l = 0;
    char c = gc();
    while (isspace(c))
        c = gc();
    while (c != EOF && !isspace(c)) {
        s[l++] = c;
        c = gc();
    }
    s[l] = '\0';
    return l;
}
template<class T> bool gi(T &v) {
    v = 0;
    char c = gc();
    while (c != EOF && c != '-' && !isdigit(c))
        c = gc();
    if (c == EOF)
        return false;
    bool neg = c == '-';
    if (neg)
        c = gc();
    while (isdigit(c)) {
        v = v * 10 + c - '0';
        c = gc();
    }
    if (neg)
        v = -v;
    return true;
}

typedef pair<int, int> II;
const ld PI = acos(-1.0);
const ld eps = 1e-9;
const int dr[] = { 0, 0, -1, +1 , -1, -1, +1, +1};
const int dc[] = { -1, +1, 0, 0 , -1, +1, -1, +1};
const int inf = (int) 1e9 + 5;
const ll linf = (ll) 1e16 + 5;
const ll mod = (ll) 1e9 + 7;
#define ok puts("ok")
#define maxn 1000005

struct Point{
    ld x, y;
    Point(){};
    Point(ld _x, ld _y){
        x = _x; y = _y;
    }
    bool operator <(const Point &P)const{
        return x < P.x;
    }
};

bool comp(const Point &P0, const Point &P1){
    return P0.y < P1.y;
}

ld dist(Point P0, Point P1){
    return sqrt(sqr(P0.x - P1.x) + sqr(P0.y - P1.y));
}

ld res = linf;
Point A[maxn];
int n;

ld radius(Point P0, Point P1, Point P2){
    ld a = dist(P0, P1), b = dist(P1, P2), c = dist(P0, P2);
    return a + b + c;
}

void go(int l, int r){
    if(r - l <= 1) return;
    if(r - l == 2){
        res = min(res, radius(A[l], A[l + 1], A[r]));
        return;
    }

    int mid = (r + l) >> 1;
    go(l, mid);
    go(mid + 1, r);
    vector<Point> P;
    for(int i = mid; i >= l && A[mid].x - res / 2 <= A[i].x; i--) P.pb(A[i]);
    for(int i = mid + 1; i <= r && A[mid].x + res / 2 >= A[i].x; i++) P.pb(A[i]);
    sort(all(P), comp);
    Rep(i, sz(P))
        for(int j = i + 1; j < sz(P) && P[j].y <= P[i].y + res / 2; j++)
            for(int k = j + 1; k < sz(P) && P[k].y <= P[i].y + res / 2; k++)
                res = min(res, radius(P[i], P[j], P[k]));

}
void solve(){
   int u, v;
   For(i, 1, n) {
	   scanf("%d %d", &u, &v);
	   A[i] = Point(u, v);
   }
   sort(A + 1, A + n);
   res = linf;
   go(1, n);
//  cout << fixed << setprecision(20);
//  cout << res << endl;
   cout << fixed << setprecision(3);
   cout << res << endl;
}

int main() {
  freopen("in.txt", "r", stdin);

	while(cin >> n && n > 0){
		solve();
	}

    return 0;
}
