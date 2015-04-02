#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1003, Depth=25;
int n, D, x[N], y[N];
double z[N];

double h(double t) {
	for (int i=1; i<=n; i++)
	z[i] = x[i]*sin(t) + y[i]*cos(t);
	sort(z+1, z+n+1);
	
	double Max = 0.0;
	int j=1;
	for (int i=1; i<=n; i++) {
		while (z[i]-z[j] > 2*D+1e-6) j++;
		double Frac = (j==1 ? 1e-6 : (2*D)/(z[i]-z[j-1]));
		Max = max(Max, i-j+1 + Frac);
	}
	return Max;
}

double climb(double t, double R) {
	double H = h(t);
	for (int i=1; i<=Depth; i++) {
		R/=2;
		double H1 = h(t-R);
		double H2 = h(t+R);
		if (H<H1 || H<H2) {
			if (H1>H2) { t-=R; H=H1; }
			else { t+=R; H=H2; }
		}
	}
	return H;
}

main() {
	scanf("%d%d", &n, &D);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &x[i], &y[i]);
	
	double Max = 0.0;
	const int B = 360;
	for (int i=0; i<B; i++)
	Max = max(Max, climb((2*M_PI)*i/B, (2*M_PI)/B));
	
	cerr << Max << endl;
	cout << int(Max) << endl;
}
