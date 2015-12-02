#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500005;
int n, Sum[N], F[N], p[N];
vector<int> List[N], a[N];

void solve(int u) {
	Sum[u] = 0;
	for (int v: a[u]) 
		Sum[u] ^= F[v];
	List[u].push_back(Sum[u]);
	for (int v: a[u]) {
		for (int x: List[v])
		List[u].push_back(x ^ F[v] ^ Sum[u]);
	}
	#define all(a) a.begin(), a.end()
	#define unique(a) a.erase(unique(all(a)), a.end())
	sort(all(List[u])); unique(List[u]);
	for (int i=0; i<List[u].size(); i++)
	if (List[u][i] != i) { F[u]=i; return; }
	F[u]=List[u].size();
}

main() {
	scanf("%d", &n);
	for (int i=2; i<=n; i++) {
		scanf("%d", &p[i]);
		a[p[i]].push_back(i);
	}
	for (int i=n; i>=1; i--) {
		solve(i);
		/*printf("F[%d] = %d\n", i, F[i]);
		for (int x: List[i]) printf("%d ", x);
		printf("List[%d]\n", i);*/
	}
	int Count = 0;
	for (int i=1; i<=n; i++)
		Count += !!Sum[i];
	cout << Count << endl;
}

