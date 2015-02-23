#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 52;
int n, Deg[N], Count[N];
char b[N][N];
bool Visited[N];

bool cycled(int u, int p) {
	Visited[u] = true;
	for (int i=1; i<=n; i++)
	if (i!=p && b[u][i]=='Y') {
		if (Visited[i]) return true;
		if (cycled(i, u)) return true;
	}
	return false;
}

main() {
	#define NIE cout << 0 << endl; return 0;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%s", b[i]+1);
	for (int i=1; i<=n; i++)
		if (!Visited[i] && cycled(i, i))
		{NIE}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		Deg[i] += (b[i][j]=='Y');
	for (int i=1; i<=n; i++)
		if (Deg[i] >= 3) {NIE}
		else Count[Deg[i]]++;
	long P=1, M=1000000007;
	long A = Count[0] + Count[1]/2;
	for (int i=1; i<=A; i++)
		P=P*i%M;
	long B = Count[1]/2;
	for (int i=1; i<=B; i++)
		P=P*2%M;
	//cerr << A << " " << B << endl;
	cout << P << endl;
}
