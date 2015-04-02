#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define all(a) a.begin(), a.end()
#define for_each(it, a) for (__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
typedef pair<int, int> ii;
const int N=2000006, B=250;
int n;
vector<int> a[N], Big;
long Sum=0;
map<ii, int> Map;

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x+=1000000; y+=1000000;
		a[x].push_back(y);
	}
	for (int k=0; k<N; k++)
		sort(a[k].begin(), a[k].end());
	for (int k=0; k<N; k++) 
	if (a[k].size()>=B) {
		Big.push_back(k);
	} else {
		for (int i=0; i<a[k].size(); i++)
			for (int j=0; j<i; j++)
			Sum += Map[ii(a[k][i], a[k][j])];
		for (int i=0; i<a[k].size(); i++)
			for (int j=0; j<i; j++)
			Map[ii(a[k][i], a[k][j])]++;
	}
	for (int k=0; k<N; k++) 
	if (a[k].size()<B)
	for_each(it, Big) {
		int K = *it;
		
		for (int i=0; i<a[k].size(); i++)
		for (int j=0; j<i; j++)
		if (binary_search(all(a[K]), a[k][i]))
		if (binary_search(all(a[K]), a[k][j]))
		Sum ++;
	}
	for (int i=0; i<Big.size(); i++)
	for (int j=0; j<i; j++) {
		int I=Big[i], J=Big[j];
		int q=0, Count=0;
		for (int p=0; p<a[I].size(); p++) {
			while (q<a[J].size() && a[J][q]<a[I][p]) q++;
			if (q<a[J].size() && a[J][q]==a[I][p])
			{ Sum+=Count; Count++; }
		}
	}
	cout << Sum << endl;
}
