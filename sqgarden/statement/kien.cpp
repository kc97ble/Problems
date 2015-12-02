#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(), a.end()
const int N = 2000006, B=500;
int Count=0, n;
vector<int> a[N], Big;

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
	if (a[k].size() > B)
		Big.push_back(k);
	else {
		for (int i=0; i<a[k].size(); i++)
		for (int j=0; j<i; j++) {
			int d = a[k][i]-a[k][j];
			if (k<d) continue;
			if (binary_search(all(a[k-d]), a[k][i]))
			if (binary_search(all(a[k-d]), a[k][j]))
			Count++;
		}
		for (int i=0; i<a[k].size(); i++)
		for (int j=0; j<i; j++) {
			int d = a[k][i]-a[k][j];
			if (k+d>=N || a[k+d].size()<=B) continue;
			if (binary_search(all(a[k+d]), a[k][i]))
			if (binary_search(all(a[k+d]), a[k][j]))
			Count++;
		}
	}
	for (int i=0; i<Big.size(); i++)
	for (int j=0; j<i; j++) {
		int I=Big[i], J=Big[j];
		int d=I-J;
		for (int k=0; k<a[I].size(); k++)
		if (binary_search(all(a[I]), a[I][k]-d))
		if (binary_search(all(a[J]), a[I][k]))
		if (binary_search(all(a[J]), a[I][k]-d))
		Count++;
	}
	cout << Count << endl;
}
