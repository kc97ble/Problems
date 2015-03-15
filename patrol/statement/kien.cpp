#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define N 1003
int n, x[N], y[N];
int ax, bx, mx;
int ay, by, my;

main(){
	cin >> n;
	cin >> ax >> bx >> mx;
	cin >> ay >> by >> my;
	for (int i=1; i<=n; i++) {
		x[i] = (ax*x[i-1]+bx)%mx;
		y[i] = (ay*y[i-1]+by)%my;
	}
	long Sum = 0;
	for (int i=1; i<=n; i++)
	for (int j=i+1; j<=n; j++) {
		int A=0, B=0;
		for (int k=1; k<=n; k++)
		if ((x[i]<x[k]) == (x[k]<x[j])) {
			if (y[k]<y[i] && y[k]<y[j]) A++;
			if (y[k]>y[i] && y[k]>y[j]) B++;
		}
		Sum += A*B;
	}
	cout << Sum << endl;
}

