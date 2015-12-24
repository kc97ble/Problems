#include <stdio.h>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1500006;
int n, k, a[N], s[N], F[N];

struct worker : public deque<int> {
	void push(int u) {
		while (size() && F[back()]>=F[u]) pop_back();
		push_back(u);
	}
	void pop(int u) {
		while (front() <= u) 
		pop_front();
	}
	int top() {
		return front();
	}
} W;

main() {
	//freopen("hack.inp", "r", stdin);
	//freopen("hack.out", "w", stdout);
	
	scanf("%d", &n); k=n-n/2;
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		a[i+n+n]=a[i+n]=a[i];
	for (int i=1; i<=3*n; i++)
		s[i] = s[i-1] + a[i];
	for (int i=1; i<=2*n; i++)
		F[i] = s[i+k-1]-s[i-1];
	for (int i=1; i<=k; i++)
		W.push(i);
	int Max = 0;
	for (int i=1; i<=n; i++) {
		Max = max(Max, F[W.top()]);
		W.pop(i); W.push(i+k);
	}
	cout << Max << endl;
}
