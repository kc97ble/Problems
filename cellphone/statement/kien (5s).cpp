#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, double> ilf;
#define X first
#define Y second

const int N = 2003;
int n, x[N], y[N], R;
ilf Max; //

ilf h(int u, double t) {
	double xx=x[u]+R*sin(t), yy=y[u]+R*cos(t);
	int Count=0; double Min=9e23;
	for (int i=1; i<=n; i++) {
		double d = hypot(x[i]-xx, y[i]-yy);
		if (d<=R+1e-3) Count++;
		else Min=min(Min, d);
	}
	return ilf(Count, -Min);
}

const int Depth = 30;

int l(int u, double t, double dt) {
	int Count=0;
	double E = R*dt;
	double xx=x[u]+R*sin(t), yy=y[u]+R*cos(t);
	for (int i=1; i<=n; i++) {
		double d = hypot(x[i]-xx, y[i]-yy);
		if (d<=R+E+1e-3) Count++;
	}
	return Count;
}

ilf climb(int u, double x, double R) {
	ilf H = h(u, x);
	for (int i=1; i<=Depth; i++) {
		if (l(u, x, R) <= Max.X) return H;
		R/=2;
		ilf H1 = h(u, x-R);
		ilf H2 = h(u, x+R);
		if (H<H1 || H<H2) {
			if (H1>H2) { H=H1, x-=R; }
			else { H=H2, x+=R; }
		}
	}
	return H;
}

main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	for (;;) {
		scanf("%d%d", &n, &R);
		if (n==0) return 0;
		for (int i=1; i<=n; i++)
		scanf("%d%d", &x[i], &y[i]);
		Max = ilf(0, 9e23);
		const int B = 3;
		for (int i=1; i<=n; i++)
		for (int j=0; j<B; j++)
		Max = max(Max, climb(i, (2*M_PI)*j/B, (2*M_PI)/B));
		printf("It is possible to cover %d points.\n", Max.X);
		fprintf(stderr, "It is possible to cover %d points.\n", Max.X);
	}
}
