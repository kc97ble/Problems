#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int n, m, t;
bool End[N];
int Prev[N], Last[N], Data[N]; // graph
int Color[N]; // of level

void visit(int u, int c, int l) {
	if (End[u]) Color[l]=c;
	for (int i=Last[u]; int v=Data[i]; i=Prev[i])
	visit(v, c, l+1);
}

int f(int u) {
	if (End[u]) return 0;
	return f(Data[Last[u]]) + 1;
}

main() {
	freopen("suffix.in", "r", stdin);
	freopen("suffix.out", "w", stdout);
	cin >> n >> m >> t;
	for (int i=1; i<=t; i++)
		{ int x; scanf("%d", &x); End[x]=true; }
	for (int i=1; i<=m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		Prev[i] = Last[x];
		Data[i] = y;
		Last[x] = i;
	}
	int Count = 0;
	for (int i=Last[1]; i!=0; i=Prev[i])
		visit(Data[i], ++Count, 0);
	int L=0; while (Color[L]) L++;
	cout << L << " " << Count << endl;
	for (int i=L-1; i>=0; i--) printf("%d ", Color[i]); printf("\n");
	for (int i=1; i<=m; i++) printf("%d ", Color[f(Data[i])]); printf("\n");
}
