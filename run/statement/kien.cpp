#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 2003;
const int M = 1000000007;
int n, m, x[N], y[N], P[N], A[N];

int at(int x)
	{ return x==P[x] ? x : P[x]=at(P[x]); }
void join(int x, int y)
	{ P[at(x)]=at(y); }

main(){
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
		P[i]=i;
	A[0]=1; A[1]=3;
	for (int i=2; i<m; i++)
		A[i] = (A[i-1] * 3LL) % M;
	for (int i=0; i<m; i++)
		scanf("%d%d", &x[i], &y[i]);
	long Sum = 0;
	for (int i=m-1; i>=0; i--) {
		if (at(x[i])==at(0) && at(y[i])==at(n-1))
			Sum += A[i];
		else if (at(x[i])==at(n-1) && at(y[i])==at(0))
			Sum += A[i];
		else
			join(x[i], y[i]);
	}
	cout << Sum % M << endl;
}

