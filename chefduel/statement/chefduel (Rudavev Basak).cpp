#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;




typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<double> VD;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;


// Time Library
#include <sys/time.h>

double getTime()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec+tv.tv_usec*1e-6;
}

void startTimer(double &start)
{
   start=getTime();
}

double timeNow(double start)
{
   return (getTime()-start);
}

//C++ Random Library
LL seed;
const LL modifier = 0x5DEECE66DLL;

void setSeed(LL x)
{
	seed = (seed ^ modifier) & ((1LL << 48) - 1);
}

int next(int bits)
{
	seed = (seed * modifier + 0xBL) & ((1LL << 48) - 1);
	return (int)(seed >> (48 - bits));
}

int nextInt(int n)
{
	if ((n & -n) == n)  // i.e., n is a power of 2
		return (int)((n * (LL)next(31)) >> 31);

	
	int bits, val;
	do {
		bits = next(31);
		val = bits % n;
	} while (bits - val + (n-1) < 0); 
	return val;
}

double nextDouble() 
{
   return (((LL)next(26) << 27) + next(27))/ (double)(1LL << 53);
}

VI nextPerm(int n)
{
	VI arr(n);
	for(int i=0;i<n;i++)
		arr[i]=i;
	for(int i=n-1;i>=0;i--)
	{
		int z = nextInt(i+1);
		swap(arr[z],arr[i]);
	}
	return arr;
}


/*Main code begins now */

int testnum;
double startTime;
double threshTime;

int K;
int R[25];
int C[25];
int grid[25][50][50];
int dir[25][50][50];
int dist[25][2500];
int origDist[25];
int sumDist;
int begx[25],begy[25],endx[25],endy[25];
char temp[100];
int npos[25][2500][4];
int npos2[25][2500][16];
int npos3[25][2500][64];
//int npos4[25][2500][256];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char dirName[] = {'N','S','W','E'};
int pos[25];
int perm[25];
bool lastTurnCompleted;
int totalSum,totalScore;
set<LL> donePos;
int step;
int steps;
PII bm1[1<<12],bm2[1<<12],bm3[1<<12],bm4[1<<12],bm5[1<<12];
int btop1,btop2,btop3,btop4,btop5;

void preprocess()
{
}

LL getHash()
{
	LL ans=1;
	for(int maze=0;maze<K;maze++)
		ans = ans*2503 + pos[maze] + 1;
	return ans;
}

inline bool ok(int maze,int nx,int ny)
{
	return (nx>=0 && nx<R[maze] && ny>=0 && ny<C[maze] && grid[maze][nx][ny]);
}

void print(int maze)
{
	for(int i=0;i<R[maze];i++)
	{
		for(int j=0;j<C[maze];j++)
		{
			if(i==begx[maze] && j==begy[maze])
				printf("E");
			else if(i==endx[maze] && j==endy[maze])
				printf("S");
			else if(grid[maze][i][j])
				printf(".");
			else
				printf("#");
		}
		printf("\n");
	}
}

void dfs(int maze,int x,int y,int d,int prevdir)
{
	dist[maze][50*x+y] = d;
	dir[maze][x][y] = prevdir;
	
	for(int k=0;k<4;k++)
	{
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(!ok(maze,nx,ny)) continue;
		if(dist[maze][50*nx+ny] > d+1)
			dfs(maze,nx,ny,d+1,k^1);
	}
}

double getCurScore()
{
	double sum=0;
	for(int maze=0;maze<K;maze++)
	{
		int d = dist[maze][pos[maze]];
		sum += 1.0/(1+d);
	}
	return sum;
}

void update(int k)
{
	for(int maze=0;maze<K;maze++)
		pos[maze] = npos[maze][pos[maze]][k];
}


int getMoveScore5(int k)
{
	int sum=0;
	for(int maze=0;maze<K;maze++)
		sum += dist[maze][npos2[maze][npos3[maze][pos[maze]][k&63]][k>>6]];
	return sum;
}

int getMoveScore6(int k)
{
	int sum=0;
	for(int maze=0;maze<K;maze++)
		sum += dist[maze][npos3[maze][npos3[maze][pos[maze]][k&63]][k>>6]];
	return sum;
}

int getMoveScore7(int k)
{
	int sum=0;
	for(int maze=0;maze<K;maze++)
	{
		int tpos = npos3[maze][pos[maze]][k&63];
		tpos = npos2[maze][tpos][(k>>6)&15];
		sum += dist[maze][ npos2[maze][tpos][k>>10] ];
	}
	return sum;
}

int getMoveScore8(int k)
{
	int sum=0;
	for(int maze=0;maze<K;maze++)
	{
		int tpos = npos3[maze][pos[maze]][k&63];
		tpos = npos3[maze][tpos][(k>>6)&63];
		sum += dist[maze][ npos2[maze][tpos][k>>12] ];
	}
	return sum;
}

int getMoveScore9(int k)
{
	int sum=0;
	for(int maze=0;maze<K;maze++)
	{
		int tpos = npos3[maze][pos[maze]][k&63];
		tpos = npos3[maze][tpos][(k>>6)&63];
		sum += dist[maze][ npos3[maze][tpos][k>>12] ];
	}
	return sum;
}

int getMoveScore10(int k)
{
	int sum=0;
	for(int maze=0;maze<K;maze++)
	{
		int tpos = npos3[maze][pos[maze]][k&63];
		tpos = npos3[maze][tpos][(k>>6)&63];
		tpos = npos2[maze][tpos][(k>>12)&15];
		sum += dist[maze][ npos2[maze][tpos][k>>16] ];
	}
	return sum;
}
	

bool check(VI ans)
{
	int n=ans.size();
	for(int maze=0;maze<K;maze++)
		pos[maze]=50*begx[maze]+begy[maze];
	
	for(int i=0;i<n;i++)
		update(ans[i]);
		
	for(int maze=0;maze<K;maze++)
		if(pos[maze]!=50*endx[maze]+endy[maze]) return false;
	return true;
}

VI getFromMask(int mask,int bits)
{
	VI ans(bits);
	for(int i=0;i<bits;i++)
	{
		ans[i]=mask&3;
		mask>>=2;
	}
	return ans;
}
		
	

void solve()
{
	startTimer(startTime);
	s(K);
	for(int maze=0;maze<K;maze++)
	{
		s(R[maze]);
		s(C[maze]);
		
		for(int i=0;i<R[maze];i++)
		{
			ss(temp);
			for(int j=0;j<C[maze];j++)
			{
				if(temp[j]=='#')
					grid[maze][i][j]=false;
				else
					grid[maze][i][j]=true;
				if(temp[j]=='S')
				{
					begx[maze]=i;
					begy[maze]=j;
				}
				if(temp[j]=='E')
				{
					endx[maze]=i;
					endy[maze]=j;
				}
			}
		}
	}
	
	//-----------------------------------INPUT DONE------------------------------------------//
	
	
	sumDist=0;
	for(int maze=0;maze<K;maze++)
	{
		for(int i=0;i<R[maze];i++)
			for(int j=0;j<C[maze];j++)
			{
				dir[maze][i][j]=-1;
				dist[maze][50*i+j]=INF;
			}
			
		dfs(maze,endx[maze],endy[maze],0,-2);
		origDist[maze] = dist[maze][50*begx[maze]+begy[maze]];
		sumDist += origDist[maze];
		
		for(int i=0;i<R[maze];i++)
			for(int j=0;j<C[maze];j++)
				for(int k=0;k<4;k++)
				{
					int nx=i+dx[k];
					int ny=j+dy[k];
					if((i==endx[maze] && j==endy[maze]) || !ok(maze,nx,ny))
						npos[maze][50*i+j][k]=50*i+j;
					else
						npos[maze][50*i+j][k]=50*nx+ny;
				}
	}
	
	//---------------------------------------------------PREPROCESSING DONE------------------------------//
	
	
	#ifndef EXTRA_PRECOMPUTE
	//int npos2[25][2500][16];
	for(int maze=0;maze<K;maze++)
		for(int i=0;i<R[maze];i++)
			for(int j=0;j<C[maze];j++)
			{
				int ttpos=50*i+j;
				for(int k=0;k<16;k++)
				{
					int tpos = npos[maze][ttpos][k&3]; 
					npos2[maze][ttpos][k] = npos[maze][tpos][k>>2]; 
				}
			}
			
	//int npos3[25][2500][64];
	for(int maze=0;maze<K;maze++)
		for(int i=0;i<R[maze];i++)
			for(int j=0;j<C[maze];j++)
			{
				int ttpos=50*i+j;
				for(int k=0;k<64;k++)
				{
					int tpos = npos[maze][ttpos][k&3]; 
					npos3[maze][ttpos][k] = npos2[maze][tpos][k>>2]; 
				}
			}
	
	// //int npos4[25][2500][256];
	// for(int maze=0;maze<K;maze++)
		// for(int i=0;i<R[maze];i++)
			// for(int j=0;j<C[maze];j++)
			// {
				// int ttpos=50*i+j;
				// for(int k=0;k<256;k++)
				// {
					// int tpos = npos2[maze][ttpos][k&15];
					// npos4[maze][ttpos][k] = npos2[maze][tpos][k>>4];
				// }
			// }
	#endif
	
	
	VI ans;
	for(int maze=0;maze<K;maze++)
		perm[maze]=maze;
	for(int maze=0;maze<K;maze++)
		pos[maze]=50*begx[maze]+begy[maze];
	donePos.clear();
	int forbidden=0;
	VI stepDirs(10);
	
	while(true)
	{
		bool left=false;
		for(int maze=0;maze<K;maze++)
			if(pos[maze]!=50*endx[maze]+endy[maze])
			{
				left=true;
				break;
			}
			
		if(!left)
			break;
		
		int bestMove = -1;
		int bestMoveScore = INF;
		
		steps = 5;
		btop1=0;
		btop2=0;
		btop3=0;
		btop4=0;
		btop5=0;
		
		for(int k=0;k<(1<<(2*steps));k++)
		{
			if(forbidden&(1<<(k&3))) continue;
			int curMoveScore = getMoveScore5(k);
			bm1[btop1++]=mp(curMoveScore,k);
		}
		sort(bm1,bm1+btop1);
		bestMove = (bm1[0].SS&3);
		
		
		for(int k=0;k<4;k++)
			for(int ind=0;ind<160 && ind<btop1;ind++)
			{
				int nk = bm1[ind].SS + (k<<10);
				int curMoveScore = getMoveScore6(nk);
				bm2[btop2++]=mp(curMoveScore,nk);
			}
		sort(bm2,bm2+btop2);
		bestMove = (bm2[0].SS&3);
		
		
		for(int k=0;k<4;k++)
			for(int ind=0;ind<160 && ind<btop2;ind++)
			{
				int nk = bm2[ind].SS + (k<<12);
				int curMoveScore = getMoveScore7(nk);
				bm3[btop3++]=mp(curMoveScore,nk);
			}
		sort(bm3,bm3+btop3);
		bestMove = (bm3[0].SS&3);
		
		
		for(int k=0;k<4;k++)
			for(int ind=0;ind<160 && ind<btop3;ind++)
			{
				int nk = bm3[ind].SS + (k<<14);
				int curMoveScore = getMoveScore8(nk);
				bm4[btop4++]=mp(curMoveScore,nk);
			}
		sort(bm4,bm4+btop4);
		bestMove = (bm4[0].SS&3);
		
		
		for(int k=0;k<4;k++)
			for(int ind=0;ind<160 && ind<btop4;ind++)
			{
				int nk = bm4[ind].SS + (k<<16);
				int curMoveScore = getMoveScore9(nk);
				bm5[btop5++]=mp(curMoveScore,nk);
			}
		sort(bm5,bm5+btop5);
		bestMove = (bm5[0].SS&3);
		
			
		for(int k=0;k<4;k++)
			for(int ind=0;ind<160 && ind<btop5;ind++)
			{
				int nk = bm5[ind].SS + (k<<18);
				int curMoveScore = getMoveScore10(nk);
				if(curMoveScore < bestMoveScore)
				{
					bestMoveScore = curMoveScore;
					bestMove = (nk&3);
				}
			}
			
		
		
		
		
		int tpos[25];
		for(int maze=0;maze<K;maze++)
			tpos[maze]=pos[maze];
		update(bestMove);
		
		LL hash = getHash();
		if(donePos.count(hash) > 0)
		{
			forbidden |= (1<<bestMove);
			for(int maze=0;maze<K;maze++)
				pos[maze]=tpos[maze];
		}
		else
		{
			ans.pb(bestMove);
			donePos.insert(hash);
			forbidden=0;
		}
			
			
			
		if(ans.size() > 500) 
			break;
	}
	
/*	#ifndef ONLINE_JUDGE
	assert(check(ans));
	debug(testnum,sumDist,ans.size());
	#endif*/
	
	totalSum += sumDist;
	totalScore += ans.size();
	
//	#ifdef ONLINE_JUDGE
	for(int i=0;i<ans.size();i++)
		printf("%c",dirName[ans[i]]);
	printf("\n");
//	#endif
	
		
}




int main()
{
	preprocess();
	totalSum=0;
	totalScore=0;
	step=0;
	int T; s(T);
	
	threshTime = 5.0/T - 0.1;
	for(testnum=1;testnum<=T;testnum++)
		solve();
		
/*	#ifndef ONLINE_JUDGE
	debug("Total",totalSum,totalScore,step);
	#endif*/
}
