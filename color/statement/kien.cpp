#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 220
#define N0 100005
const int M = 1000000009;
long Fact[N0], IFact[N0];
int A, B, C, D;

int F[N+N][N][N];
bool FF[N+N][N][N];
#define EAB E][A][B

long power(long a, long k, long M) {
	long P = 1LL;
	while (k) {
		if (k&1) P=P*a%M;
		a=a*a%M; k/=2;
	}
	return P;
}

long choose(int n, int k)
	{ return Fact[n] * IFact[k] % M * IFact[n-k] % M; }

long f(int E, int A, int B){
	if (E==0 || A<0 || B<0) return A==0 && B==0;
	if (FF[EAB]++) return F[EAB];
	long Sum = 0LL;
	Sum += f(E, A-1, B-1);
	Sum += f(E-1, A-1, B);
	Sum += f(E-1, A, B-1);
	Sum += f(E-1, A-1, B-1)*2;
	//printf("f(%d, %d, %d) = %lld\n", E, A, B, Sum);
	return F[EAB] = Sum % M;
}

int GG[N+N];
bool G[N+N];

long g(int E){
	if (G[E]++) return GG[E];
	long Sum = 0LL;
	for (int i=0; E+i<=A+B && E+i<=C+D+1; i++)
	Sum += f(E+i, A, B) * choose(C+D+1-E, i) % M;
	//printf("g(%d) = %lld\n", E, Sum);
	return GG[E] = Sum % M;
}

main(){
	Fact[0]=1; f1(i,N0-1) Fact[i]=Fact[i-1]*i%M;
	f0(i,N0-1) IFact[i] = power(Fact[i], M-2, M);
        f0(i,N+N) f0(j,N) f0(k,N) f(i, j, k);

	int ABCD[4];
	f0(i,4) cin >> ABCD[i];
	sort(ABCD, ABCD+4);
	A=ABCD[0], B=ABCD[1], C=ABCD[2], D=ABCD[3];

        if (C==0) {
           cout << (D==1 ? 1 : 0) << endl;
           return 0;
        }

	long Sum = 0LL;
	for (int c=1; c<=C; c++)
	for (int d=c-1; d<=c+1; d++)
	if (d>=1 && d<=D && C-c+D-d<=A+B)
	Sum += g(C-c+D-d) * choose(C-1, c-1) % M
		* choose(D-1, d-1) % M * (c==d ? 2 : 1);

	cout << Sum % M << endl;
}
