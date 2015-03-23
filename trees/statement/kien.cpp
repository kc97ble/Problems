#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int L, n, a[N];

main() {
	scanf("%d%d", &L, &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	int GCD = 0;
	for (int i=2; i<=n; i++)
		GCD = __gcd(GCD, a[i]-a[i-1]);
	if (GCD==0) {
		long Sum = 0;
		for (int k=1; k<=L; k++) {
			int A = (a[1]-1)/k+1;
			int B = (L-a[n])/k+1;
			for (int i=1; i<100000008 && k+i<=L; i*=2) { // prevent k+i from overflowing
				int A1 = (a[1]-1)/(k+i)+1;
				int B1 = (L-a[n])/(k+i)+1;
				if (A1==A && B1==B) { 
					Sum += i*(1LL*A*B-1); 
					//printf("+= %lld, k=%d..%d\n", 1LL*A*B, k, k+i-1);
					k+=i; 
				}
				else break;
			}
			//printf("+= %lld, k=%d\n", 1LL*A*B-1, k);
			Sum += 1LL*A*B-1;
		}
		cout << Sum+1 << endl;
	} else {
		vector<int> List;
		for (int i=1; i*i<=GCD; i++) if (GCD%i==0) {
			List.push_back(i);
			if (i*i!=GCD)
			List.push_back(GCD/i);
		}
		long Sum = 0;
		for (int i=0; i<List.size(); i++) {
			int k = List[i];
			int A = (a[1]-1)/k+1;
			int B = (L-a[n])/k+1;
			Sum += 1LL*A*B;
		}
		cout << Sum << endl;
	}
}
