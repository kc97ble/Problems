#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-2
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 205

int gauss(vector<vector<ld> > a, vector<ld> &ans){
	int n = sz(a);
	int m = (sz(a[0])) - 1;

/*   Rep(i, n){
        Rep(j, m + 1) cout << a[i][j] << " ";
        cout << endl;
    }
	cout << endl;
*/
	vector<int> where(m, -1);
	for(int col = 0, row = 0; col < m && row < n; ++col){
		int sel = row;
		for(int i = row; i < n; i++) if(abs(a[i][col]) > abs(a[sel][col])) sel = i;
		if(abs(a[sel][col]) < eps) continue;
		For(i, col, m) swap(a[row][i], a[sel][i]);
		where[col] = row;

		Rep(i, n) if(i != row){
			ld c = a[i][col] / a[row][col];
			For(j, col, m) a[i][j] -= a[row][j] * c;
		}
		++row;
	}
	ans.assign(m, 0);
	Rep(i, m) if(where[i] != -1) ans[i] = a[where[i]][m] / a[where[i]][i];
	Rep(i, n){
		ld sum = 0;
		Rep(j, m) sum += a[i][j] * ans[j];
		if(abs(sum - a[i][m]) > eps) return 0;
	}
	Rep(i, m) if(where[i] == -1) return inf;
	return 1;
}

int n, c[maxn], b[maxn], a[maxn][maxn], RR[maxn];
ld R[maxn];
vector<ld> V0, V1;

bool check(){
    Rep(i, n - 1){
        ll ret = 0;
        Rep(j, n) ret += RR[j] * 1ll * a[i][j];
        if(ret != b[i]) return false;
    }
    return true;
}

bool get(ld x){
    return x > -eps && abs(x - (int)(x + eps)) < eps;
}

ll cal(){
    ll ret = 0;
    Rep(i, n) {
        RR[i] = int(R[i] + eps);
        ret += RR[i] * c[i];
    }
    if(check()) return ret;
    return -1;
}

void sol(){
    cout << fixed << setprecision(10);
    cin >> n;
    Rep(i, n) cin >> c[i];
    Rep(i, n - 1) cin >> b[i];
    Rep(i, n - 1) Rep(j, n) cin >> a[i][j];

    int maxCounter = inf;
    Rep(i, n - 1){
        if(a[i][0])
            maxCounter = min(maxCounter, b[i] / a[i][0]);
    }

    ll res = -1;

    vector<vector<ld> > in;
    in.resize(n - 1); Rep(i, n - 1) in[i].resize(n);
    Rep(i, n - 1){
        Rep(j, n - 1) in[i][j] = a[i][j + 1];
        in[i][n - 1] = b[i];
    }
    gauss(in, V0);
  //  for(int i = 0; i < n - 1; i++) cout << V0[i] << " "; cout << endl;
    bool flag = true;
    R[0] = 0;
    For(i, 1, n - 1) {
        if(get(V0[i - 1])) R[i] = V0[i - 1];
        else {
            flag = false;
            break;
        }
    }
    if(flag){
        res = max(res, cal());
    }

    Rep(i, n - 1){
        Rep(j, n - 1) in[i][j] = a[i][j + 1];
        in[i][n - 1] = b[i] - a[i][0];
    }
    gauss(in, V1);
 //   for(int i = 0; i < n - 1; i++) cout << V1[i] << " "; cout << endl;
    flag = true;
    R[0] = 1;
    For(i, 1, n - 1) {
        if(get(V1[i - 1])) R[i] = V1[i - 1];
        else {
            flag = false;
            break;
        }
    }
    if(flag){
        res = max(res, cal());
    }

    for(int id = 2; id <= maxCounter; id++){
        R[0] = id;
        flag = true;
        For(i, 1, n - 1) {
            R[i] = V1[i -1] * (id) - V0[i - 1] * (id - 1);
            if(!get(R[i])){
             //    cout << id << " " << i << " " << R[i] << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            res = max(res, cal());
        }
    }

    if(res < 0){
        cout << -1 << endl;
    } else{
        cout << res << endl;
    }

}

void solN(){
    cout << fixed << setprecision(10);
    cin >> n;
    Rep(i, n) cin >> c[i];
    Rep(i, n - 1) cin >> b[i];
    Rep(i, n - 1) Rep(j, n) cin >> a[i][j];

    int maxCounter = inf;
    Rep(i, n - 1){
        if(a[i][n - 1])
            maxCounter = min(maxCounter, b[i] / a[i][n - 1]);
    }

    ll res = -1;

    vector<vector<ld> > in;
    in.resize(n - 1); Rep(i, n - 1) in[i].resize(n);
    Rep(i, n - 1){
        Rep(j, n - 1) in[i][j] = a[i][j];
        in[i][n - 1] = b[i];
    }
    gauss(in, V0);
    for(int i = 0; i < n - 1; i++) cout << V0[i] << " "; cout << endl;
    bool flag = true;
    R[n - 1] = 0;
    Rep(i, n - 1) {
        if(get(V0[i])) R[i] = V0[i];
        else {
            flag = false;
            break;
        }
    }
    if(flag){
        res = max(res, cal());
    }

    Rep(i, n - 1){
        Rep(j, n - 1) in[i][j] = a[i][j];
        in[i][n - 1] = b[i] - a[i][n - 1];
    }
    gauss(in, V1);
    for(int i = 0; i < n - 1; i++) cout << V1[i] << " "; cout << endl;
    flag = true;
    R[n - 1] = 1;
    Rep(i, n - 1) {
        if(get(V1[i])) R[i] = V1[i];
        else {
            flag = false;
            break;
        }
    }
    if(flag){
        res = max(res, cal());
    }

    for(int id = 2; id <= maxCounter; id++){
        R[n - 1] = id;
        flag = true;
        Rep(i, n - 1) {
            R[i] = V1[i] * (id) - V0[i] * (id - 1);
            if(!get(R[i])){
                cout << id << " " << i << " " << R[i] << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            res = max(res, cal());
        }
    }

    if(res < 0){
        cout << -1 << endl;
    } else{
        cout << res << endl;
    }

}

void trau(){
    cout << fixed << setprecision(10);
    cin >> n;
    Rep(i, n) cin >> c[i];
    Rep(i, n - 1) cin >> b[i];
    Rep(i, n - 1) Rep(j, n) cin >> a[i][j];

    int maxCounter = inf;
    Rep(i, n - 1){
        if(a[i][n - 1])
            maxCounter = min(maxCounter, b[i] / a[i][n - 1]);
    }

    ll res = -1;

    vector<vector<ld> > in;
    in.resize(n - 1); Rep(i, n - 1) in[i].resize(n);
    for(int id = 0; id <= maxCounter; id++){
        bool flag = true;
        R[n - 1] = id;
        Rep(i, n - 1){
            Rep(j, n - 1) in[i][j] = a[i][j];
            in[i][n - 1] = b[i] - id * a[i][n - 1];
        }
        gauss(in, V0);
        Rep(i, n - 1) {
            R[i] = V0[i];
            if(!get(R[i])){
                //cout << id << " " << i << " " << R[i] << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            res = max(res, cal());
        }
       // Rep(i, n - 1) cout << V0[i] << " "; cout << endl;
    }
    cout << res << endl;
}

void solve(){
    int test;
    cin >> test;
    Rep(itest, test){
 //       trau();
        sol();
    }
}


int main() {
 //   freopen("product.inp", "r", stdin);
  //  freopen("input.txt", "r", stdin);
  //  freopen("out1.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    solve();

    return 0;
}
