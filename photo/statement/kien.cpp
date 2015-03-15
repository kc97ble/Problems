#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20004;
int n, a[5][N], b[N];
map<int, int> Pos[5];

bool cmp(int x, int y) {
	int Count = 0;
	for (int k=0; k<=4; k++)
	Count += Pos[k][x]<Pos[k][y];
	return Count >= 3;
}

main() {
	scanf("%d", &n);
	for (int k=0; k<=4; k++)
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[k][i]);
		Pos[k][a[k][i]]=i;
	}
	for (int i=1; i<=n; i++)
		b[i] = a[0][i];
	sort(b+1, b+n+1, cmp);
	for (int i=1; i<=n; i++)
		printf("%d\n", b[i]);
}
