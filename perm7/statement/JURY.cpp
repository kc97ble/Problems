#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
int n, m, p[123], q[123], a[7], b[7];
int d[7][7][7][7][7][7];
int c[7][7][7][7][7][7];
#define d(u) d[u[0]][u[1]][u[2]][u[3]][u[4]][u[5]]
#define c(u) c[u[0]][u[1]][u[2]][u[3]][u[4]][u[5]]

int bfs(vi a, vi b) {
	if (a==b) return 0;
	queue<vi> qu;
	qu.push(a); d(a)=0; c(a)=1;
	qu.push(b); d(b)=0; c(b)=2;
	
	while (qu.size()) {
		vi u=qu.front(); qu.pop();
		//for (int i=0; i<n; i++) printf("%d ", u[i]);
		//printf("d=%d, c=%d\n", d(u), c(u));
		vi v = u;
		for (int i=1; i<=m; i++) {
			swap(v[p[i]], v[q[i]]);
			if (c(v)==0) {
				d(v) = d(u) + 1;
				c(v) = c(u);
				qu.push(v);
			} else if (c(v)!=c(u)){
				return d(v) + d(u) + 1;
			}
			swap(v[p[i]], v[q[i]]);
		}
	}
	return -1;
}

main(){
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
		{ scanf("%d", &a[i]); a[i]--; }
	for (int i=0; i<n; i++)
		{ scanf("%d", &b[i]); b[i]--; }
	for (int i=1; i<=m; i++)
		{ scanf("%d%d", &p[i], &q[i]); p[i]--; q[i]--; }
	cout << bfs(vi(a, a+7), vi(b, b+7)) << endl;
}
