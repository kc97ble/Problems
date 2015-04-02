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
#define mod 10007
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}
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

#define maxn 7005

double f[102][102][128],g[102][102][128],d[111][128];
int test,n,a[111],b[111];

void sol(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));

	for(int i = 0; i <= 100; i++) for(int j = 0; j <= 100; j++){
		if(i == 0 && j == 0){
			f[i][j][0] = 1;
		}
		else if(i == 0){
			if(j & 1) f[i][j][1] = 1;
			else f[i][j][0] = 1;
		}
		else if(j == 0){
			f[i][j][i] = 1;
		}
		else{
			double r = j * 1. / (i + j);
			for(int k = 0; k <= i; k ++){
				f[i][j][k+1] += r * g[i - k][j-1][k];
				f[i][j][k] += r * (1 - g[i - k][j-1][k]);
				if( k < i) r *= (i - k) * 1. / (i + j - k - 1);
			}
		}
		g[i][j][0] = f[i][j][0];
		for(int k = 1; k < 128; k++) g[i][j][k] = g[i][j][k-1] + f[i][j][k];
	}

	while(cin >> n){
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for(int i = 1; i <= n; i++) scanf("%d",&b[i]);
		memset(d,0,sizeof(d));

		d[0][0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 128; j++){
				for(int k = 0; k < 128; k++){
					d[i][j] += d[i-1][k] * f[b[i]][a[i]][j^k];
				}
			}
		}
		printf("%.6lf\n",1 - d[n][0]);
	}
}

int main(){
	sol();

	return 0;
}


