#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int m, n, sa[N], sb[N], ra[N], rb[N];
vector<int> Bucket[N];
char a[N], b[N];

void enter() {
	cin >> m >> n;
	string P, S;
	while (cin >> S) P += S;
	strcpy(a+1, P.substr(0, m).c_str());
	strcpy(b+1, P.substr(m, n).c_str());
	//cout << a+1 << endl;
	//cout << b+1 << endl;
}

bool diff(int p, int q, int k) 
	{ return ra[p]!=ra[q] || ra[p+k]!=ra[q+k]; }

void radix_sort(int a[], int b[], int h[], int n, int MaxH) {
	for (int i=0; i<=MaxH; i++) Bucket[i].clear();
	for (int i=1; i<=n; i++) Bucket[h[a[i]]].push_back(a[i]);
	int k = 0;
	for (int i=0; i<=MaxH; i++)
	for (int j=0; j<Bucket[i].size(); j++)
	b[++k] = Bucket[i][j];
}

void suffix_array() {
	int MaxRank=127, k=1;
	for (int i=1; i<=m; i++)
	{ ra[i]=a[i]; sa[i]=i; }
	
	do {
		radix_sort(sa, sb, ra+k, m, MaxRank);
		radix_sort(sb, sa, ra, m, MaxRank);
		
		MaxRank = 0;
		for (int i=1; i<=m; i++) {
			if (i==1 || diff(sa[i], sa[i-1], k)) 
				MaxRank++;
			rb[sa[i]] = MaxRank;
		}
		for (int i=1; i<=m; i++)
			ra[i] = rb[i];
		k*=2;
		//for (int i=1; i<=m; i++)
		//printf("%d %s\n", sa[i], a+sa[i]);
	} while (MaxRank != m);
}

int cmp_k=0;

bool cmp_1(int x, char c) 
	{ return a[x+cmp_k] < c; }
bool cmp_2(char c, int x)
	{ return c < a[x+cmp_k]; }

main() {
	enter();
	suffix_array();
	//for (int i=2; i<=m; i++)
	//assert(strcmp(a+sa[i-1], a+sa[i]) < 0);
	
	//for (int i=1; i<=m; i++)
	//printf("%d %s\n", sa[i], a+sa[i]);
	int ll=1, rr=m, Result=1; cmp_k=0;
	for (int i=1; i<=n; ) {
		//printf("%d %c %d: %d %d (%s) %d %d (%s)\n", 
		//	i, b[i], cmp_k, 
		//	ll, sa[ll], a+sa[ll], rr, sa[rr], a+sa[rr]);
		int L = lower_bound(sa+ll, sa+rr+1, b[i], cmp_1) - sa;
		int R = upper_bound(sa+ll, sa+rr+1, b[i], cmp_2) - sa;
		if (L==R) { ll=1, rr=m, cmp_k=0, Result++; }
		else { ll=L, rr=R-1, i++, cmp_k++; }
	}
	cout << Result << endl;
}
