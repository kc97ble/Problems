#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<long, long> llll;
typedef vector<llll> polyline;
#define X first
#define Y second

void simplify(polyline &P) {
	polyline Q;
	sort(P.begin(), P.end());
	f0(i,P.size()) {
		while (Q.size() && Q.back().Y<=P[i].Y) Q.pop_back();
		Q.push_back(P[i]);
	}
	P.swap(Q);
}

llll ddfx(llll a, llll b) {
	long p = b.Y-a.Y;
	long q = a.X-b.X;
	long G = __gcd(abs(p), abs(q));
	if (llll(p, q)<llll()) G=-G;
	return llll(p/G, q/G);
}

long operator * (llll a, llll b)
	{ return a.X*b.Y-a.Y*b.X; }

void add_line(llll I, polyline &P) {
	P.push_back(I);
	#define n P.size()
	while (n>=3 && ddfx(P[n-3], P[n-2]) * ddfx(P[n-2], P[n-1]) >= 0)
	P.erase(P.end()-2);
	#undef n
}

long LastI = 0;

long h(long x, llll d)
	{ return d.X*x+d.Y; }

long query(long x, polyline &P) {
	while (LastI+1 < P.size() && h(x, P[LastI+1]) <= h(x, P[LastI])) LastI++;
	return h(x, P[LastI]);
}

polyline a, P;

main(){
	int n; scanf("%d", &n);
	f1(i,n) {
		int x, y;
		scanf("%d%d", &x, &y);
		a.push_back(llll(x, y));
	}
	simplify(a);

	long LastF = 0;
	f0(i,a.size()) {
		add_line(llll(a[i].Y, LastF), P);
		LastF = query(a[i].X, P);
	}
	cout << LastF << endl;
}
