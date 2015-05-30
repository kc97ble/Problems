#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef vector<int> vi;

vi p2[123];

istream& operator >> (istream& cin, vi &a) {
	string s; cin >> s;
	a.resize(s.size());
	reverse(s.begin(), s.end());
	for (int i=0; i<a.size(); i++)
	a[i] = s[i]-'0';
	return cin;
}

ostream& operator << (ostream& cout, const vi &a) {
	for (int i=a.size()-1; i>=0; i--)
	printf("%d", a[i]);
	return cout;
}

bool operator < (const vi &a, const vi &b) {
	if (a.size() != b.size())
	return a.size() < b.size();
	for (int i=a.size()-1; i>=0; i--)
	if (a[i]!=b[i]) return a[i]<b[i];
	return false;
}

void fix(vi &a) {
	for (int i=0; i+1<a.size(); i++) {
		while (a[i]<0) { a[i]+=10; a[i+1]-=1; }
		while (a[i]>=10) { a[i]-=10; a[i+1]+=1; }
	}
	while (a.size()>=2 && a.back()==0)
	a.pop_back();
}

vi operator + (const vi &a, const vi &b) {
	vi c(a);
	c.resize(max(a.size(), b.size())+1);
	for (int i=0; i<b.size(); i++)
	c[i] += b[i];
	return fix(c), c;
}

vi operator - (const vi &a, const vi &b) {
	vi c(a);
	c.resize(max(a.size(), b.size())+1);
	for (int i=0; i<b.size(); i++)
	c[i] -= b[i];
	return fix(c), c;
}

void f(int n, char A, char B, char C, vi p) {
	if (n==0) return;
	if (p<p2[n-1]) { f(n-1, A, C, B, p); printf("%c", A); }
	else { f(n-1, B, A, C, p-p2[n-1]); printf("%c", C); }
}

char s[123];

vi g(int n, char A, char B, char C) {
	if (n==0) return vi(1, 0);
	if (s[n]==A) return g(n-1, A, C, B);
	if (s[n]==C) return g(n-1, B, A, C) + p2[n-1];
	cout << "-1" << endl; exit(0);
}

main() {
	p2[0]=vi(1, 1);
	for (int i=1; i<123; i++)
	p2[i] = p2[i-1] + p2[i-1];
	
	int n; scanf("%d", &n);
	vi p; cin >> p;
	f(n, 'A', 'B', 'C', p); cout << endl;
	scanf("%s", s+1);
	cout << g(n, 'A', 'B', 'C') << endl;
}
