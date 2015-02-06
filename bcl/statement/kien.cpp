#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<int, int> ii;
typedef pair<ii, ii> quad;
#define X first
#define Y second

quad rect(int x, int y, int u, int v)
	{ return quad(ii(x, y), ii(u, v)); }

#define N 2003
int n;
char a[N], F[N];
bool Visited[N][N];

void bfs(){
	queue<quad> qu;
	qu.push(rect(1, n, '\0', 0));
	while (qu.size()) {
		quad Top=qu.front(); qu.pop();
		int x=Top.X.X, y=Top.X.Y;
		int u=Top.Y.X, v=Top.Y.Y;
		if (F[v]!=u || x>y) continue;
		if (Visited[x][y]++) continue;
		
		F[v+1] = min(F[v+1], min(a[x], a[y]));
		qu.push(rect(x+1, y, a[x], v+1));
		qu.push(rect(x, y-1, a[y], v+1));
	}
}

main(){
	scanf("%d", &n);
	f1(i,n) {
		scanf(" %c", &a[i]);
		F[i]='z';
	}
	bfs();
	f1(i,n) {
		printf("%c", F[i]);
		if (i%80==0) printf("\n");
	}
}
