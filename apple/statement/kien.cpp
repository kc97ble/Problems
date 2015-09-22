#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2003;
bool FF[N][N];
vector<int> List;

void dfs(int n, int k) {
	if (FF[n][k]++) 
		return ;
	if (k==0) 
		return List.push_back(n);
	if (n&1)
		dfs(n-1, k-1);
	else {
		dfs(n/2, k-1);
		if (n) dfs(n-1, k-1);
	}
}

main() {
	freopen("apple.inp", "r", stdin) &&
	freopen("apple.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	dfs(2*n, k);
	sort(List.begin(), List.end());
	List.erase(unique(List.begin(), List.end()), List.end());
	cout << List.size() << endl;
	for (int i=0; i<List.size(); i++)
	printf(List[i]&1 ? "%d.5 " : "%d.0 ", List[i]/2);
	puts("");
}
