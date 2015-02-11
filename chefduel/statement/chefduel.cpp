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
const int hi[4] = {-1, 0, 1, 0};
const int hj[4] = {0, 1, 0, -1};
const char direct[4] = {'N', 'E', 'S', 'W'};
int k;
int m[26];
int n[26];
char board[26][55][55];
pair<int, int> Start[26];
pair<int, int> Exit[26];
void getinput() {
	scanf("%d\n", &k);
	for(int b = 0; b < k; b ++) {
		scanf("%d%d\n", &m[b], &n[b]);
		for(int i = 0; i < m[b]; i ++) {
			for(int j = 0; j < n[b]; j ++) {
				scanf("%c", &board[b][i][j]);
				if (board[b][i][j] == 'S') Start[b] = MP(i, j);
				if (board[b][i][j] == 'E') Exit[b] = MP(i, j);
			}
			scanf("\n");
		}
	}
}
bool visit[55][55];
int trace[55][55];
int order[26];
vector<int> Best;
void process() {
	vector<int> cur;
	for(int b = 0; b < k; b ++) {
		int r = order[b];
		pair<int, int> source = Start[r];
		bool breaking = false;
		if (source == Exit[r]) continue;
		for(int i = 0; i < cur.size(); i++) {
			pair<int, int> v = MP(source.F + hi[cur[i]], source.S + hj[cur[i]]);
			if (v.F < 0 || v.S < 0 || v.F >= m[r] || v.S >= n[r]) continue;
			if (board[r][v.F][v.S] == '#') continue;
			source = v;
			if (source == Exit[r]) breaking = true;
		}
		if (breaking) continue;
		queue<pair<int, int> > q;
		memset(visit, 0, sizeof(visit));
		visit[source.F][source.S] = true;
		trace[source.F][source.S] = -1;
		q.push(source);
		while (!q.empty()) {
			pair<int, int> u = q.front();
			q.pop();
			for(int p = 0; p < 4; p++) {
				pair<int, int> v = MP(u.F + hi[p], u.S + hj[p]);
				if (v.F < 0 || v.S < 0 || v.F >= m[r] || v.S >= n[r]) continue;
				if (board[r][v.F][v.S] == '#') continue;				
				if (!visit[v.F][v.S]) {
					visit[v.F][v.S] = true;
					trace[v.F][v.S] = (p + 2) % 4;
					q.push(v);
				}
			}
		}
		vector<int> tmp;
		pair<int, int> u = Exit[r];
		while (true) {
			if (trace[u.F][u.S] == -1) break;
			tmp.PB((trace[u.F][u.S] + 2) % 4);
			u = MP(u.F + hi[trace[u.F][u.S]], u.S + hj[trace[u.F][u.S]]);
		}
		reverse(tmp.begin(), tmp.end());
		for(int i = 0; i < tmp.size(); i ++)
			cur.PB(tmp[i]);
	}
//	cout << cur.size() << endl;
	if (Best.size() == 0 || cur.size() < Best.size()) {
//		cout << cur.size() << " " << Best.size() << endl;
		Best = cur;
	}
}
void Calculate() {	
	Best.clear();
	for(int i = 0; i < k; i ++) order[i] = i;
	srand(time(NULL));
	for(int p = 0; p < 100; p ++) {
		int a = rand() % k;
		int b = rand() % k;
		if (a == b) continue;
		swap(order[a], order[b]);
		process();
	}
	for(int i = 0; i < Best.size(); i++)
		printf("%c", direct[Best[i]]);
	printf("\n");
}
int main() {
//	freopen("chefduel.inp", "r", stdin);
//	freopen("chefduel.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test ++) {
		getinput();
		Calculate();
	}
	return 0;
}
