#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	long long n;
	cin >> n;
	while (n % 2 == 0) n /= 2;
	if (n == 1) printf("TAK\n"); else printf("NIE\n");
}
