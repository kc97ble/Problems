#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int m0[]={1, 2, 3, 5, 10, 20, 30, 40, 49, 0};
int n0[]={1, 2, 5, 10, 20, 50, 0};

void open_file(int t){
	char FileName[123];
	sprintf(FileName, "%d.in", t);
	freopen(FileName, "w", stdout);
	fprintf(stderr, "Openning file %s\n", FileName);
}

unsigned rand2()
	{ return rand()*rand()^rand(); }
int between(int x, int y)
	{ return rand2()%(y-x+1)+x; }
unsigned long rand3()
	{ return 1LL*rand2()*rand2() ^ rand2(); }
long bw3(long x, long y)
	{ return rand3()%(y-x+1)+x; }
long bw3r(long x, long y, int k) 
	{ while (k--) x=bw3(x, y); return x; }

main(){
	int t=0;
	for (int i=0; long m=m0[i]; i++)
	for (int j=0; long n=n0[j]; j++) {
		open_file(t++);
		cout << bw3r(1, 1LL<<m, m/3+1) << " " << bw3r(1, n, m/10+1) << endl;
		fprintf(stderr, "%d bytes written.\n", ftell(stdout));
	}
}
