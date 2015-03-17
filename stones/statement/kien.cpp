#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 200005;
int m, n;
priority_queue<int> qu[N];
priority_queue<ii> Best;

inline void changed(int u) {
	if (qu[u].size()) 
	Best.push(ii(-qu[u].top(), u));
}

main() {
	//freopen("STONES.INP", "r", stdin);
	//freopen("STONES.OUT", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++) {
		int c; scanf("%d", &c);
		if (c==1) {
			int x, y; scanf("%d%d", &x, &y);
			qu[x].push(-y); changed(x);
		} else {
			int u, x;
			do {
				ii Pop = Best.top(); Best.pop();
				u=Pop.Y, x=Pop.X;
			} while (qu[u].empty() || qu[u].top()!=-x);
			printf("%d\n", x);
			qu[u].pop(); changed(u);
		}
	}	
}
