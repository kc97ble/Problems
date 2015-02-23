#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<long, long> llll;
typedef pair<double, long> lfll;
typedef pair<lfll, llll> TPoint;
#define X first
#define Y second

llll operator - (llll a, llll b)
	{ return llll(a.X-b.X, a.Y-b.Y); }
double atan2(llll a) 
	{ return atan2(a.Y, a.X); }

#define N 1200
const int oo = 0x3c3c3c3c;
int n, m; long c[N][N];
TPoint a[N], b[20004];
#define _2(u) u.X, u.Y
#define _4(u) _2(u.X), _2(u.Y)

main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[i].Y = llll(x, y);
	}
	reverse(a, a+n);
	for (int i=0; i<n; i++)
		a[i+n]=a[i];
	
	scanf("%d", &m);
	for (int i=0; i<m; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		b[i].X.Y = z; b[i].Y = llll(x, y);
	}
	
	for (int i=0; i<n; i++) {
		double Just = -M_PI;
		for (int j=0; j<2*n; j++)
			a[j].X.X = 0.0;
		for (int j=i+1; j<i+n; j++) {
			a[j].X.X = atan2(a[j].Y-a[i].Y);
			while (a[j].X.X < Just-1e-9)
				a[j].X.X += 2*M_PI;
			Just = a[j].X.X;
		}
		
		for (int j=0; j<m; j++)
			b[j].X.X = atan2(b[j].Y-a[i].Y);
		sort(b, b+m);
		for (int j=0; j<m; j++) 
			{ b[j+m]=b[j]; b[j+m].X.X+=2*M_PI; }
		
		int p=i+1, q=0;
		while (b[q].X.X<a[i+1].X.X-1e-9) q++;
		
		long Sum = 0;
		for (int P=p; P<i+n; P++) {
			while (q<2*m && b[q].X.X<a[P].X.X-1e-9)
			{ Sum+=b[q].X.Y; q++; }
			c[i%n][P%n] = Sum;
		}
	}
	long Min=1LL*oo*oo, Sum=0;
	for (int i=0; i<m; i++)
		Sum += b[i].X.Y;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
		for (int k=j+1; k<n; k++)
		Min = min(Min, c[i][j] + c[j][k] + c[k][i]);
	cout << Sum - Min << endl;
}
