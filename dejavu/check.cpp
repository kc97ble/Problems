#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
pair<int, int> a[N];

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf("%d%d", &a[i].first, &a[i].second);
	
	sort(a+1, a+n+1);
	assert(unique(a+1, a+n+1)==a+n+1);
	cout << "OK" << endl;
}
