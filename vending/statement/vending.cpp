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

int n,B;
int f[41][41][1601];
int cost[41],amount[41],prefix[41];
int INF = 1 << 28;

int main() {
	scanf("%d %d", &n, &B);
	B = min(B,1600);
	for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
	for (int i = 0; i < n; i++) scanf("%d", &amount[i]);
	prefix[0] = cost[0];
	for (int i = 1; i < n; i++) prefix[i] = cost[i] + prefix[i - 1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 40; j++)
			for (int b = 0; b <= B; b++) f[i][j][b] = -INF;
	f[n][0][0] = 0;
	for (int i = n; i; i--)
		for (int j = 0; j <= 40; j++)
			for (int b = 0; b <= B; b++) if (f[i][j][b] > -INF)
				for (int add = 0; j + add <= 40 && add <= amount[i - 1] && b + add * cost[i - 1] <= B; add++) {
					// j hits previously, add with i - 1
					int tmp = f[i][j][b] + add * prefix[i - 1];
					tmp -= max(j + add - amount[i - 1],0) * cost[i - 1];
					f[i - 1][j + add][b + add * cost[i - 1]] = max(f[i - 1][j + add][b + add * cost[i - 1]],tmp);
				}
	int ret = -INF;
	for (int j = 0; j <= 40; j++)
		for (int b = 0; b <= B; b++) ret = max(ret,f[0][j][b]);
	printf("%d\n", ret);
}

