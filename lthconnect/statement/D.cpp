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
	For(i, 1, 89){
		freopen(("data/" + toString(i) + ".a").c_str(), "r", stdin);
		string s;
		cin >> s;
		if(s[0] == 'A') cout << "Dung" << "\n";
		else cout << "Minh\n";
	}
}

#define maxn 505

int f[155][155][2],n,m,a,b,so,tong,cay,le;
bool fr[155];
vector<vector<int> > V;

int test;

void duyet(int x){
    so++;
    fr[x] = 1;
    for(int i = 0; i < (int)V[x].size(); i++){
        if(!fr[V[x][i]]) duyet(V[x][i]);
    }
}

void solve(){
	  freopen("in.txt", "r", stdin);
    memset(f,1,sizeof(f));

    for(int i = 0; i <= 150; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= 1; k++){
                if(i < 2){
                    f[i][j][k] = 0;
                    continue;
                }
                else if( i == 2){
                    f[i][j][k] = 1;
                    continue;
                }
                int t = f[i - 1][j][1 - k];
                if(k) t &= f[i][j][1 - k];
                if( j > 1) t &= f[i - 1][j - 2][k];
                f[i][j][k] = 1 - t;
            }
        }
    }

    memset(fr, 0, sizeof(fr));
    while(cin >> n >> m){
    	V.clear();
		V.resize(n + 2);
		ms(fr, 0); so = 0;
		for(int i = 1; i <= n; i++) V[i].clear();
		for(int i = 0; i < m; i++){
			scanf("%d %d",&a,&b);
			V[a].push_back(b);
			V[b].push_back(a);
		}

		tong = 0; cay = 0; le = 0;
		for(int i = 1; i <= n; i++){
			if(!fr[i]){
				so = 0;
				duyet(i);
				tong += so * (so - 1) / 2;
				cay++;
				le += (so & 1);
			}
		}
		tong -= m;

		//cout << cay << " " << le << " " << tong << endl;

		if(f[cay][le][tong & 1]) printf("Dung");
		else printf("Minh");
		cout << "\n";
    }
}

int main(){

//	make();
	solve();
}

