#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 81

bool Visited[N][N][N];

void visit(int x, int y, int z){
	if (x<0 || y<0 || z<0) return ;
	if (x>=N || y>=N || z>=N) return;
	if (Visited[x][y][z]++) return ;
	visit(x+1,y-1,z-1);
	visit(x-1,y+1,z-1);
	visit(x-1,y-1,z+1);
	visit(x-1,y+1,z+1);
	visit(x+1,y-1,z+1);
	visit(x+1,y+1,z-1);
}

void extract(char a[], int &x, int &y, int &z) {
	x=y=z=0;
	for (int i=0; a[i]; i++) if (a[i]=='*')
	(i%3==0 ? x : i%3==1 ? y : z) ++;
}

int n, Count=0;
char a[N];

main(){
	scanf("%s", a);
	int A0, A1, A2;
	extract(a, A0, A1, A2);
	visit(A0, A1, A2);
	
	scanf("%d", &n);
	f1(i,n) {
		scanf("%s", a);
		int A0, A1, A2;
		extract(a, A0, A1, A2);
		if (Visited[A0][A1][A2])
		Count++;
	}
	cout << Count << endl;
}
