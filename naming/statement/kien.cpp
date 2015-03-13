#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const int oo = 0x3c3c3c3c;

#define N 102
int n; char a[N];
int F[N][N]; bool FF[N][N];
#define C ll][u

bool maximize(int &a, int b)
	{ if (a<b) a=b; else return false; return true; }

int f(int ll, int rr, int u, bool Tracing=false){
	if (u==n+1) return 0;
	if (!Tracing && FF[C]++) return F[C];
	int Max=-oo, d=0;
	for (int i=u; i<=n; i++){
		string A(a+ll, a+rr+1), B(a+u, a+i+1);
		if (A+B<=B+A)
		if (maximize(Max, f(u, i, i+1)+1)) d=i;
	}
	if (Tracing) { 
		int i=d;
		fprintf(stderr, "%.*s|", i-u+1, a+u);
		f(u, i, i+1, true);		
	}
	//printf("f(%d, %d, %.*s, %d) = %d\n", ll, rr, rr-ll+1, a+ll, u, Max);
	return F[C]=Max;
}

main(){
	scanf("%s", a+1); n=strlen(a+1);
	cout << f(1, 0, 1) << endl;
	f(1,0,1,1); cerr << endl;
}
