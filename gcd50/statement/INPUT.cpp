#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int n0[]={
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
	31, 32, 33, 34, 35, 36, 37, 38, 38, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
	0};

void open_file(int t){
	char FileName[123];
	sprintf(FileName, "%d.in", t);
	freopen(FileName, "w", stdout);
	fprintf(stderr, "Openning file %s\n", FileName);
}

int n;
int Primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,0};

unsigned rand2()
	{ return rand()*rand()^rand(); }
int between(int x, int y)
	{ return rand2()%(y-x+1)+x; }

long decode(int x) {
	long P = 1;
	for (int i=0; int p=Primes[i]; i++)
	if (x & (1<<i)) P *= p;
	return P;
}

long f() {
	int y = min(n, 15);
	int x = rand2() & ((1<<y)-1);
	return decode(x);
}

main(){
	for (int t=0; n=n0[t]; t++){
		//cin.ignore(1);
		open_file(t);
		cout << f() << " " << n << endl;
		for (int i=1; i<=n; i++)
		cout << f() << " " << f() << endl;
		fprintf(stderr, "%d bytes written.\n", ftell(stdout));
	}
}

