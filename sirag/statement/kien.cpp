#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100005
int n, L, G[N], F[N][30]; //
char a[N];
#define f(i, k) (i<0 ? F[N-1][29] : F[i][k])

main(){
	freopen("sirag.in", "r", stdin);
	freopen("sirag.out", "w", stdout);
	
	int t; scanf("%d", &t);
	while (t-->0) {
		scanf("%d%d%s", &n, &L, a+1);// n=strlen(a+1);
		f1(i,n) if (a[i]=='*') a[i]=27; else a[i]-=96;
		
		f1(i,n) {
			if (a[i]==27) {
				f1(k,26) f(i, k) = 1 + f(i-L, k);
				G[i] = *max_element(F[i]+1, F[i]+26+1);
			} else
				G[i] = f(i, a[i]) = 1 + f(i-L, a[i]);
		}
		
		priority_queue<int> qu, qu0;
		f1(i,L-1) qu.push(-G[i]);
		
		int Max = 0;
		for (int i=L; i<=n; i++) {
			if (i-L>=1) qu0.push(-G[i-L]);
			qu.push(-G[i]);
			while (qu0.size() && qu0.top()==qu.top()) { qu0.pop(); qu.pop(); }
			Max = max(Max, -qu.top());
		}
		cout << Max*L << endl;
		
		f1(i,n) memset(F[i], 0, sizeof F[i]);
	}
}
