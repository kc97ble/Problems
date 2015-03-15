#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, double> lflf;
typedef pair<lflf, double> line;
#define X first
#define Y second

lflf operator ! (lflf a)
	{ return lflf(-a.Y, a.X); }
double operator ^ (lflf a, lflf b)
	{ return a.X*b.X+a.Y*b.Y; }
lflf operator - (lflf a, lflf b)
	{ return lflf(a.X-b.X, a.Y-b.Y); }
line xxfd(lflf a, lflf b)
	{ lflf n=!(b-a); return line(n, n^a); }

lflf ddfx(line a, line b) {
	double D = a.X.X*b.X.Y-a.X.Y*b.X.X;
	double DX = a.Y*b.X.Y-a.X.Y*b.Y;
	double DY = a.X.X*b.Y-a.Y*b.X.X;
	return lflf(DX/D, DY/D);
}

#define all(a) a.begin(), a.end()
#define N 1003
int n;
lflf a[N];

bool irrelevant(lflf I) {
	bool Negative=false, Positive=false;
	for (int i=0; i<n; i++) {
		line d = xxfd(a[i], a[i+1]);
		double H = (d.X^I)-d.Y;
		if (H<-1e-9) Negative=true;
		if (H>+1e-9) Positive=true;
		if (Negative && Positive) return true;
	}
	return false;
}

double abs(lflf u)
	{ return hypot(u.X, u.Y); }
double abs(double a, double b)
	{ return a>b ? a-b : b-a; }
bool in_order(double a, double b, double c)
	{ return a<=b+1e-9 && b<=c+1e-9 || c<=b+1e-9 && b<=a+1e-9; }
bool in_order(lflf a, lflf b, lflf c)
	{ return in_order(a.X, b.X, c.X) && in_order(a.Y, b.Y, c.Y); }

bool careful_cmp(lflf a, lflf b) {
	if (abs(a.X, b.X)<=1e-9)
		return a.Y<b.Y-1e-9;
	return a.X<b.X-1e-9;
}

main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%lf%lf", &a[i].X, &a[i].Y);
	a[n]=a[0];

	lflf A, B;
	scanf("%lf%lf", &A.X, &A.Y);
	scanf("%lf%lf", &B.X, &B.Y);
	line dAB = xxfd(A, B);

	vector<lflf> List;
	List.push_back(A);
	List.push_back(B);

	for (int i=0; i<n; i++) {
		line d = xxfd(a[i], a[i+1]);
		lflf I = ddfx(d, dAB);
		if (in_order(a[i], I, a[i+1]))
		if (in_order(A, I, B))
		List.push_back(I);
	}
	List.erase(remove_if(all(List), irrelevant), List.end());
	sort(all(List), careful_cmp);

	if (List.size() <= 1)
		cout << 0 << endl;
	else {
		double Result = abs(List.front()-List.back())*100;
		cout << long(Result) << endl;
	}
}
