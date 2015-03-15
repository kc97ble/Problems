#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, b[2003];

main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) {
		int x; scanf("%d", &x);
		b[x] = true;
	}
	int P = 1;
	for (int i=n; i>=1; i--)
		if (!b[i]) P=P*(n-i)%10007;
	cout << P << endl;
}