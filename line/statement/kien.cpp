#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int n; double D;
double x[N], y[N], z[N];

typedef pair<int, double> ilf;

ilf h(double k) {
	double u=sin(k), v=cos(k);
	for (int i=1; i<=n; i++)
		z[i] = u*x[i]+v*y[i];
	sort(z+1, z+n+1);
	
	ilf Max(0, 0);
	int j = 1;
	for (int i=1; i<=n; i++) {
		while (z[i]-z[j] > D+1e-9) j++;
		Max = max(Max, ilf(i-j+1, j==1 ? -23e9 : z[j-1]-z[i]));
	}
	//printf("h(%lf, %lf, %lf) = %d, %lf\n", k/M_PI, u, v, Max.first, Max.second);
	return Max;
}

ilf g(double &k, double R, int Loop) {
	ilf Max=h(k);
	while (Loop--) {
		R/=2;
		ilf H1 = h(k-R);
		ilf H2 = h(k+R);
		if (Max<H1 || Max<H2)
			if (H1>H2) { Max=H1, k-=R; }
			else { Max=H2, k+=R; }
	}
	return Max;
}

main() {
	scanf("%d%lf", &n, &D); D*=2;
	for (int i=1; i<=n; i++)
	scanf("%lf%lf", &x[i], &y[i]);
	
	const int C = 180;
	ilf Max(0, -23e9);
	double Best=-1.0;
	for (int i=-C; i<=C; i++) {
		double k = i*M_PI/C;
		ilf G = g(k, M_PI/C, 10);
		if (G>Max) { Max=G, Best=k; }
	}
	Max = g(Best, M_PI/C, 100);
	cout << Max.first << endl;
}
