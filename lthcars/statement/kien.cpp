#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10004;
int n, a[N], b[N];

int sum(int a[], int n) {
	int Sum = 0;
	for (int i=1; i<=n; i++)
	Sum += a[i];
	return Sum;
}

main() {
	while (scanf("%d", &n) > 0) {
		for (int i=1; i<=n; i++)
		scanf("%d%d", &a[i], &b[i]);
		int Max = max(sum(a, n), sum(b, n));
		for (int i=1; i<=n; i++)
		Max = max(Max, a[i]+b[i]);
		cout << Max << endl;
	}
}
