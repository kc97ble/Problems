#include "testlib.h"
using namespace std;

int check(InStream& in, char *pattern, const string& s, int n, int k) {
	string t = in.readWord(pattern);
	int res = 0, blocks = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while ((j < n) && (t[j] == t[i]))
			res += (int) (t[j] != s[j]), ++j;
		++blocks, i = j;
	}
	if (blocks > k)
		in.quitf(_wa, "too many blocks");
	return res;
}

int main(int argc, char ** argv) {
	registerTestlibCmd(argc, argv);
	char pattern[100];
	int t = inf.readInt();
	for (int i = 0; i < t; ++i) {
		int n = inf.readInt();
		int k = inf.readInt();
		string s = inf.readWord();
		sprintf(pattern, "[01]{%d,%d}", n, n);
		int jury = check(ans, pattern, s, n, k);
		int cont = check(ouf, pattern, s, n, k);
		if (jury < cont)
			quitf(_wa, "answer for testcase %d is not optimal: %d instead of %d", i + 1, cont, jury);
		if (cont < jury)
			quitf(_fail, "answer for testcase %d is not optimal: %d instead of %d", i + 1, jury, cont);
	}
	quitf(_ok, "%d testcases", t);
	return 0;
}
