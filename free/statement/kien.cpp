#include <stdio.h>
#include <assert.h>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 10004;

struct trie {
	int n, a[N][128], Prev[N];
	bool Leaf[N];
	
	int create(int &x) 
		{ return x ? x : x=++n; }
	
	void insert(char s[]) {
		int u = 0;
		for (int i=0; s[i]; i++)
		u=create(a[u][s[i]]);
		Leaf[u]=true;
	}
	
	void bfs() {
		assert(n<N);
		queue<int> qu;
		qu.push(0); Prev[0]=-1;
		
		while (qu.size()) {
			int u=qu.front(); qu.pop();
			for (int i=0; i<128; i++)
			if (int v=a[u][i]) {
				qu.push(v);
				Prev[v] = next(Prev[u], i);
				Leaf[v] |= Leaf[Prev[v]];
			}
		}
	}
	
	int next(int u, char k) {
		for (int i=u; i!=-1; i=Prev[i])
		if (a[i][k]) return a[i][k];
		return 0;
	}
} Trie;

void init() {
	char s[123];
	long P = 1;
	for (int i=1; i<=18; i++) {
		sprintf(s, "%lld", P*=11);
		//cout << s << endl;
		Trie.insert(s);
	}
	Trie.bfs();
}

bool FF[123][N];
long F[123][N];

long f(int n, int u) {
	if (Trie.Leaf[u]) return 0;
	if (n==0) return 1;
	if (FF[n][u]++) return F[n][u];
	long Sum = 0;
	for (int k='0'; k<='9'; k++)
	Sum += f(n-1, Trie.next(u, k));
	return F[n][u] = Sum;
}

main() {
	init();
	long x; cin >> x; x++;
	int u=0; bool One=false;
	for (int n=20; n>=1; n--) {
		for (int k='0'; k<='9'; k++) {
			long fx = f(n-1, Trie.next(u, k));
			if (fx >= x) { 
				u=Trie.next(u, k); 
				if (One |= k!='0')
				printf("%c", k);
				break; 
			} else 
				x -= fx;
		}
	}
	puts("");
}

