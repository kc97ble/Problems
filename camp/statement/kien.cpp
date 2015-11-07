#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

const int N = 1003;
int m, n, a[N][N], s[N][N], Count[N][N];
int mm, nn, t;
int x1[N], y1[N], z1[N];
int x2[N], y2[N], z2[N];

inline int sum_range(int x, int y, int xx, int yy) {
	return s[x-1][y-1] + s[xx][yy]
		- s[x-1][yy] - s[xx][y-1];
}

int h(int x, int y, int i) {
	int S1 = sum_range(x1[i]+x, y1[i]+y, x2[i]+x, y2[i]+y);
	int w=x2[i]-x1[i]+1, h=y2[i]-y1[i]+1;
	int S2 = z1[i]==1 ?
		sum_range(x1[i]+x+w, y1[i]+y, x2[i]+x+w, y2[i]+y) :
		sum_range(x1[i]+x, y1[i]+y+h, x2[i]+x, y2[i]+y+h);
	return (S1<S2) != z2[i];
}

bool maximize(int &a, int b)
	{ if (a<b) a=b; else return false; return true; }

bool by_count(ii p, ii q)
	{ return Count[p.X][p.Y] > Count[q.X][q.Y]; }

main() {
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	scanf("%d", &a[i][j]);

	for (int i=1; i<=m; i++)
	for (int j=1; j<=n; j++)
	s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];

	scanf("%d%d%d", &mm, &nn, &t);
	for (int i=1; i<=t; i++) {
		scanf("%d%d%d%d%d%d", &x1[i], &y1[i],
			&x2[i], &y2[i], &z1[i], &z2[i]);
		x2[i]=x1[i]+x2[i]-1; y2[i]=y1[i]+y2[i]-1;
	}

	vector<ii> List;
	for (int i=0; i<m-mm+1; i++)
	for (int j=0; j<n-nn+1; j++)
	List.push_back(ii(i, j));

	const int Limit = 1000006;
	const double Coef = 0.50;
	int Passed = 0;

	for (int i=1; i<=t; i++) {
		for (int j=0; j<List.size(); j++) {
			int x=List[j].first, y=List[j].second;
			Count[x][y] += h(x, y, i);
		}
		Passed += List.size();
		if (Passed > Limit) {
			Passed=0; sort(List.begin(), List.end(), by_count);
			List.resize(min((int)List.size(), int(List.size()*Coef)+1));
		}
	}

	int Max=-1, dx=0, dy=0;

	for (int i=0; i<List.size(); i++)
	if (maximize(Max, Count[List[i].X][List[i].Y]))
	{ dx=List[i].X, dy=List[i].Y; }

	cout << dx+1 << " " << dy+1 << endl;
        cout << Max << endl;
}
