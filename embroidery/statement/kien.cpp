#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<double, double> lflf;
typedef pair<lflf, double> line;
typedef pair<double, int> lfi;
#define X first
#define Y second

#define N 100005
const int oo = 1000000000;
int n, Position[N];
double R;
vector<lfi> T;

lflf operator + (lflf a, lflf b)
	{ return lflf(a.X+b.X, a.Y+b.Y); }
lflf operator - (lflf a, lflf b)
	{ return lflf(a.X-b.X, a.Y-b.Y); }
lflf operator * (lflf a, double x)
	{ return lflf(a.X*x, a.Y*x); }
lflf operator ! (lflf a)
	{ return lflf(-a.Y, a.X); }
double abs(lflf a)
	{ return sqrt(a.X*a.X+a.Y*a.Y); }
double abs(double a, double b)
	{ return a>b ? a-b : b-a; }

line normalize(line d) { 
	double x=abs(d.X);
	d.X.X/=x, d.X.Y/=x, d.Y/=x;
	return d; 
}

bool try_dcfx(line d, double R, lflf &I1, lflf &I2) {
	double h = -d.Y;
	lflf H = d.X*d.Y; // (0,0) into d
	//printf("d=%lfx%+lfy=%lf\n", d.X.X, d.X.Y, d.Y);
	//printf("H = %lf, %lf\n", H.X, H.Y);
	if (abs(R, h)<=1e-9) { I1=I2=H; return true; }
	if (h>R) return false;
	double a = sqrt(R*R-h*h);
	I1=H+(!d.X)*a, I2=H-(!d.X)*a;
	return true;
}

bool lfi_cmp(lfi a, lfi b) { 
	if (abs(a.X, b.X)<=1e-9) return a.Y<b.Y;
	return a.X<b.X;
}

struct fenwick_tree {
	int T[N];
	void update(int u, int x)
		{ for (int i=u; i<N; i+=i&-i) T[i]+=x; }
	int get(int u)
		{ int Sum=T[u]; while (u-=u&-u) Sum+=T[u]; return Sum; }
} tr;

main(){
	scanf("%d%lf", &n, &R);
	f1(i,n) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		line d = normalize(line(lflf(x, y), -z));
		lflf I1, I2;
		if (try_dcfx(d, R, I1, I2)) {
			if (atan2(I2.Y, I2.X) < atan2(I1.Y, I1.X)) swap(I1, I2);
			//printf("(%lf, %lf)[%lf], (%lf, %lf)[%lf]\n", I1.X, I1.Y, 
			//	atan2(I1.Y, I1.X), I2.X, I2.Y, atan2(I2.Y, I2.X));
			T.push_back(lfi(atan2(I1.Y, I1.X), i));
			T.push_back(lfi(atan2(I2.Y, I2.X), i+oo));
		}
	}
	sort(T.begin(), T.end(), lfi_cmp);
	
	long Sum=0; int NewPosition=1;
	f0(i,T.size()) {
		if (T[i].Y<oo)
			tr.update(Position[T[i].Y]=NewPosition++, 1);
		else {
			int x = Position[T[i].Y-oo];
			Sum += tr.get(N-1) - tr.get(x);
			tr.update(x, -1);
		}
	}
	cout << Sum << endl;
}
