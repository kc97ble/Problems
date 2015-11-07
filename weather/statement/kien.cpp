#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, b[370][20];
int F[370][4][4][7][7][7][7], t; //
#define C u][x-1][y-1][p1][p4][p13][p16

inline bool party(int x, int y, int u) 
	{ return b[u][(x-1)*4+y]; }

bool f(int u, int x, int y, int p1, int p4, int p13, int p16, int Phase=0) {
	if (Phase==0) {
		if (u==n+1) return true;
		if (x!=1 || y!=1) p1++; else p1=0;
		if (x!=1 || y!=3) p4++; else p4=0;
		if (x!=3 || y!=1) p13++; else p13=0;
		if (x!=3 || y!=3) p16++; else p16=0;
		if (party(x, y, u) || party(x+1, y+1, u)) return false;
		if (party(x+1, y, u) || party(x, y+1, u)) return false; 
		if (p1>=7 || p4>=7 || p13>=7 || p16>=7) return false;
		Phase=1;
	}
	
	if (F[C]!=t) F[C]=t; else return false;
	bool Any = false;
	for (int i=1; i<=3; i++) {
		Any = Any || f(u+1, i, y, p1, p4, p13, p16);
		Any = Any || f(u+1, x, i, p1, p4, p13, p16);
	}
	return Any;
}

main() {
	while (++t) {
		scanf("%d", &n);
		if (n==0) return 0;
		for (int i=1; i<=n; i++)
		for (int j=1; j<=16; j++)
		scanf("%d", &b[i][j]);
		
		cout << f(1, 2, 2, 0, 0, 0, 0) << endl;
	}
}

