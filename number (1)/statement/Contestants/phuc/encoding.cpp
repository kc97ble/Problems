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

const int maxn = 10004;
int f [maxn];



int main (int ac, char **av) {	
	cout << "00" << endl;
		cout << "01" << endl;
		cout << "100" << endl;
		cout << "101" << endl;
		cout << "110" << endl;
		cout << "111" << endl;
		return 0;
	f [1] = 1;
	f [2] = 2;
	for (int i = 3; i <= 100; ++i) {
		f [i] = 1e9;
		for (int j = 1; j < i; ++j) {
			//if (i == 4) cerr << f [j] << " " << f [i - j] << endl;
			f [i] = min (f [i], f [j] + f [i - j] + i);
		}
	}
	//cerr << f [4] << endl;
	for (int i = 3; i <= 100; ++i) {
		int c = 0;
		for (int j = 1; j <= i / 2; ++j)
			if (f [i] == f [j] + f [i - j] + i)
				++c;
		if (c != 1) cerr << i << endl;
	}
	for (int i = 1; i <= 10; ++i) cerr << f[i] << endl;
	return 0;
}
