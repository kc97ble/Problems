#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<complex>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define PB push_back
int n, m, k;
string forbid[100111];
vector<string> box; 
struct trieNut {
	int d[26];
};
vector<trieNut> trie;
int Create(bool finish) {
	trieNut tmp;
	memset(tmp.d, -1, sizeof(tmp.d));
	trie.PB(tmp);
	return trie.size() - 1;
}
void gen(int i, string s, string sub) {
	if (i == s.size()) {
		box.PB(sub);
		return;
	}
	if (s[i] == '?') {
		string tmp = sub + "A";
		gen(i + 1, s, tmp);
		tmp = sub + "B";
		gen(i + 1, s, tmp);
	}
	else {
		string tmp = sub + s[i];
		gen(i + 1, s, tmp);
	}
}
void add(string s) {
	box.clear();
	string sub = "";
	gen(0, s, sub);
	for(int i = 0; i < box.size(); i++) {
//		cout << box[i] << endl;
		s = box[i];
		int idx = 0;
		for(int j = 0; j < s.size(); j ++) {
			int next = trie[idx].d[s[j] - 'A'];
			if (next < 0) {
				next = Create(0);
				trie[idx].d[s[j] - 'A'] = next;
			}
			idx = next;
		}
	}
}
void getinput() {
	scanf("%d", &n);
	scanf("%d", &m);
	int tmp = Create(0);
	for(int i = 0; i < m; i++) {
		cin >> forbid[i];
		add(forbid[i]);
	}
	k = forbid[0].size();
}
map<string, int> f[55];
bool fit(string s) {
	if (s.size() < k) return false;
	int idx = 0;
	for(int j = 0; j < s.size(); j ++) {
		int next = trie[idx].d[s[j] - 'A'];
		if (next < 0) return false;
		idx = next;
	}
}
int calF(int i, string s) {
	if (fit(s)) return 0;
	if (i == n) return 1;
	if (f[i].count(s)) return f[i][s];
	int &res = f[i][s];
	res = 0;
	string tmp;
	for(char c = 'A'; c <= 'B'; c++) {
		if (s.size() == k) tmp = s.substr(1, k - 1);
		else tmp = s;
		tmp = tmp + c;
		res += calF(i + 1, tmp);
	}
//	cout << i << " " << s << " " << res << endl;   
	return res;
}
void process() {
	int q;
	scanf("%d", &q);
	for(int quest = 0; quest < q; quest ++) {
		int remain;
		scanf("%d", &remain);
		remain ++;
		string res = "";
		string tail = "";
		for(int i = 0; i < n; i++) {
//			cout << i << " " << tail << endl;
			for(char c = 'A'; c <= 'B'; c++) {
//				cout << i << " " << c << " " << remain << endl;
				string s;
				if (tail.size() < k) s = tail + c;
				else s = tail.substr(1, k - 1) + c;
				bool check = true;
				if (fit(s)) check = false;
				if (!check) continue;			
//				cout << s << " " << fit(s, forbid[0]) << endl;
				int tmp = calF(i + 1, s);
//				cout << i << " " << c << " " << remain << " " << tmp << endl;
				if (tmp >= remain) {
					res.PB(c);			
					tail = s;		
//					cout << c << endl;
					break;
				}
				else remain -= tmp;
			}
		}
		if (res.size() < n) cout << "NOPAGE" << endl;
		else cout << res << endl;
	}
}
int main() {
	getinput();
	process();
	return 0;
}
