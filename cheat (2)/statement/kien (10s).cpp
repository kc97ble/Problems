#include <stdio.h>
#include <string.h>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2500006, oo = 0x3c3c3c3c;
int m, n, F[N];
string a[N], b[N];
vector<int> d[N];

bool ok(vector<int> &d, int L) {
	if (L==0) return true;
	deque<int> qu;
	int n = d.size();
	F[n] = 0;
	#define h(u) (F[u]+u)
	for (int i=n-1; i>=0; i--) {
		if (i+L<=n) {
			while (qu.size() && h(qu.front())<=h(i+L)) qu.pop_front();
			qu.push_front(i+L);
		}
		while (qu.size() && qu.back()>i+d[i]) qu.pop_back();
		if (qu.empty()) F[i] = F[i+1];
		else F[i] = max(F[i+1], h(qu.back())-i);
	}
	return F[0]*10 >= n*9;
}

int solve(vector<int> &d) {
	int n = d.size();
	int ll=0, rr=n, mm=(ll+rr)/2;
	while (ll<rr) {
		if (ok(d, mm)) ll=mm; else rr=mm-1;
		mm=(ll+rr+1)/2;
	}
	return mm;
}

int match(const char a[], const char b[]) {
	int Count = 0;
	for (int i=0; a[i] && b[i]; i++)
	if (a[i]==b[i]) Count++; else break;
	return Count;
}

namespace suffix {
	char a[N];
	int n, sa[N], sb[N], ra[N], cp[N], rb[N];
	int m, d[N], g;
	
	bool by_strcmp(int x, int y)
		{ return strcmp(a+x, a+y) < 0; }
	inline bool cmp(int x, int y)
		{ return ra[x]==ra[y] ? ra[x+g]<ra[y+g] : ra[x]<ra[y]; }
	
	inline void add_string(const string &s) {
		for (int i=0; s[i]; i++) a[++n]=s[i];
		a[++n]='!';
	}
	
	inline void pop_string(const string &s, vector<int> &T) {
		T.resize(s.size());
		for (int i=0; s[i]; i++)
		T[i] = d[++n];
		++n;
	}
	
	void radix_sort(int a[], int b[], int n, int r[], int K){
		vector<int> Count(K+1), Start(K+1);
		for (int i=1; i<=n; i++) Count[r[a[i]]]++;
		for (int i=1; i<=K; i++) Start[i]=Start[i-1]+Count[i-1];
		for (int i=1; i<=n; i++) b[++Start[r[a[i]]]]=a[i];
	}
	
	void suffix_array() {
		for (int i=1; i<=n; i++) 
		{ sa[i]=i; ra[i]=a[i]; }
		
		for (g=1; g<=n; g*=2) {
			//radix_sort(sa, sb, n, ra+g, n);
			//radix_sort(sb, sa, n, ra, n);
			sort(sa+1, sa+n+1, cmp);
			for (int i=1; i<=n; i++)
			rb[sa[i]]=rb[sa[i-1]] + cmp(sa[i-1], sa[i]);
			for (int i=1; i<=n; i++)
			ra[i] = rb[i];
			if (ra[sa[n]]==n) break;
		}
		for (int i=1; i<=n; i++)
			ra[sa[i]]=i;
		
		int l=0;
		for (int i=1; i<=n; i++) {
			int j = sa[ra[i]+1];
			while (a[i+l]==a[j+l] && a[i+l]!='!') l++;
			cp[ra[i]]=l;
			if (l) l--;
		}
	}
	
	void left_to_right() {
		int Min = 0;
		for (int i=1; i<=n; i++)
		if (sa[i]<=m) Min=cp[i];
		else { d[sa[i]]=Min; Min=min(Min, cp[i]); }
	}
	
	void right_to_left() {
		int Min = oo;
		for (int i=n; i>=1; i--)
		if (sa[i]<=m) Min=oo;
		else { Min=min(Min, cp[i]); d[sa[i]]=max(d[sa[i]], Min); }
	}

	void execute() {
		for (int i=1; i<=::m; i++)
		add_string(::a[i]);
		m=n;
		for (int i=1; i<=::n; i++)
		add_string(::b[i]);
		
		suffix_array();
		left_to_right();
		right_to_left();
		
		n=m;
		for (int i=1; i<=::n; i++)
		pop_string(::b[i], ::d[i]);
	}
};


main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=m; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	suffix :: execute();
	
	for (int i=1; i<=n; i++)
	cout << solve(d[i]) << "\n";
}

