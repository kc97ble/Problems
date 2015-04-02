#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 502;
int L[N], R[N];
string String[N];
bool IsConst[N];
char a[2003];

int t;
int F[N][2003];
int FF[N][2003]; //

int f(int u, int x) {
	if (FF[u][x]==t) return F[u][x];
	int ox = x;
	if (IsConst[u]) {
		const char* s = String[u].c_str();
		for (int i=0; char c=s[i]; i++)
		if (a[x]==c) x++;
	} else {
		x=f(L[u], x);
		x=f(R[u], x);
	}
	return FF[u][ox]=t, F[u][ox]=x;
}

main() {
	ios :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	do {
		int n; cin >> n;
		map<string, int> Map;
		for (int i=1; i<=n; i++) {
			string xx, yy, zz;
			cin >> xx; cin.ignore(3);
			int &x = Map[xx]; if (x==0) x=Map.size();
			cin >> yy;
			if (IsConst[x] = islower(yy[0])) {
				String[x]=yy;
			} else {
				cin.ignore(3); cin >> zz;
				int &y = Map[yy]; if (y==0) y=Map.size();
				int &z = Map[zz]; if (z==0) z=Map.size();
				L[x]=y, R[x]=z;
			}
		}
		string ss; cin >> ss >> a;
		cout << (a[f(Map[ss], 0)]==0 ? "YES" : "NO") << endl;
	} while (--t);
}
