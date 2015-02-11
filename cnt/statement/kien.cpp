#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 203
const int oo = 0x3c3c3c3c;
int n, k;
vector<int> a[N];

int FF[2][N][N];
bool F[2][N][N];
#define C UsedU][v][k

bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

int f(int u, int i, int p, int k, bool UsedU, bool Tracing=false){
	//printf("f(%d, %d, %d, %d, %d) = ?\n", u, i, p, k, (int)UsedU);
	int v=a[u][i];
	if (v==0) return k==0 ? 0 : oo;
	if (v==p) return f(u, i+1, p, k, UsedU, Tracing);
	if (!Tracing && F[C]++) return FF[C];
	
	int Min=oo, dx=0, dy=0;
	f0(j,k) if (minimize(Min, 
		f(v, 0, u, j, true) + f(u, i+1, p, k-1-j, UsedU) + UsedU))
		{ dx=1; dy=j; }
	f0(j,k+1) if (minimize(Min,
		f(v, 0, u, j, false) + f(u, i+1, p, k-j, UsedU)))
		{ dx=2; dy=j; }
	
	if (Tracing) {
		if (dx==1) {
			int j=dy;
			printf("%d ", v);
			f(v, 0, u, j, true, true);
			f(u, i+1, p, k-1-j, UsedU, true);
		} else {
			int j=dy;
			f(v, 0, u, j, false, true);
			f(u, i+1, p, k-j, UsedU, true);
		}
	}
	
	//printf("f(%d, %d, %d, %d, %d) = %d\n", u, i, p, k, (int)UsedU, Min);
	return FF[C]=Min;
}

main(){
	freopen("cnt.inp", "r", stdin);
	freopen("cnt.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	f1(i,n-1) {
		int x, y; scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	f1(i,n) a[i].push_back(0);
	int F1 = f(1, 0, 1, k, false);
	int F2 = f(1, 0, 1, k-1, true);
	cout << min(F1, F2) << endl;
	if (F1 < F2) {
		f(1, 0, 1, k, false, true);
	} else {
		printf("%d ", 1);
		f(1, 0, 1, k-1, true, true);
	}
	cout << endl;
}
