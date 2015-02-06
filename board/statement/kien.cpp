#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 1000006
const int M = 1000000007;
long Fact[N];
#define IFact(x) power(Fact[x], M-2)

long power(long a, long k) {
	long P = 1;
	while (k) {
		if (k&1) P=P*a%M;
		a=a*a%M; k/=2;
	}
	return P;
}

main(){
	//freopen("board.inp", "r", stdin);
	//freopen("board.out", "w", stdout);
	Fact[0]=1; f1(i,N-1) Fact[i] = Fact[i-1] * i % M;
	int m, n; scanf("%d%d", &m, &n);
	long P = Fact[m*m-n*n];
	for (int i=1; i<=(m-n)/2; i++) 
	f0(k,4) P=P*IFact(i*2-1)%M;
	f1(i,n) f0(k,4) P=P*IFact((m-n)/2)%M;
	
	for (int i=1; i<=(m-n)/2; i++) f0(k,4) { 
		P=P*Fact[i*2-2]%M;
		P=P*IFact(i-1)%M;
		P=P*IFact(i-1)%M; 
	}
	cout << P << endl;
}
