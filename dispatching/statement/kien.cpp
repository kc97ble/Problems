#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 100005;
int n, M, B[N], C[N], L[N];
vector<int> a[N];

struct worker {
	priority_queue<int> *qu;
	long Sum;
	worker()
		{ Sum=0; qu=new priority_queue<int>(); }
	void push(int x) {
		qu->push(x); Sum+=x;
		if (Sum>M) { Sum-=qu->top(); qu->pop(); }
	}
} Worker[N];

bool by_size(int x, int y)
	{ return Worker[x].qu->size() > Worker[y].qu->size(); }

main() {
	scanf("%d%d", &n, &M);
	for (int i=1; i<=n; i++) {
		scanf("%d%d%d", &B[i], &C[i], &L[i]);
		a[B[i]].push_back(i);
	}
	for (int i=1; i<=n; i++)
		a[i].push_back(0);
	long Max = 0LL;
	for (int u=n; u>=1; u--) {
		sort(a[u].begin(), --a[u].end(), by_size);
		for (int i=0; int v=a[u][i]; i++)
		if (i==0) 
			Worker[u] = Worker[v];
		else {
			priority_queue<int> *qu = Worker[v].qu;
			while (qu->size()) {
				Worker[u].push(qu->top());
				qu->pop();
			}
		}
		Worker[u].push(C[u]);
		Max = max(Max, 1LL * Worker[u].qu->size() * L[u]);
	}
	cout << Max << endl;
}
