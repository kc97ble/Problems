#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int N = 100005;
int n, b[N];
char a[N];
int Count[128]; //
int dx, dy;
set<ii> Tried;

vector<int> current(int k) {
	vector<int> T; T.reserve(k-1);
	for (int i=2; i<=k; i++)
	T.push_back(Count[i]-Count[1]);
	return T;
}

void solve(int L, int R) {
	if (R-L+1 < dy-dx) return;
	if (R-L+1==dy-dx && L-1<=dy) return;
	if (Tried.count(ii(L, R))==0) Tried.insert(ii(L, R)); else return;
	
	map<char, int> Zip;
	for (int i=L; i<=R; i++) {
		if (Zip[a[i]]==0)
		Zip[a[i]]=Zip.size();
		b[i] = Zip[a[i]];
	}
	for (int i=1; i<=Zip.size(); i++)
		Count[i] = 0;
	
	map<vi, int> Map;
	Map[current(Zip.size())]=L-1;
	for (int i=L; i<=R; i++) {
		Count[b[i]]++;
		vi T=current(Zip.size());
		if (Map.count(T)) {
			int j=Map[T];
			if (i-j>dy-dx || i-j==dy-dx && j<dx)
			{ dx=j, dy=i; }
		} else {
			Map[T] = i;
		}
	}
	
}

main() {
	//freopen("balstring.inp", "r", stdin);
	//freopen("balstring.out", "w", stdout);
	
	scanf("%s", a);
	n=strlen(a);
	
	char MaxChar = 0;
	for (int i=0; a[i]; i++)
		MaxChar = max(MaxChar, a[i]-=96);
		
	dx=-1, dy=-1;
	for (int k=0; k<(1<<MaxChar); k++) {
		vector<int> T;
		T.push_back(-1);
		for (int i=0; a[i]; i++)
			if ((1<<a[i]-1) & (~k))
			T.push_back(i);
		T.push_back(n);
		
		for (int i=1; i<T.size(); i++)
			if (T[i]-T[i-1]-1 > 0)
			solve(T[i-1]+1, T[i]-1);
	}
	cout << dx+1 << " " << dy << endl;
}
