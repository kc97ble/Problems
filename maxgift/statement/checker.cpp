#include <bits/stdc++.h>
using namespace std;

#define long long long
const int N = 302;
int n, k, a[N], b[N];

int min_range(int L, int R) 
	{ return *min_element(a+L, a+R+1); }

long solution() {
	long Result;
	assert(cin >> Result);
	for (int i=1; i<=k-1; i++)
		assert(scanf("%d", &b[i])==1);
	b[k]=n; b[0]=0;
	for (int i=1; i<=k-1; i++)
		assert(b[i]>b[i-1] && b[i]>=1 && b[i]<=n);
	long Sum=0;
	for (int i=1; i<=k; i++)
		Sum += min_range(b[i-1]+1, b[i]);
	assert(Sum==Result);
	return Result;
}

main(int argc, char ** argv) {
	if (argc==4) freopen(argv[1], "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	if (argc==4) freopen(argv[2], "r", stdin);
	long Result1 = solution();
	
	if (argc==4) freopen(argv[3], "r", stdin);
	long Result2 = solution();
	
	assert(Result1 == Result2);
}

