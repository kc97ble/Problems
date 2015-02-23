#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

int f(int n, int p) // deg n! p
	{ return n<p ? 0 : n/p + f(n/p, p); }

int choose(int n, int k, int p) 
	{ return f(n, p) - f(k, p) - f(n-k, p); }

main() {
	int n, m; cin >> n >> m;
	int b[123], bb[123], k=0;
	
	for (int i=2; i*i<=m; i++)
	if (m%i==0) {
		b[k++]=i; bb[k-1]=0;
		while (m%i==0) { m/=i; bb[k-1]++; }
	}
	if (m!=1) { b[k++]=m; bb[k-1]=1; }
	
	vector<int> Result;
	for (int i=0; i<n; i++) {
		bool All = true;
		for (int j=0; j<k; j++)
		if (choose(n-1, i, b[j]) < bb[j])
		{ All=false; break; }
		if (All) Result.push_back(i+1);
	}
	
	cout << Result.size() << endl;
	for (int i=0; i<Result.size(); i++)
	printf("%d\n", Result[i]);
}
