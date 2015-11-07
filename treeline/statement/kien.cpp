#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 200005, M = 1000000000;
int n, a[N]; bool np[N];
vector<int> Primes;

struct factors {
	int b[N];
	int deg(int k, int n) 
		{ return n<k ? 0 : n/k + deg(k, n/k); }
	void add_fact(int n)
		{ for (auto p: Primes) b[p]+=deg(p, n); }
	void rem_fact(int n)
		{ for (auto p: Primes) b[p]-=deg(p, n); }
		
	long module(int M) { 
		long P=1; 
		for (auto p: Primes) 
		for (int i=1; i<=b[p]; i++)
		P=P*p%M; 
		return P; 
	}
} W1, W2;

main() {
	for (int i=2; i*i<N; i++) if (!np[i])
	for (int j=i*i; j<N; j+=i) np[j]=true;
	
	for (int i=2; i<N; i++)
	if (!np[i]) Primes.push_back(i);
	
	int Count = 0;
	scanf("%d%*d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		if (a[i]>a[i-1]) Count++;
		else Count=1;
	}
	cout << Count+1 << endl;
	
	n++;
	W1.add_fact(2*n), W1.rem_fact(n), W1.rem_fact(n);
	W2.add_fact(2*n), W2.rem_fact(n-1), W2.rem_fact(n+1);
	cout << (W1.module(M) - W2.module(M) + M) % M << endl;
}

