#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 10004

int n, m, t, Max=0, Level[N]; //
vector<int> a[N]; //

void visit(int u, int p, int l){
	Level[u]=l;
	for (int i=0; int v=a[u][i]; i++) if (v!=p)
	if (Level[v]) Max = max(Max, Level[u]-Level[v]+1);
	else visit(v, u, l+1);
}

main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		f1(i,m) {
			int x, y; scanf("%d%d", &x, &y);
			a[x].push_back(y);
			a[y].push_back(x);
		}	
		f1(i,n) a[i].push_back(0);
		f1(i,n) if (!Level[i]) visit(i, i, 1);
		cout << Max << endl;
		f1(i,n) { a[i].clear(); Level[i]=0; }
		Max=0;
	}
}
