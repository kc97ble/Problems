#include <bits/stdc++.h>
using namespace std;

#define long long long
const int N = 100005, M = 1000000007;
int n, m;
long Inc[4*N], Sum[4*N];

struct node {
	int ll, rr, id;
	node(int L, int R, int X)
		{ ll=L, rr=R, id=X; access(); }
	node left()
		{ return node(ll, (ll+rr)/2, id*2); }
	node right()
		{ return node((ll+rr)/2+1, rr, id*2+1); }
	
	void access() {
		if (Inc[id]) {
			if (ll!=rr) Inc[id*2]=(Inc[id*2]+Inc[id])%M;
			if (ll!=rr) Inc[id*2+1]=(Inc[id*2+1]+Inc[id])%M;
			Sum[id]=(Sum[id]+Inc[id]*(rr-ll+1))%M;
			Inc[id]=0;
		}
	}
		
	int sum_range(int L, int R) {
		if (ll>R || L>rr || L>R) return 0;
		if (L<=ll && rr<=R) return Sum[id]%M;
		int Sum1 = left().sum_range(L, R);
		int Sum2 = right().sum_range(L, R);
		return (Sum1+Sum2)%M;
	}
	
	void inc_range(int L, int R, int x) {
		if (ll>R || L>rr || L>R) return;
		if (L<=ll && rr<=R) { Inc[id]=x; access(); return; }
		left().inc_range(L, R, x);
		right().inc_range(L, R, x);
		Sum[id]=(Sum[id*2]+Sum[id*2+1])%M;
	}
};

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		int x; scanf("%d", &x);
		node(1, n, 1).inc_range(i, i, x);
	}
	for (int i=1; i<=m; i++) {
		char s[4]; scanf("%s", s);
		if (s[2]=='T') { // set
			int u, x; scanf("%d%d", &u, &x);
			x -= node(1, n, 1).sum_range(u, u);
			node(1, n, 1).inc_range(u, u, x);
		} else if (s[2]=='C') { // inc
			int L, R, x; scanf("%d%d%d", &L, &R, &x);
			node(1, n, 1).inc_range(L, R, x);
		} else if (s[2]=='M') { // sum
			int L, R; scanf("%d%d", &L, &R);
			int Result = node(1, n, 1).sum_range(L, R);
			printf("%d\n", (Result%M+M)%M);
		}
	}
}
