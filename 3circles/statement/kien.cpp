#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

double abs(double a, double b)
	{ return a>b ? a-b : b-a; }
#define N 10004
bool ncp[N][N];

main() {	
	for (int k=2; k<N; k++)
	for (int i=k; i<N; i+=k)
	for (int j=k; j<N; j+=k)
	ncp[i][j] = true;
	
	int n;
	while (cin >> n) {
		long Sum = 0;
		for (int rra=1; rra*rra<=n; rra++)
		for (int rrb=1; rrb<=rra; rrb++)
		if (!ncp[rra][rrb]) 
		{
			long ra=rra*rra, rb=rrb*rrb;
			long kk = ra+rb+2*rra*rrb;
			long rc = (ra*rb*kk) / (ra+rb+2*rra*rrb);
			ra*=kk, rb*=kk;
			Sum += (n/ra+1) * (n/ra) / 2 * (ra+rb+rc);
		}
		cout << Sum << endl;
	}
}
