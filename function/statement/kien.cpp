#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 2000006;
int n, a[N], d[N], p[N], b[N];
long S;

int bfs(int S) {
	queue<int> qu;
	qu.push(S); d[S]=1; p[S]=0;
	
	while (qu.size()) {
		int u=qu.front(); qu.pop();
		if (u==0) return d[0]-1;
		for (int i=1; i<=n; i++) {
			int v1=u-a[i], v2=u+a[i];
			if (v1>=0 && v1<N && d[v1]==0)
			{ d[v1]=d[u]+1; p[v1]=+i; qu.push(v1); }
			if (v2>=0 && v2<N && d[v2]==0)
			{ d[v2]=d[u]+1; p[v2]=-i; qu.push(v2); }
		}
	}
	return -1;
}

long ceil(long x, long y) 
	{ return x/y + !!(x%y); }

main() {
	cin >> S >> n;
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	long Last = 0;
	if (S>1000000) {
		Last = ceil(S-1000000, a[n]);
		S -= Last*a[n];
	}
	
	cerr << bfs(S) << endl;
	#define a(x) (x>0 ? a[x] : -a[-x])
	for (int i=0; p[i]; i+=a(p[i]))
		if (p[i]>0) b[p[i]]++; 
		else b[-p[i]]--;
	for (int i=1; i<=n-1; i++)
		printf("%d ", b[i]);
	cout << b[n]+Last << endl;
}
