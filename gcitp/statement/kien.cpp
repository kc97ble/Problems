#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define all(a) a.begin(), a.end()
const int N = 5003;
int n, a[N], b[N], Where[N];
long M[N]; //

struct superset {
	long Hash; bool b[602];
	void insert(int u) 
		{ if (b[u]++) return; Hash+=M[u]; }
	void clear()
		{ Hash=0; memset(b, 0, sizeof b); }
} Set; //

void solve(int a[], int L, int R, map<long, int> &Map) {
	Set.clear();
	Set.insert(a[L]);
	for (int i=L+1; i<=R; i++) {
		Set.insert(a[i]);
		Map[Set.Hash]++;
	}
}

main() {
	M[0]=2309; M[1]=2309; for (int i=2; i<N; i++) M[i]=M[i-1]*M[1];
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	
	if (n>=301) {
		long Sum = 0;
		for (int i=1; i<=n; i++)
			Where[b[i]] = i;
		for (int L=1; L<=n; L++) {
			int Min=n, Max=1;
			for (int R=L; R<=n; R++) {
				Min = min(Min, Where[a[R]]);
				Max = max(Max, Where[a[R]]);
				if (Max-Min+1 == R-L+1)
				Sum++;
			}
		}
		cout << Sum-n << endl;
	} else {
		vector<int> List(a+1, a+n+1);
		List.insert(List.end(), b+1, b+n+1);
		sort(List.begin(), List.end());
		
		for (int i=1; i<=n; i++)
			a[i] = lower_bound(all(List), a[i]) - List.begin() + 1;
		for (int i=1; i<=n; i++)
			b[i] = lower_bound(all(List), b[i]) - List.begin() + 1;
		
		map<long, int> Map1, Map2;
		for (int i=1; i<=n; i++)
			solve(a, i, n, Map1);
		for (int i=1; i<=n; i++)
			solve(b, i, n, Map2);
		auto it = Map1.begin();
		auto jt = Map2.begin();
		
		long Sum = 0;
		while (it!=Map1.end() && jt!=Map2.end()) {
			if (it->first == jt->first) {
				Sum += it->second * jt->second;
				it++, jt++;
			} else 
				it->first < jt->first ? it++ : jt++;
		}
		cout << Sum << endl;
	}
}

