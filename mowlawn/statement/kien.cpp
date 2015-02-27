#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int n, k, a[N];
long F[N], G[N], s[N];

main() {
	scanf("%d%d", &n, &k); k++;
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		s[i] = s[i-1] + a[i];
	
	priority_queue<long> qu1, qu2;
	G[0]=0; qu1.push(G[0]);
	for (int i=1; i<=n+1; i++) {
		if (i-k-1 >= 0) qu2.push(G[i-k-1]);
		while (qu1.size() && qu2.size() && qu1.top()==qu2.top()) 
			{ qu1.pop(); qu2.pop(); }
		F[i] = qu1.top() + s[i-1];
		G[i] = F[i] - s[i]; qu1.push(G[i]);
		//printf("F[%d] = %d\n", i, F[i]);
	}
	cout << F[n+1] << endl;
}
