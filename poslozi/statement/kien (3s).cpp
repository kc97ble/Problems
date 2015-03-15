#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 10000007
typedef vector<int> vi;
int n, m, p[123], q[123];
int Color[N], d[N];
int C1[12][12][12][12][12][12][12], MaxI1=0;
int C2[300005][12][2][2][2][2][2][2], MaxI2=0;

int of(const vi &a) {
	int &I1 = C1[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];
	if (I1==0) I1=++MaxI1;
	int x=a[8], y=a[9], z=a[10], t=a[11];
	int &I2 = C2[I1][a[7]][x>y][x>z][x>t][y>z][y>t][z>t];
	if (I2==0) I2=++MaxI2;
	return I2;
}

int bfs(const vi &a, const vi &b) {
	queue<vi> qu;
	qu.push(a); Color[of(a)]=1; d[of(a)]=0;
	qu.push(b); Color[of(b)]=2; d[of(b)]=0;

	vi u, v;
	while (qu.size()) {
		u.swap(qu.front()); qu.pop(); v=u;
		int U=of(u);
		for (int i=1; i<=m; i++) {
			swap(v[p[i]], v[q[i]]);
			int V=of(v);
			if (Color[V]==0) {
				qu.push(v);
				d[V] = d[U]+1;
				Color[V] = Color[U];
			} else if (Color[V]!=Color[U]) {
				return d[U] + d[V] + 1;
			}
			swap(v[p[i]], v[q[i]]);
		}
	}
	return -1;
}

main(){
	scanf("%d%d", &n, &m);
	vi S(12), T(12);
	for (int i=0; i<n; i++)
		{ scanf("%d", &S[i]); S[i]--; }
	for (int i=0; i<n; i++)
		T[i]=i;
	for (int i=1; i<=m; i++) {
		scanf("%d%d", &p[i], &q[i]);
		p[i]--, q[i]--;
	}
	cout << bfs(S, T) << endl;
}
