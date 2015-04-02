#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n, Edges=0, Success=0;
char a[123][123], b[123][123];
int d1[123][123];
bool Visited[123][123];
bool IsVowel[128];

int rx[]={-1,0,1,0};
int ry[]={0,-1,0,1};
char rc[]="|-|-";

bool visit(int x, int y) {
	if (!Visited[x][y]) Visited[x][y]=true; else return false;
	//printf("visit(%d, %d)\n", x, y);
	bool Result = IsVowel[b[x][y]];
	if (Result) Success++;
	for (int i=0; i<4; i++) {
		int x1=x+rx[i], y1=y+ry[i];
		int x2=x1+rx[i], y2=y1+ry[i];
		//printf("%d %d %d %d %c %c\n", x1, x2, y1, y2, a[x1][y1], rc[i]);
		if (a[x1][y1]==rc[i] && visit(x2, y2)) { 
			Edges++; Result=true;
			d1[x][y] = max(d1[x][y], d1[x2][y2]+1);
		}
	}
	return Result;
}

main() {
	IsVowel['u']=IsVowel['e']=IsVowel['o']=true;
	IsVowel['a']=IsVowel['i']=IsVowel['y']=true;
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
		scanf("%s", b[i]+1);
	for (int i=1; i<=m; i++)
		scanf("%s", a[i]+1);

	int Result=0, Vowels=0;
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++) {
		if (a[i][j]=='.') {
			visit(i, j);
			Result = 2*Edges-d1[i][j];
		}
		if (IsVowel[b[i][j]])
			Vowels++;
	}
	//cout << Vowels << " " << Success << endl;
	if (Vowels!=Success)
		cout << "NIE" << endl;
	else
		cout << Result << endl;
}
