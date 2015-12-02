#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int t=0;
char s[123], FileName[123];

main() {
	freopen("out.txt", "r", stdin);
	while (gets(s)) {
		sprintf(FileName, "lthterror.%d.ans", ++t);
		cerr << FileName << endl;
		freopen(FileName, "w", stdout);
		puts(s);
	}
}

