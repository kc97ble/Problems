#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, a[N], b[N], k;

main() {
	freopen("mutation.inp", "r", stdin);
	freopen("mutation.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	while (k-->0) {
		for (int i=1; i<=n; i++) b[i]=0;
		for (int i=1; i<=n; i++) b[a[i]]++;
		
		bool Same = true;
		for (int i=1; i<=n; i++)
		if (a[i]!=b[i]) { Same=false; break; }
		
		if (Same) break;
		for (int i=1; i<=n; i++)
		a[i] = b[i];
	}
	for (int i=1; i<=n; i++)
	printf("%d ", a[i]);
	cout << endl;
}
