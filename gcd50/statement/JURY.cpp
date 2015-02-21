#include <stdio.h>
#include <assert.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
int Primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,0};
int m, p[52], q[52];
bool d[1<<15];
long Max;

int encode(long x) {
	int Sum = 0;
	for (int i=0; int p=Primes[i]; i++)
	if (x%p==0) Sum |= (1<<i);
	//printf("encode(%lld) = %d\n", x, Sum);
	return Sum;
}

long decode(int x) {
	long P = 1;
	for (int i=0; int p=Primes[i]; i++)
	if (x & (1<<i)) P *= p;
	return P;
}

void bfs(int S) {
	queue<int> qu;
	qu.push(S); d[S]=true;
	
	while (qu.size()) {
		int u=qu.front(); qu.pop();
		Max = max(Max, decode(u));
		for (int i=1; i<=m; i++) {
			int v = (u & p[i]) | q[i];
			if (d[v]==0) { 
				//printf("%lld -> %lld\n", decode(u), decode(v)); 
				qu.push(v); d[v]=true;
			}
		}
	}
}

main(){
	cin >> Max >> m;
	int S=encode(Max);
	for (int i=1; i<=m; i++) { 
		long x, y; cin >> x >> y;
		p[i]=encode(x);
		q[i]=encode(y);
	}
	bfs(S);
	cout << Max << endl;	
}
