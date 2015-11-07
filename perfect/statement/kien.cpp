#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, a[N], F[N], H;

main() {
	scanf("%d%d", &n, &H);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
	if (H <= a[i]) {
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	
	if (n!=1 && a[1]<a[2]) 
		cout << 1 << endl;
	else 
		cout << 2 << endl;
	F[0]=1; F[1]=1; F[2]=2;
	for (int i=3; i<=n+1; i++)
	F[i] = (F[i-1] + F[i-2]) % 1000000000;
	cout << F[n+1] << endl;
}

