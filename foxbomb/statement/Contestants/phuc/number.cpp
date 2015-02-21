#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
using namespace std;

const int modulo = 1e9 + 7;
int n, a [11], comb [111][111], f [111][111], res = 0;


void cal () {
	//cerr << n << endl;
	memset (f, 0, sizeof f);
	f [10][0] = 1;

	for (int i = 9; i >= 0; --i)
		for (int j = 0; j <= n; ++j)
			for (int k = a [i]; k <= j; ++k) {
				f [i][j] += 1LL * f [i + 1][j - k] * comb [j][k] % modulo;
				if (f [i][j] >= modulo) f [i][j] -= modulo;
			}
	for (int i = 0; i <= n; ++i) {
		res += f [0][i];
		if (res >= modulo) res -= modulo;
	}
}

int main (int ac, char **av) {	
	comb [0][0] = 1;
	for (int i = 1; i < 111; ++i) {
		comb [i][0] = comb [i][i] = 1;
		for (int j = 1; j < i; ++j) {
			comb [i][j] = comb [i - 1][j - 1] + comb [i][j - 1];
			if (comb [i][j] >= modulo) comb [i][j] -= modulo;
		}
	}

	cin >> n;
	for (int i = 0; i < 10; ++i) {
		cin >> a [i];
	}

	--n;
	for (int i = 1; i < 10; ++i) {
		int t = a [i];
		a [i] = max (0, a [i] - 1);
		long long cur = res;
		cal ();
		//cerr << i << " " << res - cur << endl;
		a [i] = t;
	}
	cout << res << endl;

	return 0;
}
