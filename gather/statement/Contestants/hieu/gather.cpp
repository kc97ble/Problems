#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAX 100000
#define INF 2000111000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <vii> vvii;

int n, amount;
int c[MAX+1];
vvii s (MAX+1);
int h[MAX+1];
int a[MAX+1];
int euler[2*MAX+1];
int min_pos[MAX+1];
int max_pos[MAX+1];
vvi rmq (2*MAX+1);

void input() {
	cin>>n;
	int u, v, w;
	for (int i=1; i<=n; i++) scanf("%d", &c[i]);
	for (int i=1; i<n; i++) {
		scanf("%d %d %d", &u, &v, &w);
		s[u].push_back(ii(v, w));
		s[v].push_back(ii(u, w));
	}
}

void high(int v, int order) {
	h[v]=order;
	for (int i=0; i<s[v].size(); i++) {
		int u=s[v][i].first;
		if (h[u]==0) high(u, order+1);
	}
}

void leng(int v) {
	for (int i=0; i<s[v].size(); i++) {
		int u=s[v][i].first;
		int w=s[v][i].second;
		if (h[u]>h[v]) {
			a[u]=a[v]+w;
			leng(u);
		}
	}
}

void euler_tour(int v) {
	euler[++amount]=v;
	min_pos[v]=max_pos[v]=amount;
	for (int i=0; i<s[v].size(); i++) {
		int u=s[v][i].first;
		if (h[u]>h[v]) {
			euler_tour(u);
			euler[++amount]=v;
			max_pos[v]=amount;
		}
	}
}

void RMQ() {
	for (int i=amount; i>=1; i--) {
		rmq[i].push_back(euler[i]);
		int j=1, d=0;
		while (i+j+j-1<=amount) {
			int c=rmq[i][d];
			if (h[rmq[i+j][d]]<h[c]) c=rmq[i+j][d];
			rmq[i].push_back(c);
			j<<=1;
			d++;
		}
	}
}

int get_min(int x, int y) {
	int l=y-x+1;
	int j=1, d=0;
	while (j+j<l) {
		j<<=1;
		d++;
	}
	int c=rmq[x][d];
	if (h[rmq[y-j+1][d]]<h[c]) c=rmq[y-j+1][d];
	return c;
}

int lca(int u, int v) {
	int x=min(min_pos[u], min_pos[v]);
	int y=max(max_pos[u], max_pos[v]);
	return get_min(x, y);
}

int leng_path(int u1, int u2) {
	int v=lca(u1, u2);
	return a[u1]-a[v]+a[u2]-a[v];
}

int main(void) {
	input();
	high(1, 1);
	leng(1);
	euler_tour(1);
	RMQ();
	int result=INF, r;
	for (int i=1; i<=n; i++) {
		r=0;
		for (int j=1; j<=n; j++) r+=c[j]*leng_path(j, i);
		result=min(result, r);
	}
	cout<<result;
}
