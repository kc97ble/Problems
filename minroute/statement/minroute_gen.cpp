#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

int nn[]={5,10,20,50,1e4,2e4,5e4,6e4,8e4,1e5,0};

void open_file(int t){
	char FileName[123];
	sprintf(FileName, "%d.in", t);
	freopen(FileName, "w", stdout);
	fprintf(stderr, "Openning file %s\n", FileName);
}

unsigned rand2()
	{ return rand()*rand()^rand(); }
int bw(int x, int y)
	{ return rand2()%(y-x+1)+x; }

#define N 100005
int n, p[N], l[N];

void visit(int u, int ll, int rr) {
	if (ll>rr) return;
	int k = bw(ll, bw(ll, bw(ll, rr)));
	p[k]=u;
	visit(k, k+1, rr);
	visit(u, ll, k-1);
}

main(){
	for (int t=0; n=nn[t]; t++) {
		open_file(t);
		printf("%d\n", n);
		f1(i,n) l[i]=i;
		random_shuffle(l+2, l+n+1);
		visit(1, 2, n);
		for (int i=2; i<=n; i++)
		printf("%d %d %d\n", l[i], l[p[i]], bw(1,bw(1,min(n,1000))));
		fprintf(stderr, "%d bytes written.\n", ftell(stdout));
		//cin.ignore(1);
	}
}
