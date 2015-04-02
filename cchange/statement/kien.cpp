#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define for_each(it, a) for (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
const int N = 1000006;
const int oo = 0x3c3c3c3c;
typedef map<long, long> imi;
int n, a[52], F[52][N];

inline int f(int x, int n, bool Solved=true) {
	if (x==0) return 0;
	if (n==0) return oo;
	if (Solved) return F[n][x];
	int Min=f(x, n-1);
	if (x>=a[n]) Min = min(Min, f(x-a[n], n)+1);
	return F[n][x] = Min;
}

imi g(int x) {
	int k=n; while (a[k]>=x) k--;
	for (int i=0; i<=x; i++)
		F[0][i] = (i==0 ? 0 : oo);
	for (int i=1; i<=k; i++) {
		for (int j=0; j<=x; j++) {
			F[i][j] = F[i-1][j];
			if (j>=a[i]) F[i][j] = min(F[i][j], F[i][j-a[i]]+1);
			//f(j, i, false);
		}
	}
	int j=x; imi Result;
	for (int i=k; i>=1; i--)
		while (j>=a[i] && F[i][j]==F[i][j-a[i]]+1)
		{ Result[a[i]]++; j-=a[i]; }
	return Result;
}

long ceil(long a, long b)
	{ return a/b + !!(a%b); }

main(){
	long x; cin >> n >> x;
	for (int i=1; i<=n; i++)
	scanf("%d", &a[i]);
	
	long d = (x>=N ? ceil(x-(N-1), a[n]) : 0);
	imi Current = g(x-d*a[n]);
	if (d) Current[a[n]]+=d;
	
	long Result = 1;
	imi :: iterator Last = --Current.end();
	while (Last->first != 1) {
		//for_each(it, Current) printf("%d*%d ", it->first, it->second); printf("Current\n");
		imi Decision = g(Last->first);
		//for_each(it, Decision) printf("%d*%d ", it->first, it->second); printf("Decision\n");
		for_each(it, Decision)
		Current[it->first] += it->second * Last->second;
		Result += Last->second;
		Current.erase(Last);
		Last = --Current.end();
	}
	cout << Result << endl;
}
