#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef pair<long, long> llll;
#define X first
#define Y second

const int N = 200005;
long W, H;
int n, l[N];
long x[N], y[N], R[N];
map<long, long> Map;

main() {
	cin >> W >> H >> n; W*=2; H*=2;
	Map.emplace(W, 0);
	Map.emplace(0, 0);
	for (int i=1; i<=n; i++) {
		double xx, yy; scanf("%lf%lf", &xx, &yy);
		x[i]=xx*2+0.5; y[i]=yy*2+0.5;
	}
	for (int i=1; i<=n; i++) l[i]=i;
	sort(l+1, l+n+1, [](int p, int q) { return y[p]<y[q]; } );
	
	for (int j=1; j<=n; j++) { int i=l[j];
		R[i] = y[i] - Map.lower_bound(x[i])->Y;
		auto it1 = Map.lower_bound(x[i]-R[i]);
		Map[x[i]-R[i]] = it1->Y;
		it1 = Map.lower_bound(x[i]-R[i]);
		
		auto it2 = Map.lower_bound(x[i]+R[i]);
		Map[x[i]+R[i]] = y[i]+R[i];
		it2 = Map.lower_bound(x[i]+R[i]);
		
		Map.erase(next(it1), it2);
	}
	for (int i=1; i<=n; i++)
	cout << R[i] << endl;
}

