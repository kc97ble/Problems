#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> lflf;
#define X first
#define Y second

const int N = 20004;
int n, x[N], y[N], L[N], R[N];
int MinY, MaxY;
ii LR[N], HeadLR[N], TailLR[N], xy[N];
bool b[123][123];
double HeadCost[N], TailCost[N];
double c[123][123];

bool over(ii p, ii q)
	{ return p.X<=q.X && q.Y<=p.Y; }
bool inorder(int x, int y, int z)
	{ return x<=y && y<=z || z<=y && y<=x; }
bool strict_inorder(int x, int y, int z)
	{ return x<y && y<z || z<y && y<x; }
bool inorder(double x, double y, double z)
	{ return x<=y+1e-9 && y<=z+1e-9 || z<=y+1e-9 && y<=x+1e-9; }
bool strict_inorder(double x, double y, double z)
	{ return x<=y-1e-9 && y<=z-1e-9 || z<=y-1e-9 && y<=x-1e-9; }
double x_intersect(lflf a, lflf b, double y)
	{ return (b.X-a.X) / (b.Y-a.Y) * (y-a.Y) + a.X; }
ii operator & (ii a, ii b)
	{ return ii(max(a.X, b.X), min(a.Y, b.Y)); }
bool operator ! (ii a)
	{ return a.X>a.Y; }

int head() {
	for (int i=MinY+1; i<=MaxY; i++)
		if (!over(LR[i], LR[i-1]))
		return i-1;
	return MaxY;
}

int tail() {
	for (int i=MaxY-1; i>=MinY; i--)
		if (!over(LR[i], LR[i+1]))
		return i+1;
	return MinY;
}

void enter() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i] += 10000, y[i] += 10000;
	}
	x[0]=x[n]; y[0]=y[n]; // done x, y

	for (int i=1; i<=n; i++)
	if (x[i]==x[i-1]) {
		if (y[i]>y[i-1])
			for (int j=y[i-1]; j<y[i]; j++)
			R[j] = x[i];
		else
			for (int j=y[i]; j<y[i-1]; j++)
			L[j] = x[i];
	} // done L, R

	MinY = *min_element(y+1, y+n+1);
	MaxY = *max_element(y+1, y+n+1) - 1;

	for (int i=1; i<=n; i++)
		xy[i] = ii(x[i], y[i]);
	for (int i=MinY; i<=MaxY; i++)
		LR[i] = ii(L[i], R[i]);
	for (int i=MinY; i<=MaxY; i++)
		if (i==MinY) HeadLR[i]=LR[i];
		else HeadLR[i] = LR[i] & HeadLR[i-1];
	for (int i=MaxY; i>=MinY; i--)
		if (i==MaxY) TailLR[i]=LR[i];
		else TailLR[i] = LR[i] & TailLR[i+1];
	// done MinY, MaxY, LR, HeadLR, TailLR
}

bool visible(ii a, ii b) {
	if (a.Y==b.Y) return true;
	if (a.Y > b.Y) swap(a, b);

	for (int k=1; k<=n; k++)
	if (a.Y<y[k] && y[k]<b.Y) {
		double ix=x_intersect(a, b, y[k]);
		double A=max(L[y[k]-1], L[y[k]]), B=min(R[y[k]-1], R[y[k]]);
		if (!inorder(A, ix, B)) return false;
	}
	if (!(LR[a.Y] & ii(a.X, a.X)))
		return false;
	if (!(LR[b.Y-1] & ii(b.X, b.X)))
		return false;
	return true;
}

bool minimize(double &a, double b)
	{ if (a>b) a=b; else return false; return true; }
double dist(ii a, ii b)
	{ return hypot(a.X-b.X, a.Y-b.Y); }

main() {
	enter();
	//for (int i=MinY; i<=MaxY; i++) { for (int j=1; j<=L[i]; j++) printf(" "); for (int j=1; j<=R[i]-L[i]; j++) printf("#"); puts(""); }

	#define return(x) return printf("%.5lf\n", double(x)*2), 0
	int Head=head(), Tail=tail();
	//printf("Head=%d, Tail=%d\n", Head, Tail);
	if (Head >= Tail-1) {
		if (L[MinY] > R[MaxY]) return(L[MinY]-R[MaxY]);
		if (L[MaxY] > R[MinY]) return(L[MaxY]-R[MinY]);
		return(0);
	}

	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) {
		b[i][j] = visible(xy[i], xy[j]);
		c[i][j] = (b[i][j] ? dist(xy[i], xy[j]) : (1.0/0.0));
	}
	for (int k=1; k<=n; k++)
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
//	for (int i=1; i<=n; i++) { for (int j=1; j<=n; j++) printf("%d", b[i][j]); printf(" b[%d]\n", i); }
//	for (int i=MinY; i<=MaxY; i++) printf("HeadLR[%d] = %d..%d, TailLR=%d..%d\n", i, HeadLR[i].X, HeadLR[i].Y, TailLR[i].X, TailLR[i].Y);

	double Min=(1.0/0.0);
	ii AA(L[MinY], Head+1), BB(R[MinY], Head+1);
	ii CC(L[MaxY], Tail), DD(R[MaxY], Tail);
	if (visible(AA, CC)) Min=min(Min, dist(AA, CC));
	if (visible(AA, DD)) Min=min(Min, dist(AA, DD));
	if (visible(BB, CC)) Min=min(Min, dist(BB, CC));
	if (visible(BB, DD)) Min=min(Min, dist(BB, DD));

	if (!!(LR[MinY] & LR[MaxY])) {
		double jx = (max(AA.X, CC.X) + min(BB.X, DD.X)) / 2.0;
		if (visible(ii(jx, Head+1), ii(jx, Tail)))
		Min = min(Min, double(Tail-Head-1));
	}

	/*if (visible(AA, CC) && visible(AA, DD) && inorder(CC.X, AA.X, DD.X)) Min = min(Min, double(Tail-Head-1));
	if (visible(BB, CC) && visible(BB, DD) && inorder(CC.X, BB.X, DD.X)) Min = min(Min, double(Tail-Head-1));
	if (visible(CC, AA) && visible(CC, BB) && inorder(AA.X, CC.X, BB.X)) Min = min(Min, double(Tail-Head-1));
	if (visible(DD, AA) && visible(DD, BB) && inorder(AA.X, DD.X, BB.X)) Min = min(Min, double(Tail-Head-1));*/
//	printf("AA=%d:%d, BB=%d:%d\n", AA.X, AA.Y, BB.X, BB.Y);
//	printf("CC=%d:%d, DD=%d:%d\n", CC.X, CC.Y, DD.X, DD.Y);

	for (int i=1; i<=n; i++)
		{ HeadCost[i]=TailCost[i]=(1.0/0.0); }
	for (int i=1; i<=n; i++) {
		if (visible(AA, xy[i])) minimize(HeadCost[i], dist(AA, xy[i]));
		if (visible(BB, xy[i])) minimize(HeadCost[i], dist(BB, xy[i]));
		if (visible(CC, xy[i])) minimize(TailCost[i], dist(CC, xy[i]));
		if (visible(DD, xy[i])) minimize(TailCost[i], dist(DD, xy[i]));
	}
	for (int i=1; i<=n; i++) if (y[i]>Head)
		if (!!(HeadLR[y[i]-1] & ii(x[i], x[i])))
		minimize(HeadCost[i], abs(y[i]-(Head+1)));
	for (int i=1; i<=n; i++) if (y[i]<=Tail)
		if (!!(TailLR[y[i]] & ii(x[i], x[i])))
		minimize(TailCost[i], abs(y[i]-Tail));
//	for (int i=1; i<=n; i++) printf("%g", HeadCost[i]); printf("HeadCost\n");
//	for (int i=1; i<=n; i++) printf("%g", TailCost[i]); printf("TailCost\n");

	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	Min = min(Min, c[i][j]+HeadCost[i]+TailCost[j]);

	return (Min);
}

