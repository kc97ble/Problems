#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 1003
int n, Assigned[N], t=2309, Visited[N], F[N];
vector<int> a[N];

int where(int u){
	f1(i,n) if (F[i]==u) return i;
	for(;;) cout << "HAHAHA" << endl;
}

bool visit(int u){
	if (Visited[u]==t) return false; Visited[u]=t;
	for (int i=0; int v=a[u][i]; i++)
	if (!Assigned[v] || visit(Assigned[v]))
	{ Assigned[u]=v; Assigned[v]=u; return true; }
	return false;
}

main(){
	freopen("revolutie.in", "r", stdin);
	freopen("revolutie.out", "w", stdout);
	
	scanf("%d", &n);
	f1(i,n) f1(j,n) {
		int x;
		scanf("%d", &x);
		//printf(j==n ? "%d\n" : "%d ", x=rand()<RAND_MAX*0.2);
		if (x) a[i].push_back(N-j);
	}
	f1(i,n) a[i].push_back(0);
	
	int Success = 0;
	f1(i,n) if (!Assigned[i]) { t++; Success += visit(i); }
	if (Success != n) { cout << -1 << endl; return 0; }

	f1(i,n) F[i]=N-Assigned[i];
	//f1(i,n) printf("%d ", F[i]); printf("\n");
	cout << n << endl;
	f1(i,n) {
		int x=where(i);
		printf("L %d %d\n", i, x);
		swap(F[i], F[x]);
	}
}
