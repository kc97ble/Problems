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
#define mod 50515093
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

string toString(int x){
	string res = "";
	res.pb(x / 10 + '0');
	res.pb(x % 10 + '0');
	return res;
}

void make(){
	freopen("out.txt", "w", stdout);
	For(i, 1, 50){
		if(i == 30) continue;
		freopen(("data/" + toString(i) + ".a").c_str(), "r", stdin);
		string s, t;
		cin >> s;
		cout << s << endl;

	}
}

#define maxn 205
#define maxe 50005
string problem = "transform";

string str = "ACGT";

string s, t;
int a[maxn], n;

int cal(char ch){
    Rep(i, 4) if(str[i] == ch) return i;
    return -1;
}

int f[105][55][55][55], back[105][55][55][55];
vector<int> ad[5], rm[5];

void solve(){
	freopen("in.txt", "r", stdin);

	while(cin >> s >> t){
		ms(f, 0); ms(back, 0);
		n = sz(s);
		For(i, 1, n){
			a[i] = (cal(t[i - 1]) - cal(s[i - 1]) + 4) % 4;
		}
		int m = (n >> 1) + 1;
		a[0] = 0; a[n + 1] = 0;

		ms(f, 0x3f);
		f[0][0][0][0] = 0;
		For(run, 0, n) For(i, 0, m) For(j, 0, m) For(k, 0, m) if(f[run][i][j][k] < inf){
			int A = (i + j + j + k + k + k) % 4, d, ii, jj, kk;
			d = (a[run + 1] - A + 4) % 4;
			ii = i; jj = j; kk = k;
			if(d == 1) ii++;
			else if(d == 2) jj++;
			else if(d == 3) kk++;

			if(f[run + 1][ii][jj][kk] > f[run][i][j][k] + (d != 0)){
				f[run + 1][ii][jj][kk] = f[run][i][j][k] + (d != 0);
				back[run + 1][ii][jj][kk] = d;
			}

			if(i > 0){
				ii = i - 1; jj = j; kk = k;
				A = (ii + jj + jj + kk + kk + kk);
				d = (a[run + 1] - A + 40000) % 4;
				if(d == 1) ii++;
				else if(d == 2) jj++;
				else if(d == 3) kk++;
				if(f[run + 1][ii][jj][kk] > f[run][i][j][k] + (d != 0)){
					f[run + 1][ii][jj][kk] = f[run][i][j][k] + (d != 0);
					back[run + 1][ii][jj][kk] = 5 + d;
				}
			}

			if(j > 0){
				ii = i; jj = j - 1; kk = k;
				A = (ii + jj + jj + kk + kk + kk);
				d = (a[run + 1] - A + 40000) % 4;
				if(d == 1) ii++;
				else if(d == 2) jj++;
				else if(d == 3) kk++;
				if(f[run + 1][ii][jj][kk] > f[run][i][j][k] + (d != 0)){
					f[run + 1][ii][jj][kk] = f[run][i][j][k] + (d != 0);
					back[run + 1][ii][jj][kk] = 10 + d;
				}
			}

			if(k > 0){
				ii = i; jj = j; kk = k - 1;
				A = (ii + jj + jj + kk + kk + kk);
				d = (a[run + 1] - A + 40000) % 4;
				if(d == 1) ii++;
				else if(d == 2) jj++;
				else if(d == 3) kk++;
				if(f[run + 1][ii][jj][kk] > f[run][i][j][k] + (d != 0)){
					f[run + 1][ii][jj][kk] = f[run][i][j][k] + (d != 0);
					back[run + 1][ii][jj][kk] = 15 + d;
				}
			}
		}

		int run = n + 1, n1 = 0, n2 = 0, n3 = 0;
		while(run){
			int A = back[run][n1][n2][n3];
			int x = A % 5, y = A / 5;
			if(x == 1){
				n1--;
				ad[1].pb(run);
			}
			if(x == 2){
				n2--;
				ad[2].pb(run);
			}
			if(x == 3){
				n3--;
				ad[3].pb(run);
			}
			if(y == 1){
				n1++;
				rm[1].pb(run - 1);
			}
			if(y == 2){
				n2++;
				rm[2].pb(run - 1);
			}
			if(y == 3){
				n3++;
				rm[3].pb(run - 1);
			}
			run--;
		}

		For(i, 1, 3){
			sort(all(ad[i]));
			sort(all(rm[i]));
		}

		cout << f[n + 1][0][0][0] << endl;
//		For(i, 1, 3){
//			Rep(j, sz(ad[i])){
//				cout << ad[i][j] << " " << rm[i][j] << " " << i << endl;
//			}
//		}
	}
//    cout << clock() << endl;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//	make();
	solve();

    return 0;
}

