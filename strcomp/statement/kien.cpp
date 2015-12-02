#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long
typedef pair<int, long> hash_t;
#define X first
#define Y second

const int N = 300005;
int n, m;
char b[N];
hash_t Hash[4*N];
long M[N];

hash_t operator + (hash_t a, hash_t b) 
	{ return hash_t(a.X+b.X, a.Y*M[b.X]+b.Y); }

struct node {
	int ll, rr, id;
	node(int L, int X)
		{ ll=L, id=X; rr=ll+Hash[id].X-1; }
	node left()
		{ return node(ll, id*2); }
	node right()
		{ return node(ll+Hash[id*2].X, id*2+1); }
	
	void remove(int X) {
		if (ll>X || X>rr) return ;
		if (ll==rr) { Hash[id]=hash_t(0, 0); return ; }
		right().remove(X), left().remove(X);
		Hash[id] = Hash[id*2] + Hash[id*2+1];
	}
	
	hash_t hash_range(int L, int R) {
		if (ll>R || L>rr || L>R) return hash_t(0, 0);
		if (L<=ll && rr<=R) return Hash[id];
		return left().hash_range(L, R) + right().hash_range(L, R);
	}
	
	void init(char b[], int L, int R) {
		if (L==R) { Hash[id]=hash_t(1, b[ll]); return ; }
		left().init(b, L, (L+R)/2);
		right().init(b, (L+R)/2+1, R);
		Hash[id] = Hash[id*2] + Hash[id*2+1];
	}
};

main() {
	M[0]=1; M[1]=2309;
	for (int i=2; i<N; i++)
	M[i] = M[i-1] * M[1];
	
	scanf("%s", b+1);
	n=strlen(b+1);
	node(1, 1).init(b, 1, n);
	
	scanf("%d", &m);
	for (int i=1; i<=m; i++) {
		char c; int x, y, z;
		scanf(" %c%d", &c, &x);
		if (c=='-')
			node(1, 1).remove(x);
		else {
			scanf("%d%d", &y, &z);
			hash_t H1 = node(1, 1).hash_range(x, x+z-1);
			hash_t H2 = node(1, 1).hash_range(y, y+z-1);
			puts(H1==H2 ? "YES" : "NO");
		}
	}
}

