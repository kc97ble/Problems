#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005, M = 1000000000;
int n, H, a[N], F[N];

main() {
	scanf("%d%d", &n, &H);
	int Count = 0;
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		if (a[i]<a[i-1]) Count++;
		else Count=1;
	}
	if (H<=*max_element(a+1, a+n+1)) {
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	cout << (Count==3 ? 1 : 2) << endl;
	
	F[0]=1; F[1]=1; F[2]=2; F[3]=4;
	for (int i=4; i<=n+1; i++)
	F[i] = ((F[i-1] + F[i-2]) % M + F[i-3]) % M;
	cout << F[n+1] << endl;
}

