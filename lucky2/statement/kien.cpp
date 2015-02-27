#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define all(a) a.begin(), a.end()
typedef pair<long, long> llll;
#define X first
#define Y second

int a[123], n;

void btrk(int a[], int l, vector<llll> &T, long X, long Y) {
	if (l==0) { T.push_back(llll(X, Y)); return; }
	btrk(a+1, l-1, T, X, Y*2);
	btrk(a+1, l-1, T, X+a[1], Y*2+1);
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	
	int ll=n/2, rr=n-ll; // rr>0
	vector<llll> L; btrk(a, ll, L, 0, 0); sort(all(L));
	vector<llll> R; btrk(a+ll, rr, R, 0, 0); sort(all(R));
	
	vector<long> C;
	C.push_back(4);
	for (int i=2; i<=10; i++)
	C.push_back(C.back()*10+4);
	C.push_back(7);
	for (int i=2; i<=10; i++)
	C.push_back(C.back()*10+7);
	
	llll Max(0LL, 0ll);
	for (int k=0; k<C.size(); k++) {
		int j = R.size()-1;
		for (int i=0; i<L.size(); i++) {
			while (j>=0 && L[i].X+R[j].X>C[k]) j--;
			if (j==-1) break;
			if (L[i].X+R[j].X == C[k])
			Max = max(Max, llll(L[i].X+R[j].X, (L[i].Y<<rr) | R[j].Y));
		}
	}
	if (Max.X==0LL) return 0;
	cerr << Max.X << endl;
	for (int i=1; i<=n; i++)
	if (Max.Y & (1LL<<n-i))
	cout << a[i] << " ";
}
