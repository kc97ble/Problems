#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

short a[10][10];
char A[20], B[20], C[20];
short F[10][10][19][19][2][2];
bool FF[10][10][19][19][2][2];
#define This Start][Decision][u0][u][Less][More

short f(short Start, short Decision, int u0, int u, bool Less, bool More){
	if (u==19) return a[Start][Decision];
	if (FF[This]++) return F[This];
	short Result = Start;
	f0(k,10)
	if (Less || k<=B[u]-'0')
	if (More || k>=A[u]-'0')
	Result = f(Result, u0==u ? k : Decision, u0, u+1, 
		Less || k<B[u]-'0', More || k>A[u]-'0');
	return F[This]=Result;
}

main(){
	f0(i,10) f0(j,10) scanf("%hd", &a[i][j]);
	long A0, B0; cin >> A0 >> B0;
	sprintf(C, "%019lld", A0);
	sprintf(A, "%019lld", A0+1);
	sprintf(B, "%019lld", B0);
	string s = "";
	f0(i,19) {
		short Current = f(C[i]-'0', 0, i, 0, false, false);
		if (s.size() || Current) s += Current+'0';
	}
	cout << (s.size() ? s : string("0")) << endl;
}
