#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int m,n;
int d[55][55][55][55];
int mini[55][55];
int INF = 1 << 28;

struct MeetInTheMaze {
	long long getExpected(vector<string> maze) {
		m = maze.size();
		n = maze[0].size();
		for (int sx = 0; sx < m; sx++)
		  for (int sy = 0; sy < n; sy++) if (maze[sx][sy] != '#') {
		  	for (int i = 0; i < m; i++)
		  	  for (int j = 0; j < n; j++) d[sx][sy][i][j] = INF;
		  	d[sx][sy][sx][sy] = 0;

		  	queue< pair<int,int> > q;
		  	q.push(make_pair(sx,sy));
		  	while (!q.empty()) {
		  		int ux = q.front().first,uy = q.front().second;
		  		q.pop();
		  		for (int i = 0; i < 4; i++) {
		  			int vx = ux + dx[i],vy = uy + dy[i];
		  			if (vx < 0 || vx >= m || vy < 0 || vy >= n || maze[vx][vy] == '#' || d[sx][sy][vx][vy] < INF) continue;
		  			d[sx][sy][vx][vy] = 1 + d[sx][sy][ux][uy];
		  			q.push(make_pair(vx,vy));
		  		}
		  	}
		  }

		long long numerator = 0;
		vector< pair<int,int> > F,R;
		for (int i = 0; i < m; i++)
		  for (int j = 0; j < n; j++)
		    if (maze[i][j] == 'F') F.push_back(make_pair(i,j));
		    else if (maze[i][j] == 'R') R.push_back(make_pair(i,j));

		for (int a = 0; a < F.size(); a++)
		  for (int b = 0; b < R.size(); b++) {
		  	int fx = F[a].first,fy = F[a].second,rx = R[b].first,ry = R[b].second;
		  	vector< pair<int,int> > bucket[7502];
		  	for (int i = 0; i < m; i++)
		  	  for (int j = 0; j < n; j++) {
		  	  	mini[i][j] = d[i][j][fx][fy] + d[i][j][rx][ry];
		  	  	if (mini[i][j] <= 7500) bucket[mini[i][j]].push_back(make_pair(i,j));
		  	  }

		  	for (int len = 1; len <= 7500; len++)
		  		for (int i = 0; i < bucket[len].size(); i++) {
		  			int ux = bucket[len][i].first,uy = bucket[len][i].second;
		  			if (mini[ux][uy] < len) continue;
		  			for (int j = 0; j < 4; j++) {
		  				int vx = ux + dx[j],vy = uy + dy[j];
		  				if (vx < 0 || vx >= m || vy < 0 || vy >= n || maze[vx][vy] == '#') continue;
		  				if (mini[vx][vy] > len + 1) {
		  					mini[vx][vy] = len + 1;
		  					bucket[len + 1].push_back(make_pair(vx,vy));
		  				}
		  			}
		  		}

		  	for (int i = 0; i < m; i++)
		  	  for (int j = 0; j < n; j++) if (maze[i][j] == 'L') {
		  	  	if (mini[i][j] >= INF) continue;
		  	  	numerator += mini[i][j];
		  	  }
		  }

          return numerator;
	}

	string convert(long long x) {
		stringstream w;
		w << x;
		return w.str();
	}
} mf;

int main() {
    int fm,fn;
    vector<string> s;
    scanf("%d %d", &fm, &fn);
    for (int i = 0; i < fm; i++) {
        string f;
        cin >> f;
        s.push_back(f);
    }
    cout << mf.getExpected(s) << endl;
}
