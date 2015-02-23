#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const int M = 1000000007;
long n; int L;

long F1[150][2][51][2][51];
bool F2[150][2][51][2][51];
#define C Depth][S][s][T][t

long f(long n, int S, int s, int T, int t, int Depth) {
	if (n==0 || s>L) return S==T && s==t;
	if (F2[C]++) return F1[C];
	long Sum = 0;
	if (n&1) {
		Sum = f(n-1, S, s+1, T, t, Depth+1) 
		    + f(n-1, !S, 1, T, t, Depth+1);
	} else {
		f0(k,2) f1(i,L) 
		Sum += f(n/2, S, s, k, i, Depth+1) 
		     * f(n/2, k, i, T, t, Depth+1) % M;
	}
	return F1[C] = Sum % M;
}

long g(int u, int S, int s) {
	if (u==n+1 || s>L) return s<=L;
	return (g(u+1, S, s+1) + g(u+1, !S, 1)) % M;
}

main(){
	cin >> n >> L;
	long Sum = 0;
	f0(k,2) f1(i,L) Sum += f(n-1, 0, 1, k, i, 0) + f(n-1, 1, 1, k, i, 0);
	cout << Sum % M << endl;
	//cout << g(1, 0, 0) << endl;
}
