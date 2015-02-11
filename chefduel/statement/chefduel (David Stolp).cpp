#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

char route[10001];
int len;

int K;
char maze[20][50][51];
short dist[20][50][50];
char exitdir[20][50][50];
int maze_size[20][2];
int start[20][2];
int goal[20][2];

const int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
const char *dirs="NESW";

void move(int robot[20][2], int dir){
	for(int k=0; k<K; k++){
		if(maze[k][robot[k][0]][robot[k][1]]=='E')
			continue;
		int ny=robot[k][0]+dy[dir], nx=robot[k][1]+dx[dir];
		if(0<=ny && ny<maze_size[k][0] && 0<=nx && nx<maze_size[k][1] && maze[k][ny][nx]!='#'){
			robot[k][0]=ny;
			robot[k][1]=nx;
		}
	}
}

void dfs(int k, int y, int x, int d=0, int e=0){
	if(!(0<=y && y<maze_size[k][0] && 0<=x && x<maze_size[k][1]))
		return;
	if(dist[k][y][x]!=-1 || maze[k][y][x]=='#')
		return;
	dist[k][y][x]=d;
	exitdir[k][y][x]=e;
	for(int i=0; i<4; i++)
		dfs(k, y+dy[i], x+dx[i], d+1, i^2);
}

void read(){
	scanf("%d", &K);
	for(int k=0; k<K; k++){
		scanf("%d %d", &maze_size[k][0], &maze_size[k][1]);
		for(int i=0; i<maze_size[k][0]; i++){
			scanf(" %s", maze[k][i]);
			for(int j=0; j<maze_size[k][1]; j++){
				if(maze[k][i][j]=='S'){
					start[k][0]=i;
					start[k][1]=j;
				}
				if(maze[k][i][j]=='E'){
					goal[k][0]=i;
					goal[k][1]=j;
				}
			}
		}
	}
}

int dfs2(int robot[20][2], int depth){
	if(depth==0){
		int sum=0;
		for(int k=0; k<K; k++)
			sum+=dist[k][robot[k][0]][robot[k][1]];
		return sum;
	}
	int ret=99999;
	for(int d=0; d<4; d++){
		int robot2[20][2];
		memcpy(robot2, robot, sizeof(robot2));
		move(robot2, d);
		ret=min(ret, dfs2(robot2, depth-1));
	}
	return ret;
}

void solve(){
	len=0;
	memset(dist, -1, sizeof(dist));
	int robot[20][2];
	for(int k=0; k<K; k++){
		dfs(k, goal[k][0], goal[k][1]);
		for(int i=0; i<maze_size[k][0]; i++)
		for(int j=0; j<maze_size[k][1]; j++){
			assert((maze[k][i][j]=='#')==(dist[k][i][j]<0));
		}
		robot[k][0]=start[k][0];
		robot[k][1]=start[k][1];
	}
	for(;;){
		int cur=0;
		for(int k=0; k<K; k++)
			cur+=dist[k][robot[k][0]][robot[k][1]];
		if(cur==0)
			break;
		int next=99999, best=-1;
		for(int depth=0; depth<5; depth++){
			for(int d=0; d<4; d++){
				int robot2[20][2];
				memcpy(robot2, robot, sizeof(robot));
				move(robot2, d);
				int h=dfs2(robot2, depth);
				if(h<next){
					next=h;
					best=d;
				}
			}
		}
		if(next>=cur){
			for(int k=0; k<K; k++){
				if(robot[k][0]!=goal[k][0] || robot[k][1]!=goal[k][1]){
					while(robot[k][0]!=goal[k][0] || robot[k][1]!=goal[k][1]){
						int d=exitdir[k][robot[k][0]][robot[k][1]];
						route[len++]=dirs[d];
						move(robot, d);
					}
					break;
				}
			}
		}else{
			route[len++]=dirs[best];
			move(robot, best);
		}
	}
	route[len]=0;
}

void print(){
	puts(route);
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		read();
		solve();
		print();
	}
	return 0;
}