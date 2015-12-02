#include <bits/stdc++.h>
using namespace std;

const int limit = 100000 + 5;
const int lim = 1000 + 5;
int f[limit][lim];

int main(){
	int n, k;
	scanf("%d%d",&n,&k);
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		scanf("%d",&a[i]);
	
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i < n; ++i){
		if (i > 0) f[i][1] = f[i-1][1]; else f[i][1] = a[i];
		f[i][1] = max(f[i][1], a[i]);		
	}
		
	int MAX = f[0][0];
	for(int j = 2; j <= k; ++j){
		stack< pair<int,int> > st;		
		for(int i = 0; i < n; ++i){
			int cur = MAX;
			while(!st.empty() && st.top().second <= a[i]){
				cur = min(cur, st.top().first);
				st.pop();
			}
			
			if (cur != MAX && 
				(st.empty() || cur+a[i] < st.top().first + st.top().second) )
					st.push( pair<int,int> (cur, a[i]) );
			
			if (i+1 >= j)
				f[i][j] = st.top().first + st.top().second;
			
			if (f[i][j-1] < f[i][j])
				st.push( pair<int,int> (f[i][j-1], 0) );	
		}	
	}
	
	printf("%d\n",f[n-1][k]);
	

}