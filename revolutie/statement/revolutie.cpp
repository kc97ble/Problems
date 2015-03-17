#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const int MAX_N = 128;
const int MAX_T = 10;

int n;
int a[MAX_N][MAX_N];
int cup[MAX_N];
char vis[MAX_N];

int cupleaza(int i) {
	if (vis[i]) return 0;
	vis[i] = 1;
	for (int j = 1; j <= n; ++j)
		if (a[i][j] && (!cup[j] || (cup[j] != i && cupleaza(cup[j])))) {
			cup[j] = i;
			return 1;
		}
	return 0;
}

int main() {

	for (int t = 1; t <= MAX_T; ++t) {
		ostringstream filein;
		ostringstream fileout;
		filein << t << "-revolutie.in";
		fileout << t << "-revolutie.ok";

		ifstream fin(filein.str().c_str());
		ofstream fout(fileout.str().c_str());
	
		fin >> n;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				fin >> a[i][j];

		memset(cup, 0, sizeof(cup));

		int sol = 0;
		for (int i = 1; i <= n; ++i) {
			memset(vis, 0, sizeof(vis));
			sol += cupleaza(i);
		}

		if (sol != n) {
			fout << "-1\n";
			return 0;
		}

		fout << n << "\n";
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j)
				if (cup[j] == i) {
					fout << "C " << i << " " << j << "\n";
					swap(cup[i], cup[j]);
				}
	}
}