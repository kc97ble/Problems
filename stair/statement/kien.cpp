#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const int M = 1000000122; // 2×3×11×2089×7253
long m[6]={2,3,11,2089,7253,0};

long power(long a, long k, long M){
	long P = 1;
	while (k){
		if (k&1) P=P*a%M;
		k/=2, a=a*a%M;
	}
	return P;
}

long choose(long k, long n, long M){
	long P = 1;
	f0(i,k) P = P * (n-i) * power(i+1, M-2, M) % M;
	//printf("choose(%lld, %lld, %lld) = %lld\n", k, n, M, P);
	return P;
}

long lucas(long k, long n, long M){
	long P = 1;
	while (k || n){
		P = P * choose(k%M, n%M, M) % M;
		k/=M, n/=M;
	}
	//printf("lucas(%lld, %lld, %lld) = %lld\n", k, n, M, P);
	return P;
}

long choose_np(long k, long n, long M, long m[]){
	long S = 0;
	for (int i=0; int p=m[i]; i++) {
		int r=lucas(k, n, p);
		S += r * (M/p) * power(M/p, p-2, p);
	}
	//printf("choose_np(%lld, %lld, %lld) = %lld\n", k, n, M, S%M);
	return S % M;
}

main(){
	long n, k;
	cin >> n >> k;
	long Cn = choose_np(n, 2*n, M, m) - choose_np(n-1, 2*n, M, m) + M;
	cout << power(k, Cn, M+1) << endl;
}
