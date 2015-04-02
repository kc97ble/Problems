#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define long long long
#define for_each(it, a) for (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
#define index_of(x, a) (lower_bound(a.begin(), a.end(), x) - a.begin())
#define all(a) a.begin(), a.end()
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#define X first
#define Y second

const int N = 6003;
vector<int> xs, ys;
vector<iii> e;
int s[N][N];

void inc_range_1(int x, int y, int u, int v, int k) {
	#define push_iii(x, y, k) push_back(iii(ii(x, y), k))
	e.push_iii(x, y, k);
	e.push_iii(x, v+1, -k);
	e.push_iii(u+1, y, -k);
	e.push_iii(u+1, v+1, k);
}

main() {
	int k; scanf("%*d%*d%d", &k);
	for (int i=1; i<=k; i++) {
		char c; int x, y, R;
		scanf(" %c%d%d%d", &c, &x, &y, &R);
		inc_range_1(x-y-R, x+y-R, x-y+R, x+y+R, c=='W' ? +1 : -1);
	} // done e
	for_each(it, e) {
		xs.push_back(it->X.X);
		ys.push_back(it->X.Y);
	}
	sort(all(xs)); xs.erase(unique(all(xs)), xs.end()); // done xs
	sort(all(ys)); ys.erase(unique(all(ys)), ys.end()); // done ys
	
	for_each(it, e) {
		int x = index_of(it->X.X, xs);
		int y = index_of(it->X.Y, ys);
		s[x][y] += it->Y;
	}
	for (int i=0; i<xs.size(); i++)
	for (int j=0; j<ys.size(); j++) {
		s[i][j] += (i==0 ? 0 : s[i-1][j]);
		s[i][j] += (j==0 ? 0 : s[i][j-1]);
		s[i][j] -= (i&&j ? s[i-1][j-1] : 0);
	}
	
	long A=0, B=0;
	for (int i=0; i<xs.size(); i++)
	for (int j=0; j<ys.size(); j++)
	if (s[i][j]) {
		long W = xs[i+1]-xs[i];
		long H = ys[j+1]-ys[j];
		long S=W*H/2;
		if ((W&1) && (H&1))
		if ((xs[i]&1) == (ys[j]&1)) 
		S++;
		
		if (s[i][j] < 0) A += S;
		if (s[i][j] > 0) B += S;
	}
	cout << B << " " << A << endl;
}
