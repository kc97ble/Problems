#include <bits/stdc++.h>
using namespace std;

const int N = 6703;
int n, k, a[N], F[N];

int f(int n) {
	if (n<=0) return 0;
	if (F[n]) return F[n];
	
	int Min = 0x3c3c3c3c;
	for (int i=1; i<=k; i++)
	Min = min(Min, f(n-i)+a[n]);
	return F[n] = Min;
}

main() {
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	int Sum=0;
	for (int i=1; i<=n; i++)
	Sum += a[i];
	
	int Min = 0x3c3c3c3c;
	for (int i=1; i<=k; i++)
	Min = min(Min, f(n+1-i));
	
	cout << Sum - Min << endl;
}
