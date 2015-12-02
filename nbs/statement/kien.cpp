#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

class vi: public vector<int> { public:
	vi() {}
	bool odd() { return at(0)&1; }
};

void operator /= (vi &a, int x) {
	int o=0;
	for (int i=a.size()-1; i>=0; i--) 
	{ a[i]+=o*10; o=a[i]%x; a[i]/=x; }
}

void operator -- (vi &a) {
	for (int i=0; i<a.size(); i++)
	if (a[i]) { a[i]--; return; }
	else a[i]=9;
}

istream& operator >> (istream& cin, vi &a) {
	string s; cin >> s; reverse(s.begin(), s.end());
	a.resize(s.size());
	for (int i=0; i<s.size(); i++)
	a[i] = s[i]-'0';
	return cin;
}

string DecToBin(vi t, int n) {
	string s;
	for (int i=1; i<=n; i++) {
		s += (t.odd() ? '1' : '0');
		t /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

main() {
	{
		int n; vi t; cin >> n >> t; --t;
		string s = DecToBin(t, n-!(n&1));
		if (n%2==0) {
			int c0 = count(s.begin(), s.end(), '0');
			s += (c0&1 ? '0' : '1');
		}
		cout << s << endl;
	}
	{
		string s; cin >> s;
		int n=s.size()-(~s.size()&1), t=0;
		for (int i=0; i<n; i++)
		t = (t*2 + (s[i]-'0')) % 111539786;
		cout << (t+1) % 111539786 << endl;
	}
}
