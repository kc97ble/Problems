#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 4000006
int n, F[N]; char a[N];
map<string, int> Map;

int kmp(char a[]){
	F[0]=-1;
	for (int i=1; a[i]; i++)
	for (int k=F[i-1]; F[i]=k+1; k=F[k])
	if (a[k+1]==a[i]) break;
	return F[strlen(a+1)];
}

main(){
	scanf("%d", &n);
	long Sum = 0;
	f1(i,n) {
		scanf("%*d%s", a+1);
		strncat(a+1, a+1, strlen(a+1));
		string aa (a+kmp(a)+1);
		Sum += (Map[aa]++);
	}
	cout << Sum*2+n << endl;
}
