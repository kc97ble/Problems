#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
typedef pair<long, long> llll;
typedef vector<llll> convex;
#define X first
#define Y second

#define N 1000006
const int oo = 0x3c3c3c3c;
int n, A, B, C, a[N];
long s[N];
convex T;

llll ddfx(llll a, llll b) {
	long p = b.Y-a.Y;
	long q = a.X-b.X;
	long G = __gcd(abs(p), abs(q));
	if (llll(p, q)<llll()) G=-G;
	return llll(p/G, q/G);
}

long operator * (llll a, llll b) {
	return a.X*b.Y-a.Y*b.X;
}

void add_line(llll I, vector<llll> &T) {
	if (T.size() && T.back().X>=I.X) return;
	T.push_back(I);
	#define n T.size()
	while (n>=3 && ddfx(T[n-3], T[n-2]) * ddfx(T[n-2], T[n-1]) >= 0)
	T.erase(T.end()-2);
	#undef n
}

long h(long x, llll d) {
	return d.X*x+d.Y;
}

long query(long x, convex &T){
	int ll=0, rr=T.size()-1, ml=(ll+ll+rr)/3, mr=(ll+rr+rr)/3;
	while (ll<ml && ml<mr && mr<rr) {
		if (h(x, T[ml]) >= h(x, T[mr])) rr=mr; else ll=ml;
		ml=(ll+ll+rr)/3, mr=(ll+rr+rr)/3;
	}
	long Max = -1LL*oo*oo;
	for (int i=ll; i<=rr; i++)
	Max = max(Max, h(x, T[i]));
	return Max;
}

main(){
	scanf("%d%d%d%d", &n, &A, &B, &C);
	f1(i,n) scanf("%d", &a[i]);
	f1(i,n) s[i]=s[i-1]+a[i];
	
	long LastF = 0;
	add_line(llll(0, 0), T);
	f1(i,n) {
		LastF = query(s[i], T) + A*s[i]*s[i] + B*s[i] + C;
		add_line(llll(-2*A*s[i], -B*s[i] + A*s[i]*s[i] + LastF), T);
	}
	cout << LastF << endl;
}
