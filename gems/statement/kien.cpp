#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = (1<<24)+1;
int A, B, C, n, Next[N];
int Visiting[N], F[N]; //
stack<int> st;

void visit(int u) {
	while (!Visiting[u] && !F[u]) {
		Visiting[u] = st.size()+1;
		st.push(u); u=Next[u];
	}
	
	if (!F[u]) {
		F[u] = st.size()-Visiting[u]+1;
		while (st.top()!=u)
		{ F[st.top()]=F[u]; st.pop(); }
		st.pop();
	}
	while (st.size()) {
		int u=st.top(); st.pop();
		F[u] = F[Next[u]]+1;
	}
}

main() {
	int t; cin >> t;
	while (cin >> A >> B >> C >> n) {
		for (int i=0; i<n; i++)
			Next[i+1] = (1LL*A*i*i + B*i + C) % n + 1;
		for (int i=1; i<=n; i++)
			if (!F[i]) visit(i);
		cout << *max_element(F+1, F+n+1) << endl;
		
		memset(Visiting, 0, sizeof Visiting);
		memset(F, 0, sizeof F);	
	}
}
