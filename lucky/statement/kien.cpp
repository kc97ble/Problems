#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int k;
char s[6];
vector<int> F[6][6];

const vector<int> &f(int L, int R) {
	if (F[L][R].size()) return F[L][R];
	int Whole = 0;
	for (int i=L; i<=R; i++)
	Whole = Whole * 10 + (s[i]-'0');
	F[L][R].push_back(Whole);
	
	for (int i=L; i<R; i++) {
		const vector<int> &Left = f(L, i);
		const vector<int> &Right = f(i+1, R);
		for (int il=0; il<Left.size(); il++)
		for (int ir=0; ir<Right.size(); ir++) {
			int xl=Left[il], xr=Right[ir];
			#define try(x) F[L][R].push_back(x)
			try(xl+xr), try(xl-xr), try(xl*xr), try(xr-xl);
			if (xr!=0 && xl%xr==0) try(xl/xr);
		}
	}
	#define all(a) a.begin(), a.end()
	sort(all(F[L][R]));
	F[L][R].erase(unique(all(F[L][R])), F[L][R].end());
	return F[L][R];
}

main() {
	freopen("lucky.inp", "r", stdin)&&
	freopen("lucky.out", "w", stdout);
	
	scanf("%d%s", &k, s);
	const vector<int> &List = f(0, 5);
	bool ok = count(List.begin(), List.end(), k);
	cout << (ok ? "YES" : "NO") << endl;
	//for (int i=0; i<List.size(); i++)
	//printf(i&15 ? "%d " : "%d\n", List[i]);
	//cout << List.size() << endl;
}
