#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int oo = 0x3c3c3c3c;
const int N = 30;
int m, n;
char a[N][N];

int FF[N][N][1<<10][2];
bool F[N][N][1<<10][2];

int f(int x, int y, int Cur, int Next) {
	if (x==m+1) return Cur==0 ? 0 : -oo;
	if (y==n+1) return f(x+1, 1, Next, 0);
	#define LEFT ((1<<y-1)-1)
	#define THIS x][y][Next&LEFT | Cur&~LEFT][!!((1<<y-1)&&Next)
	if (F[THIS]++) return FF[THIS];
	if (a[x][y]=='1' || (1<<y-1)&Cur)
		return FF[THIS] = f(x, y+1, Cur, Next);
	int Max = f(x, y+1, Cur, Next);
	if (a[x][y]=='.' && a[x+1][y+1]=='.')
	if (a[x+1][y]=='.' && a[x][y+1]=='.')
	if ((Cur & (3<<y-1))==0)
	if ((Next & (3<<y-1))==0)
	Max = max(Max, f(x, y+1, Cur | (3<<y-1), Next | (3<<y-1)) + 1);
	return FF[THIS] = Max;
}

main() {
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
		scanf("%s", a[i]+1);
	for (int i=1; i<=max(m, n)+1; i++)
		for (int j=1; j<i; j++)
		swap(a[i][j], a[j][i]);
	swap(m, n);
	cout << f(1, 1, 0, 0)*12 + m*n << endl;
}
