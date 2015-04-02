#include <stdio.h>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int m;
deque<int> st;

main(){
	scanf("%d", &m);
	while (m--) {
		int x; scanf("%d", &x);
		if (x==-1) {
			if (st.size()==0) 
				printf("-1\n");
			else {
				printf("%d\n", st.back());
				st.pop_back();
			}
		} else if (x==0) {
			int k = min((int)st.size(), m-(int)st.size());
			deque<int> :: iterator it = st.end();
			for (int i=1; i<=k; i++)
			{ it=st.end()-i; st.push_front(*it); }
		} else {
			st.push_back(x);
		}
	}
}
