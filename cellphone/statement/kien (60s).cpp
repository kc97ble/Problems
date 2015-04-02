#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, double> ilf;
#define X first
#define Y second

const int N = 2003;
int n, X[N], Y[N];
double R;

ilf h(double x, double y) {
	int Count=0; double Min=23e9;
	for (int i=1; i<=n; i++) {
		double L = hypot(x-X[i], y-Y[i]);
		if (L <= R+1e-4) Count++;
		else Min = min(Min, L);
	}
	//printf("h(%lf, %lf) = %d, %lf\n", x, y, Count, -Min);
	return ilf(Count, -Min);
}

bool maximize(ilf &a, ilf b)
	{ if (a<b) a=b; else return false; return true; }

const int ax=10, bx=25, ay=10, by=25;

ilf climby(double x, double y) {
	ilf H = h(x, y);
	double R = 10000.0;
	for (int i=1; i<=by; i++) {
		ilf H1 = h(x, y-R);
		ilf H2 = h(x, y+R);
		if (H1>H && H1>=H2)
			{ y-=R; H=H1; }
		else if (H2>H && H2>=H1)
			{ y+=R; H=H2; }
		R/=2;
	}
	return H;
}

ilf climby(double x) {
	ilf Max(0, -23e9);
	for (int i=0; i<ay; i++)
	Max = max(Max, climby(x, (10000/ay)*(i+0.5)));
	return Max;
}

ilf climbx(double x) {
	double R=10000.0;
	ilf H = climby(x);
	for (int i=1; i<=bx; i++) {
		//printf("x=%lf, R=%lf, H=%d:%lf\n", x, R, H.X, H.Y);
		ilf H1 = climby(x-R);
		ilf H2 = climby(x+R);
		if (H1>H && H1>=H2)
			{ x=x-R; H=H1; }
		else if (H2>H && H2>=H1)
			{ x=x+R; H=H2; }
		R/=2;
	}
	return H;
}

ilf climbx() {
	ilf Max(0, -23e9);
	for (int i=0; i<ax; i++)
	Max = max(Max, climbx((10000.0/ax)*(i+0.5)));
	return Max;
}

main() {
	//freopen("input", "r", stdin);
	//freopen("output", "w", stdout);
	for (int t=1; ;t++) {
		cin >> n >> R;
		if (n==0) break;
		for (int i=1; i<=n; i++)
		scanf("%d%d", &X[i], &Y[i]);
		int Result = climbx().X;
		printf("It is possible to cover %d points.\n", Result);
		//fprintf(stderr, "t=%d, Result=%d, n=%d\n", t, Result, n);
	}
}
