#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

void enter(int p[], int n, int G) {
	int M; 
	cin >> M;
	
	int x[M];
	for (int i=0; i<M; i++)
	scanf("%d", &x[i]);
	
	int k=0;
	for (int i=0; i<n; i++) {
		p[i+1] = x[k];
		int s = (k+1)%M;
		x[k] = ((x[k]^x[s])+13) % G;
		k = s;
	}
}

const int N = 500005;
int n, C, p[N], b[N];
long F[N], G[N], s[N];

main() {
	cin >> n >> C;
	enter(p, n, 1001);
	enter(b, n, 10001);
	
	long SumP = 0;
	for (int i=1; i<=n; i++)
		{ SumP+=p[i]; p[i] *= 2; }
	for (int i=1; i<=n; i++)
		s[i] = s[i-1] + p[i];
	
	priority_queue<long> qu1, qu2;
	F[n+1]=0; G[n+1]=s[n];
	qu1.push(G[n+1]);
	
	for (int i=n; i>=0; i--) {
		if (i+C+1 <= n+1) qu2.push(G[i+C+1]);
		while (qu1.size() && qu2.size() && qu1.top()==qu2.top()) 
			{ qu1.pop(); qu2.pop(); }
		//printf("top[%d] = %d\n", i, qu1.top());
		F[i] = qu1.top() - s[i]; // F[i] = (F[j: i+1 .. i+C] + s[j-1]) - s[i];
		if (i+C <= n) F[i] = max(F[i], F[i+C] + (s[i+C] - s[i]) + b[i+C]);
		if (i!=0) {
			G[i] = F[i] + s[i-1];
			qu1.push(G[i]);
		}
	}
	//for (int i=0; i<=n+1; i++) printf("%d ", F[i]); printf("F[]\n");
	//for (int i=0; i<=n+1; i++) printf("%d ", G[i]); printf("G[]\n");
	cout << F[0]-SumP << endl;
}
