#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, double> lflf;
typedef pair<lflf, double> line;
#define X first
#define Y second

lflf operator - (lflf a, lflf b)
	{ return lflf(a.X-b.X, a.Y-b.Y); }
lflf operator ! (lflf a)
	{ return lflf(-a.Y, a.X); }
line xxfd(lflf a, lflf b) 
	{ lflf n=!(b-a); return line(n, n.X*a.X+n.Y*a.Y); }
double xdf(lflf a, line d)
	{ return d.X.X*a.X+d.X.Y*a.Y-d.Y; }
double dist(lflf a, lflf b)
	{ return hypot(a.X-b.X, a.Y-b.Y); }
bool in_order(double a, double b, double c)
	{ return a<=b+1e-9 && b<=c+1e-9 || c<=b+1e-9 && b<=a+1e-9; }
bool in_order(lflf a, lflf b, lflf c)
	{ return in_order(a.X, b.X, c.X) && in_order(a.Y, b.Y, c.Y); }
	
lflf operator * (line a, line b) {
	double D = a.X.X*b.X.Y - a.X.Y*b.X.X;
	double DX = a.Y*b.X.Y - a.X.Y*b.Y;
	double DY = a.X.X*b.Y - a.Y*b.X.X;
	return lflf (DX/D, DY/D);
}

const int N = 11;
int n, x[N], y[N];
lflf a[N];

int gain(int p, int q) {
	line d = xxfd(a[p], a[q]);
	int Or = 0;
	for (int i=1; i<=n; i++)
	if (fabs(xdf(a[i], d)) <= 1e-9)
	if (in_order(a[p], a[i], a[q]))
	Or |= (1<<i-1);
	return Or;
}

double F[10][10][1<<10][20];
bool FF[10][10][1<<10][20];
#define C p-1][q-1][Used][Limit

double f(int p, int q, int Used, int Limit) {
	if (Used==(1<<n)-1) return 0;
	if (Limit==0) return 1.0/0.0;
	if (FF[C]++) return F[C];
	
	double Min = 1.0/0.0;
	for (int i=1; i<=n; i++) if (i!=p && i!=q)
	Min = min(Min, f(q, i, Used | gain(q, i), Limit-1) 
		+ dist(a[i], a[q]));
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (i!=j && i!=q && j!=q && i!=p && j!=p) {
		lflf I = xxfd(a[p], a[q]) * xxfd(a[i], a[j]);
		if (isfinite(I.X) && isfinite(I.Y)) // math.h
		if (in_order(a[p], a[q], I) && in_order(I, a[i], a[j]))
		Min = min(Min, f(i, j, Used | gain(i, j), Limit-1) 
			+ dist(a[q], I) + dist(I, a[j]));
	}
	//printf("f(%d, %d, %d, %d) = %lf\n", p, q, Used, Limit, Min);
	return F[C] = Min;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		a[i] = lflf(x[i], y[i]);
	}
	
	double Min = 1.0/0.0;
	int MinK = 2309;
	
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (i!=j) {
		for (int k=0; k<=MinK; k++) {
			double fx = f(i, j, gain(i, j), k) + dist(a[i], a[j]);
			if (isfinite(fx)) { 
				//printf("F[%d, %d] = %lf\n", i, j, fx);
				if (k<MinK || Min>fx)
				{ Min=fx; MinK=k; }
				break; 
			}
		}
	}
	printf("%.4lf\n", Min);
}

