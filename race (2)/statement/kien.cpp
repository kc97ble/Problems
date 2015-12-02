#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, a[N], b[N], Score=0;

void decide(int x, int y) {
	//printf("%d %d\n", x, y);
	if (a[x]>b[y]) Score++;
	if (a[x]<b[y]) Score--;
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	for (int i=1; i<=n; i++) scanf("%d", &b[i]);
		
	multimap<int, int> MapA, MapB;
	for (int i=1; i<=n; i++) MapA.emplace(a[i], i);
	for (int i=1; i<=n; i++) MapB.emplace(b[i], i);
	
	for (auto it=MapA.begin(); it!=MapA.end(); ) {
		auto jt = MapB.lower_bound(it->first);
		if (jt==MapB.begin()) { it++; continue; } else jt--;
		decide(it->second, jt->second);
		MapA.erase(it++); MapB.erase(jt);
	}
	
	auto jt=MapB.end();
	for (auto it=MapA.begin(); it!=MapA.end(); it++)
	decide(it->second, (--jt)->second);
	cout << Score << endl;
}

