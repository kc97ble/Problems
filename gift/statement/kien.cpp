#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int oo = 0x3c3c3c3c;
int n, a[20];
long a1, a2, a3; //

bool maximize(int &a, int b)
	{ if (a<b) a=b; else return false; return true; }

int F[20][3][2][2][2];
int FF[20][3][2][2][2], t;
#define ff n][o][i0][ji][kj

int f(int n, int o, bool i0, bool ji, bool kj, bool Tracing=false) {
	if (o<0 || o>=3) return -oo;
	if (n==0) return o==0 && i0 && ji && kj ? 0 : -oo;
	if (!Tracing && FF[ff]==t) return F[ff];
	int Max=-oo, dx, dy, dz;
	
	for (int i=0; i<=9; i++)
	for (int j=0; j<=9; j++)
	for (int k=0; k<=9; k++)
	if (j>=i || ji)
	if (k>=j || kj) {
		int fx = f(n-1, (a[n-1]+o*10)-(i+j+k), i0||i>0, ji||j>i, kj||k>j);
		if (maximize(Max, fx+(i+j+k)))
		{ dx=i, dy=j, dz=k; }
	}
	if (Tracing) {
		int i=dx, j=dy, k=dz;
		a1=a1*10+i, a2=a2*10+j, a3=a3*10+k;
		f(n-1, (a[n-1]+o*10) - (i+j+k), i0||i>0, ji||j>i, kj||k>j, true);
	}
	return FF[ff]=t, F[ff]=Max;
}

vector<long> h(long x) {
	if (x==0) return vector<long>();
	long P=1; while (x%2==0) { x/=2; P*=2; }
	long Q=1; while (Q*3<=x) Q*=3;
	vector<long> T = h(x-Q);
	for (long &o: T) o*=P;
	T.push_back(Q*P);
	return T;
}

main() {
	cin >> t;
	do {
		long x; cin >> x;
		
		n=0;
		do {
			a[n++]=x%10;
		} while (x/=10);
		
		if (f(n, 0, 0, 0, 0) < 0)
			cout << -1 << endl;
		else {
			f(n, 0, 0, 0, 0, true);
			//cout << a1 << " " << a2 << " " << a3 << endl;
			vector<long> H1=h(a1), H2=h(a2), H3=h(a3);
			cout << H1.size() << " " << H2.size() << " " << H3.size();
			for (long o: H1) cout << " " << o;
			for (long o: H2) cout << " " << o;
			for (long o: H3) cout << " " << o;
			cout << endl;
		}
		a1=a2=a3=0;
	} while (--t);
}
