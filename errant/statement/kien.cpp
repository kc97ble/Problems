#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int rx[]={-2, -2, -1, -1, 1, 1, 2, 2};
int ry[]={-1, 1, -2, 2, -2, 2, -1, 1};
bool F[2][8003], FF[2][8003];

bool f(int x, int y) {
	x=abs(x), y=abs(y);
	if (x!=0 && y!=0 && x!=y) return true;
	if (FF[x==y][x|y]++) return F[x==y][x|y];
	bool All=true;
	f0(k,8) {
		int x1=x, y1=y, x2=x+rx[k], y2=y+ry[k];
		while (x2*x2+y2*y2 < x1*x1+y1*y1) {
			All &= f(x2, y2);
			x1=x2; x2+=rx[k];
			y1=y2; y2+=ry[k];
		}
	}
	//printf("f(%d, %d) = %d\n", x, y, !All);
	return F[x==y][x|y] = !All;
}

int n, x[100], y[100];
char z[100];

main(){
	scanf("%d", &n);
	f1(i,n) scanf("%d", &x[i]);
	f1(i,n) scanf("%d", &y[i]);
	f1(i,n) z[i]=(f(x[i], y[i]) ? 'W' : 'B');
	cout << z+1 << endl;
}
