#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, ii> typed_ii;
const int N = 502;
int n, m, T, V[N][N], L[N][N], b[N][N];
double d[N][N]; ii p[N][N];

bool minimize(double &a, double b)
	{ if (a!=a || a>b) a=b; else return false; return true; }

void trace(int u, int x) {
	vector<int> List;
	while (u!=0) {
		List.push_back(u);
		ii P = p[u][x];
		u=P.first; x=P.second;
	}
	List.push_back(0);
	reverse(List.begin(), List.end());
	for (int i=0; i<List.size(); i++)
	printf("%d ", List[i]);
	puts("");
}

double dijkstra(int u, int x, int T) {
	priority_queue<typed_ii> qu;
	memset(d, -1, sizeof d);
	d[u][x]=0; qu.push(typed_ii(0, ii(u, x)));
	
	while (qu.size()) {
		ii Top = qu.top().second; qu.pop();
		int u=Top.first, x=Top.second;
		if (u==T) {
			trace(u, x);
			return d[u][x];
		}
		for (int v=1; v<=n; v++) if (b[u][v]) {
			int y = (V[u][v] ? V[u][v] : x);
			if (minimize(d[v][y], d[u][x] + 1.*L[u][v]/y)) {
				qu.push(typed_ii(-d[v][y], ii(v, y)));
				p[v][y] = ii(u, x);
			}
		}
	}
	
	return 0.0/0.0;
}

main() {
	//freopen("speed.in", "r", stdin)&&
	//freopen("speed.out", "w", stdout);
	
	cin >> n >> m >> T;
	for (int i=1; i<=m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		b[x][y] = true;
		scanf("%d%d", &V[x][y], &L[x][y]);
	}
	cerr << dijkstra(0, 70, T) << endl;
}
