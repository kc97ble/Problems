#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int dx[N], dy[N];

string sorted(string a)
	{ sort(a.begin(), a.end()); return a; };

vector<int> solve(int L, int R) {
	vector<int> List;
	int Count = 0;
	for (int i=L; i<=R; i++)
	for (int j=i; j<=R; j++)
	if (sorted(to_string(i*j))==sorted(to_string(i)+to_string(j))) {
		dx[i*j]=i; dy[i*j]=j;
		List.push_back(i*j);
		//printf("%d=%d*%d\n", i*j, i, j);
		Count++;
	}
	#define all(a) a.begin(), a.end()
	sort(List.begin(), List.end());
	List.erase(unique(all(List)), List.end());
	return List;
}

main() {
	int n, k; scanf("%d%d", &k, &n);
	if (n==2) {
		vector<int> List = solve(1, 9);
		for (int i=0; i<k; i++)
		printf("%d=%dx%d\n", List[i], dx[List[i]], dy[List[i]]);
	} else if (n==4) {
		vector<int> List = solve(10, 99);
		for (int i=0; i<k; i++)
		printf("%d=%dx%d\n", List[i], dx[List[i]], dy[List[i]]);
	} else if (n==6) {
		string TrailingZero((n-6)/2, '0');
		const char * tz = TrailingZero.c_str();
		vector<int> List = solve(100, 999);
		for (int i=0; i<k; i++)
		printf("%d%s%s=%d%sx%d%s\n", List[i], tz, tz, dx[List[i]], tz, dy[List[i]], tz);
	}
}

