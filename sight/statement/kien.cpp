#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int n, r, x[N], y[N];
double L[N], R[N];
vector<double> LL, RR;

main() {
	freopen("sight.inp", "r", stdin);
	freopen("sight.out", "w", stdout);
	
	scanf("%d%d", &n, &r);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		double t = acos(r / hypot(x[i], y[i]));
		double t0 = atan2(y[i], x[i]);
		
		L[i]=t0-t;
		LL.push_back(L[i]);
		LL.push_back(L[i]-2*M_PI);
		LL.push_back(L[i]+2*M_PI);
		
		R[i]=t0+t;
		RR.push_back(R[i]);
		RR.push_back(R[i]-2*M_PI);
		RR.push_back(R[i]+2*M_PI);
		//printf("L[%d]=%g, R=%g, %g, %g, %g, %g\n", i, 
		//	L[i]/M_PI, R[i]/M_PI, L[i]/M_PI-2, R[i]/M_PI-2, L[i]/M_PI+2, R[i]/M_PI+2);
	}
	
	sort(LL.begin(), LL.end());
	sort(RR.begin(), RR.end());
	//for (int i=0; i<LL.size(); i++) printf("%g ", LL[i]/M_PI); puts("LL");
	//for (int i=0; i<RR.size(); i++) printf("%g ", RR[i]/M_PI); puts("RR");
	
	long Sum = 0;
	for (int i=1; i<=n; i++) {
		int Sum1 = LL.end() - lower_bound(LL.begin(), LL.end(), R[i]-1e-12);
		int Sum2 = upper_bound(RR.begin(), RR.end(), L[i]+1e-12) - RR.begin();
		//printf("Sum1[%d] = %d, Sum2 = %d\n", i, Sum1, Sum2);
		Sum += LL.size() - (Sum1 + Sum2);
	}
	cout << (Sum-n)/2 << endl;
}
