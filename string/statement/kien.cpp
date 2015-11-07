#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long unsigned long long
const int N = 1000006;
int n, k;
long a[N], b[N];
char A[N], B[N];
int aa[N], bb[N], Result[N];

long hash(char a[], int n) {
	long Sum = 0;
	for (int i=1; i<=n; i++)
	Sum = (Sum * 2309 + a[i]) % 1000000007;
	return Sum;
}

bool by_a(int x, int y)
	{ return a[x] < a[y]; }
bool by_b(int x, int y)
	{ return b[x] < b[y]; }

main() {
	scanf("%d%d", &n, &k);
	scanf("%s", A+1);
	for (int i=1; i<=k; i++)
		a[i] = ::hash(A+(i-1)*(n/k), n/k);
	for (int i=1; i<=k; i++) {
		scanf("%s", B+1);
		b[i] = ::hash(B, n/k);
	}
	
	//for (int i=1; i<=k; i++) printf("%llx ", a[i]); printf("\n");
	//for (int i=1; i<=k; i++) printf("%llx ", b[i]); printf("\n");
	
	for (int i=1; i<=k; i++) aa[i]=i;
	stable_sort(aa+1, aa+k+1, by_a);
	for (int i=1; i<=k; i++) bb[i]=i;
	stable_sort(bb+1, bb+k+1, by_b);
	
	for (int i=1; i<=k; i++)
	Result[aa[i]]=bb[i];
	for (int i=1; i<=k; i++)
	printf("%d ", Result[i]);
	cout << endl;
}
