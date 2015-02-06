#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<double, int> lfi;
typedef pair<double, double> lflf;
#define X first
#define Y second

#define each(i, a) (__typeof(a.begin()) i=a.begin(); i!=a.end(); i++)

int m, n;
double Ox, Oy;
vector<lfi> e;
lflf a[123];

lflf operator - (lflf a, lflf b)
	{ return lflf(a.X-b.X, a.Y-b.Y); }
double operator * (lflf a, lflf b)
	{ return a.X*b.Y-a.Y*b.X; }
void optimize(double &Min, double &Max, double x)
	{ if (Min>x) Min=x; if (Max<x) Max=x; }
void add(double x, int y) 
	{ e.push_back(lfi(x, y)); }
double angle(double x, double y)
	{ return atan2(y-Oy, x-Ox); }
double abs(double a, double b)
	{ return a>b?a-b:b-a; }
	
bool cmp(lfi a, lfi b) {
	if (abs(a.X, b.X)<=1e-9) return a.Y<b.Y;
	return a.X < b.X;
}

void solve(double &x1, double &x2){
	f1(i,n) { a[i].X-=Ox, a[i].Y-=Oy; }
	a[0]=a[n], a[n+1]=a[1];
	f1(i,n) {
		double BA = a[i]*(a[i-1]-a[i]);
		double BC = a[i]*(a[i+1]-a[i]);
		if (BA>1e-9 && BC>=-1e-9) x1=atan2(a[i].Y, a[i].X);
		if (BA<-1e-9 && BC<=1e-9) x2=atan2(a[i].Y, a[i].X);
	}
}

main(){
	scanf("%d%d%lf%lf", &n, &m, &Ox, &Oy);
	f0(i,n) {
		add(angle(0, i), 0);
		add(angle(i+1, 0), 0);
		add(angle(n, i+1), 0);
		add(angle(i, n), 0);
	}
	while (m-->0) {
		scanf("%d", &n);
		f1(i,n) scanf("%lf%lf", &a[i].X, &a[i].Y);
		
		double Min, Max;
		solve(Min, Max);
		if (Min>Max) swap(Min, Max);
		
		if (Max-Min<=M_PI) {
			add(Min, -1), add(Max, +1);
		} else {
			add(Max, -1), add(M_PI, +1);
			add(-M_PI, -1), add(Min, +1);
		}
	}
	sort(e.begin(), e.end(), cmp);
	int Level=0, Count=0, i=0;
	for each(it, e) {
		if (it->Y==0)
			Count += !Level;
		else
			Level += it->Y;
	}
	cout << Count << endl;
}
