#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 1000006
int n, F[N], G[N]; char a[N];

void kmp(char a[], int F[], int G[]){
	F[0]=-1;
	for (int i=1; a[i]; i++)
	for (int k=F[i-1]; F[i]=k+1; k=F[k])
	if (a[k+1]==a[i]) break;
	
	for (int i=1; a[i]; i++)
	G[i]=(F[i] ? G[F[i]] : i);
}

main(){
	long Sum = 0;
	scanf("%d%s", &n, a+1);
	kmp(a, F, G);
	f1(i,n) Sum += i-G[i];
	cout << Sum << endl;
}
