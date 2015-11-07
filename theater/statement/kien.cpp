#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long
const int N = 100005, M = 1000003;
int n, m, Result[N], b[N];
long H[N];
map<long, set<int> > Map;

main() {
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	Map[0].insert(i);

	for (int i=1; i<=m; i++) {
		vector<long> Changes;
		int p; scanf("%d", &p);
		//int p; printf("%d ", p=rand()%n+1);
		for (int j=1; j<=p; j++) {
			//printf("%d ", b[j]=rand()%n+1);
			scanf("%d", &b[j]);
			Changes.push_back(H[b[j]]);
			Map[H[b[j]]].erase(b[j]);
			H[b[j]] = H[b[j]] * M + i;
			Map[H[b[j]]].insert(b[j]);
			Changes.push_back(H[b[j]]);
		}
		#define unique(a) a.erase(unique(a.begin(), a.end()), a.end())
		sort(Changes.begin(), Changes.end()); unique(Changes);
		for (int j=0; j<=Changes.size(); j++)
		if (Map[Changes[j]].size()==1) {
			int u = *Map[Changes[j]].begin();
			if (Result[u]==0) Result[u]=i;
		}

		/*for (int j=1; j<=n; j++) if (Naive[j]==0)
		if (count(H+1, H+n+1, H[j])==1) Naive[j]=i;*/
	}
	for (int i=1; i<=n; i++)
	printf("%d ", Result[i]);
	puts("");
}
