#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int index_of(int x, int k) {
	int L = (1LL<<k)-1;
	int M = L + (1LL<<k-1);
	if (x<M) return (x-L)*2;
	return (x-M)*2+1;
}

int value_of(int x, int k) {
	int L = (1LL<<k)-1;
	int M = L + (1LL<<k-1);
	if (~x&1) return L+(x/2);
	return M+(x/2);
}

int depth_of(int x) {
	int k=0;
	while ((1LL<<k)-1 <= x) k++;
	return k-1;
}

main() {
	int n; 
	while (cin >> n) {
		if (n==0) {
			cout << 0 << endl;
			cout << 1 << " " << 2 << endl;
		} else {
			int k = depth_of(n);
			int i = index_of(n, k);
			cout << value_of(i/2, k-1) << endl;
			cout << value_of(i*2, k+1) << " " << value_of(i*2+1, k+1) << endl;
		}
	}
}
