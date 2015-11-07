#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
long L, R, k;

long ceil(long a, long b) 
	{ return a/b + !!(a%b); }

main() {
	while (cin >> L >> R >> k) {
		string Min = "~";
		for (long i=1; i<=R; i=i*10) {
			long x = ceil(max(i, L), k) * k;
			if (x<=R) Min = min(Min, to_string(x));
		}
		if (Min=="~") Min="-1";
		cout << Min << endl;
	}
}

