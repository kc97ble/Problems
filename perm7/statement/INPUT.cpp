#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int n0[]={
	2, 
	3, 3,
	4, 4, 4,
	5, 5, 5, 5,
	6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 0};
int m0[]={
	1,
	2, 3,
	4, 5, 6,
	7, 8, 9, 10,
	11, 12, 13, 14, 15,
	16, 17, 18, 19, 20, 21,
	21, 21, 21, 21, 0};

void open_file(int t){
	char FileName[123];
	sprintf(FileName, "%d.in", t);
	freopen(FileName, "w", stdout);
	fprintf(stderr, "Openning file %s\n", FileName);
}

int n, m, a[10], b[10];

unsigned rand2()
	{ return rand()*rand()^rand(); }
int between(int x, int y)
	{ return rand2()%(y-x+1)+x; }

main(){
	for (int t=0; n=n0[t], m=m0[t]; t++){
		open_file(t);
		printf("%d %d\n", n, m);
		
		for (int i=1; i<=n; i++) a[i]=i;
		random_shuffle(a+1, a+n+1);
		for (int i=1; i<=n; i++)
			printf(i==n ? "%d\n" : "%d ", a[i]);
		
		for (int i=1; i<=n; i++) b[i]=i;
		random_shuffle(b+1, b+n+1);
		for (int i=1; i<=n; i++)
			printf(i==n ? "%d\n" : "%d ", b[i]);
		
		for (int i=1; i<=m; i++)
			printf("%d %d\n", between(1, n), between(1, n));
		fprintf(stderr, "%d bytes written.\n", ftell(stdout));
	}
}

