#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
char a[17];
int c1, d1, c2, d2;
bool F[16][16][16][2][2];
bool FF[16][16][16][2][2];

bool f(int u, int c1, int c2, bool nz, bool gt, bool Tracing=false) {
	if (a[u]==0) return c1==0 && c2==0 && nz;
	#define THIS u][c1][c2][nz][gt
	if (!Tracing && FF[THIS]++) return F[THIS];
	bool Any=false; int d=-1;
	for (int i=0; i<=9; i++)
	if (gt || i>=a[u]-'0') {
		int D1=(d1!=0 || nz) && i==d1 && c1 ? c1-1 : c1;
		int D2=(d2!=0 || nz) && i==d2 && c2 ? c2-1 : c2;
		if (f(u+1, D1, D2, i!=0 || nz, gt || i>a[u]-'0'))
		{ d=i; Any=true; break; }
	}
	//printf("f(%d, %d, %d, %d, %d) = %d\n", u, c1, c2, nz+0, gt+0, Any+0);
	if (Tracing) {
		int i=d;
		if (nz || i!=0) printf("%d", i);
		int D1=(d1!=0 || nz) && i==d1 && c1 ? c1-1 : c1;
		int D2=(d2!=0 || nz) && i==d2 && c2 ? c2-1 : c2;
		f(u+1, D1, D2, i!=0 || nz, gt || i>a[u]-'0', true);
	}
	return F[THIS] = Any;
}

main(){
	long x; cin >> x;
	cin >> d1 >> c1;
	cin >> d2 >> c2;
	sprintf(a, "%016lld", x);
	f(0, c1, c2, false, false, true); cout << endl;
}
