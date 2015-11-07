#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 1000006, M = 111539786;
bool np[N];

int deg(int k, int a) {
	if (a<k) return 0;
	return a/k + deg(k, a/k);
}

main() {
//	freopen("lcm.inp", "r", stdin);
//	freopen("lcm.out", "w", stdout);
	
	np[0]=np[1]=true;
	for (int i=2; i*i<N; i++) if (!np[i])
	for (int j=i*i; j<N; j+=i)
	np[j]=true;
	
	int t; scanf("%d", &t);
	while (t-->0) {
		long P = 1;
		int A, B; scanf("%d%d", &A, &B);
		for (int i=2; i<=B; i++) if (!np[i]) {
			int x = deg(i, B) - deg(i, A-1);
			//printf("x[%d] = %d\n", i, x);
			P = (x*2+1) * P % M;
		}
		printf("%d\n", int(P));
	}
}
