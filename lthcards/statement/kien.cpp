#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

main() {
	long A, B, Max=0;
	cin >> A >> B;
	Max = B;
	for (int i=0; i<=62; i++) {
		long M = (1LL<<i)-1;
		if ((B&~M)-1 >= A)
		Max = max(Max, B|M);
	}
	cout << Max << endl;
}
