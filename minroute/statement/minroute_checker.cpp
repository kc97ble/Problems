#include <stdio.h>
#include <assert.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

void read_file(const char * FileName) {
	freopen(FileName, "r", stdin);
}

#define N 100005
int n;
map<int, int> Map[N];

main(int argc, char ** argv){
	read_file(argv[1]); // input
	scanf("%d", &n);	
	f1(i,n-1) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		Map[x][y]=Map[y][x]=z;
	}
	
	read_file(argv[2]); // answer
	int Expected;
	assert(scanf("%d", &Expected));
	
	read_file(argv[3]); // output
	int Sum, Count;
	assert(scanf("%d%d", &Sum, &Count)>0);
	assert(Count<2*n && Sum==Expected);
	vector<int> T(Count);
	f0(i,Count) assert(scanf("%d", &T[i]));
	
	int S = 0;
	f0(i,Count-1) {
		assert(Map[T[i]].count(T[i+1]) > 0);
		S += Map[T[i]][T[i+1]];
	}
	assert(S==Sum);
	cout << "DONE" << endl; // *** checker nay thieu mot so cho, can than
}
