#include <stdio.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

long sum1(int k, int n) {
	long Sum = 0;
	for (int i=0; i<n; i++)
	if (k & (1<<i)) Sum += i;
	return Sum;
}

long sum2(int k, int n) {
	long Sum = 0;
	for (int i=0; i<n; i++)
	if (k & (1<<i)) Sum += i*i;
	return Sum;
}

bool solve(int n, vector<int> &T) {
	for (int i=0; i<(1<<n); i++)
	if (sum1(i, n) == sum1(~i, n))
	if (sum2(i, n) == sum2(~i, n)) {
		for (int j=0; j<n; j++)
		if (i & (1<<j))
		T.push_back(j);
		return true;
	}
	return false;
}

const int b[] = {1,0,0,1,0,1,1,0};

main() {
	int n; scanf("%d", &n);
	int k = n;
	if (k > 12) k=(k-12)%8+12;
	
	vector<int> T;
	if (solve(k, T)) {
		for (int i=k; i<n; i++)
		if (b[(n-i-1)%8]) T.push_back(i);
		cout << "YES" << endl;
		long Sum1 = 0, Sum2 = 0;
		for (int i=0; i<T.size(); i++) {
			Sum1 += T[i];
			Sum2 += 1LL*T[i]*T[i];
			printf("%d ", T[i]);
		}
		cout << endl;
		
		long Sum1N = 0, Sum2N = 0;
		for (int i=0; i<n; i++) {
			Sum1N += i;
			Sum2N += 1LL*i*i;
		}
		cerr << Sum1 << " " << Sum1N << endl;
		cerr << Sum2 << " " << Sum2N << endl;
		assert(Sum1*2 == Sum1N);
		assert(Sum2*2 == Sum2N);
	} else {
		cout << "NO" << endl;
	}
}

