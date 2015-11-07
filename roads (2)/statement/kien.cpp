#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20004;
typedef pair<int, int> ii;
#define X first
#define Y second
int n, m, k;
vector<ii> Edge[2], Kept[2];
int Count[2];

struct djs {
	int P[N];
	djs()
		{ for (int i=0; i<N; i++) P[i]=i; }
	bool join(int x, int y)
		{ x=at(x); y=at(y); return x==y ? false : (P[x]=y, true); }
	int at(int x)
		{ return x==P[x] ? x : P[x]=at(P[x]); }
} Label1, Label2;

void try_keep(ii v, int k) {
	if (Label2.join(v.X, v.Y)) {
		//printf("keep %d %d %d\n", v.X, v.Y, k);
		Kept[k].push_back(v);
		Count[k]++;
	}
}

main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		Edge[z].emplace_back(x, y);
	}
	
	for (ii v: Edge[1])
		Label1.join(v.X, v.Y);
	for (ii v: Edge[0])
		if (Label1.join(v.X, v.Y))
		try_keep(v, 0);
	for (ii v: Edge[0])
		if (Count[0] >= k) break;
		else try_keep(v, 0);
	for (ii v: Edge[1])
		try_keep(v, 1);
	if (Count[0]==k && Count[1]==n-k-1) {
		for (ii v: Kept[0]) printf("%d %d 0\n", v.X, v.Y);
		for (ii v: Kept[1]) printf("%d %d 1\n", v.X, v.Y);
	} else {
		cout << "no solution" << endl;
	}
}

