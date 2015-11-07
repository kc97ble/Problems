#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, b[1000006];
string a[1000006];

main(int argc, char ** argv) {
	if (argc==3) freopen(argv[1], "r", stdin);
	cin >> n >> k;
	cin >> a[0];
	for (int i=1; i<=k; i++)
	cin >> a[i];
	
	if (argc==3) freopen(argv[2], "r", stdin);
	string S;
	for (int i=1; i<=k; i++) {
		assert(cin >> b[i]);
		assert(b[i]>=1 && b[i]<=k);
		S += a[b[i]];
	}
	assert(S==a[0]);
	sort(b+1, b+k+1);
	for (int i=1; i<=k; i++)
	assert(i==b[i]);
	cout << "OK" << endl;
}
