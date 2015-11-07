#include <bits/stdc++.h>
using namespace std;

#define long long long

void openfile(const char fmt[], int Index) {
	char fn[128];
	sprintf(fn, fmt, Index);
	fprintf(stderr, "%s\n", fn);
	freopen(fn, "w", stdout);
	//cin.ignore(1);
}

unsigned long rand32()
	{ return rand()<<16 | rand(); }
unsigned long rand64()
	{ return rand32()<<32 | rand32(); }
long bw(long a, long b) 
	{ return a+rand64()%(b-a+1); }

int t=0;

void gen1(int n) {
	openfile("%d.in", t++);
	int x=rand()%64, y=rand()%64;
	for (int i=0; i<6; i++) {
		if ((1<<i)&y) printf("?");
		else printf((1<<i)&x ? "(" : ")");
	}
	puts("");
}

void gen2(int n) {
	openfile("%d.in", t++);
	int l=0;
	for (int i=1; i<=n; i++)
	if ((rand()&3) && l) {
		printf(rand()&3 ? ")" : "?");
		l--;
	} else {
		printf(rand()&3 ? "(" : "?");
		l++;
	}
	puts("");
}
	
main() {
	#define loop(n) for (int i=1; i<=(n); i++)
	loop(50) gen1(6);
	loop(50) gen2(100);
	
}
