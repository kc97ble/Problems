#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int x0, y0, z0;
int x, y, z;
vector<int> P, Q;

void pour(int &p, int &q) {
	//printf("pour(%d, %d)\n", p, q);
	P.push_back(p); Q.push_back(q);
	p-=q; q+=q;
	//printf("-> %d, %d, %d\n", x, y, z);
}

main(){
	cin >> x0 >> y0 >> z0;
	x=x0, y=y0, z=z0;
	while (x && y && z) {
		int ox=x, oy=y, oz=z;
		x=max(ox, max(oy, oz));
		z=min(ox, min(oy, oz));
		y=ox+oy+oz-x-z;

		int q = y/z;
		for (int i=1; i<=q; i<<=1) {
			if (i&q) pour(y, z);
			else pour(x, z);
		}
	}
	cout << P.size() << endl;

	for (int i=0; i<P.size(); i++) {
		int p = (x0==P[i] ? 1 : (y0==P[i] ? 2 : 3));
		int q = (z0==Q[i] ? 3 : (y0==Q[i] ? 2 : 1));
		printf("%d %d\n", p, q);
		int &x = (p==1 ? x0 : (p==2 ? y0 : z0));
		int &y = (q==1 ? x0 : (q==2 ? y0 : z0));
		if (x<y) return -1;
		x-=y; y+=y;
	}
	if (x0 && y0 && z0) return -1;
}

