#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 2000006
int n, s[N];
bool np[N];

void eratos(){
	np[0]=np[1]=true;
	for (int i=2; i*i<N; i++) if (!np[i])
	for (int j=i*i; j<N; j+=i)
	np[j]=true;
	
	f1(i,N-1) s[i]=s[i-1]+(!np[i]);
}

main(){
	eratos();
	int T; scanf("%d", &T);
	while (T-->0) {
		scanf("%d", &n);
		long Sum = 0LL;
		f1(i,n) Sum += 1LL * (s[i+n]-s[i+(i==1)]) * (n-(s[i+n]-s[i])-(i!=1));
		cout << 1LL*n*(n-1)*(n-2)/6 - Sum/2 << endl;
	}
}
