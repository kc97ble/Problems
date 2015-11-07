#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
#define all(a) a.begin(), a.end()

const int N = 2003;
int n, x[N], y[N], c[N][N];
vector<ii> List[N];

int F[N][N];
bool FF[N][N];
#define C u][it-List[u].begin()

int f(int u, vector<ii> :: iterator it) {
	if (it==List[u].begin()) return 0;
	if (FF[C]++) return F[C];
	int Max = f(u, prev(it));
	if (int v=prev(it)->second) if (v!=u)
	Max = max(Max, f(v, lower_bound(all(List[v]), ii(c[u][v], 0)))+1);
	return F[C] = Max;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &x[i], &y[i]);
	
	#define sqr(x) ((x)*(x))
	for (int i=0; i<=n; i++)
	for (int j=0; j<=n; j++) {
		c[i][j] = sqr(x[i]-x[j])+sqr(y[i]-y[j]);
		List[i].push_back(ii(c[i][j], j));
	}
	for (int i=1; i<=n; i++)
	sort(all(List[i]));
	
	int Max = 0;
	for (int i=1; i<=n; i++)
	Max = max(Max, f(i, lower_bound(all(List[i]), ii(c[i][0], 0)))+1);
	cout << Max << endl;
}

