#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int n, m;
vector<int> a[102];
int F[102][20004];
bool FF[102][20004];

int f(int k, int m){
	if (k==0) return 0;
	if (FF[k][m]++) return F[k][m];
	int Cur=0, Max=f(k-1, m);
	for (int i=0; i<a[k].size(); i++) {
		Cur += a[k][i];
		if (m-Cur<0) break;
		Max = max(Max, f(k-1, m-Cur)+(i+1)*k);
	}
	return F[k][m]=Max;
}

main(){
	scanf("%d%d", &n, &m);
	f1(i,n) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[y].push_back(x);
	}
	f1(i,100) sort(a[i].begin(), a[i].end());
	cout << f(100, m) << endl;
}
