#include <stdio.h>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int n, m;
set<int> Set;
map<int, bool> Color;
priority_queue<ii> qu;

int h(int x)
	{ auto it = Set.lower_bound(x); return *it - *prev(it); }
void update(set<int> :: iterator it) 
	{ qu.emplace(*it - *prev(it), *it); }

main() {
	scanf("%d%d", &n, &m);
	
	Set.insert(0);
	Set.insert(n);
	qu.push(ii(n, n));
	
	for (int i=1; i<=m; i++) {
		int x; scanf("%d", &x);
		Set.insert(x);
		Set.insert(x-1);
		Color[x] ^= 1;
		if (x<n && Color[x+1]==Color[x]) Set.erase(x);
		if (x>1 && Color[x-1]==Color[x]) Set.erase(x-1);
		
		auto it = Set.lower_bound(x);
		update(it);
		if (next(it)!=Set.end()) update(next(it));
		if (it!=Set.begin()) update(prev(it));
		
		ii w = qu.top();
		while (h(w.second) != w.first) 
		{ qu.pop(); w=qu.top(); }
		printf("%d\n", w.first);
	}
	
}

