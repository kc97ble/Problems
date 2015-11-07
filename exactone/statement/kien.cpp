#include <bits/stdc++.h>
using namespace std;

#define long long long
int n;
long S123, S12, S23, S13, S1, S2, S3;
int c[123][123][123];

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		S123 += c[x][y][z]++;
		S23 += c[0][y][z]++; 
		S13 += c[x][0][z]++;
		S12 += c[x][y][0]++;
		S1 += c[x][0][0]++;
		S2 += c[0][y][0]++;
		S3 += c[0][0][z]++;
		c[0][0][0]++;
	}
	cout << (S1+S2+S3)-2*(S12+S23+S13)+3*S123 << endl;
}

