#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<double, double> lflf;
typedef pair<lflf, double> line;
#define X first
#define Y second

#define N 2003
double Max=0, L, Best;
int n;
lflf A[N], B[N];

lflf operator - (lflf a, lflf b)
	{ return lflf(a.X-b.X, a.Y-b.Y); }
double operator ^ (lflf a, lflf b)
	{ return a.X*b.X+a.Y*b.Y; }
double xdf(lflf I, line d)
	{ return I.X*d.X.X+I.Y*d.X.Y-d.Y; }
double abs(lflf I)
	{ return sqrt(I.X*I.X+I.Y*I.Y); }
double abs(double x, double y)
	{ return x>y?x-y:y-x; }
double dist(lflf I, line d)
	{ return abs(xdf(I, d), 0.0) / abs(d.X); }
lflf fn(lflf a)
	{ return lflf(-a.Y, a.X); }
line xxfd(lflf a, lflf b)
	{ lflf n=fn(b-a); return line(n, n.X*a.X+n.Y*a.Y); }
double dist(lflf I, lflf A, lflf B){
	if (((B-A)^(I-A))>0 && ((A-B)^(I-B))>0) 
		return dist(I, xxfd(A, B));
	else 
		return min(abs(I-A), abs(I-B));
}

double f(double x){
	double Min = 23e9;
	x=max(0.0, min(x, L));
	f1(i,n) Min = min(Min, dist(lflf(x,0), A[i], B[i]));
	if (Max<Min) { Max=Min; Best=x; }
	return Min;
}

void climb(double x, double R, int Loop){
	while (Loop-->0) {
		double F1=f(x-R), F2=f(x), F3=f(x+R);
		if (F1>F2 && F1>F3) x-=R;
		else if (F3>F2 && F3>F1) x+=R;
		R/=2;
	}	
}

void random_drop(double L, double R, int Loop) {
	L=max(L, 0.0); R=min(R, ::L);
	double Range = R-L;
	while (Loop-->0)
	climb(L+Range*rand()/RAND_MAX, Range/(5<<rand()%10), Loop);
}

main(){
	scanf("%d%lf", &n, &L);
	f1(i,n) scanf("%lf%lf%lf%lf", &A[i].X, &A[i].Y, &B[i].X, &B[i].Y);
	
	Best=L/2, Max=f(L/2);
	for (int i=2; i<=64; i*=2)
	random_drop(Best-L/i, Best+L/i, 30);
	cout.precision(3);
	cout << fixed << Max << endl;
}
