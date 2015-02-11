#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
//const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define K 20
#define N 36
int k;
int n[K],m[K];
int sx[K],sy[K],ex[K],ey[K];
char s[K][N][N];
int t[K][N][N];
int bfsx[N*N],bfsy[N*N];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char dc[5]="EWSN";

#define MAXLEN 10000

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		fill(t,1);
		int L,h,i,j,k;
		scanf("%d",&L);
		VPII a(L);
		for(h=0;h<L;h++)
		{
			scanf("%d%d",n+h,m+h);
			for(i=0;i<n[h];i++)
			{
				scanf("%s",s[h][i]);
				for(j=0;j<m[h];j++)
				{
					if(s[h][i][j]=='S') s[h][sx[h]=i][sy[h]=j]='.';
					if(s[h][i][j]=='E') s[h][ex[h]=i][ey[h]=j]='.';
				}
			}
			a[h]=mp(sx[h],sy[h]);
			int len=0;
			bfsx[len]=ex[h];
			bfsy[len++]=ey[h];
			t[h][ex[h]][ey[h]]=0;
			for(int q=0;q<len;q++)
			{
				i=bfsx[q];
				j=bfsy[q];
				int tt=t[h][i][j]+1;
				for(k=0;k<4;k++)
				{
					int x=i+dx[k];
					int y=j+dy[k];
					if(0<=x && x<n[h] && 0<=y && y<m[h] && s[h][x][y]=='.' && t[h][x][y]>tt)
					{
						t[h][x][y]=tt;
						bfsx[len]=x;
						bfsy[len++]=y;
					}
				}
			}
		}
		char res[11111]="";
		int len=0;
		set<VPII> vis;
		for(;;)
		{
			int tt=0;
			for(h=0;h<L;h++)
				tt+=t[h][a[h].X][a[h].Y];
			if(tt==0)
				break;
			int bestt=inf;
			int bestk=-1;
			for(k=0;k<4;k++)
			{
				VPII aa=a;
				int curt=inf;
				for(h=0;h<L;h++)
				{
					if(t[h][a[h].X][a[h].Y]==0) continue;
					int x=a[h].X+dx[k];
					int y=a[h].Y+dy[k];
					if(0<=x && x<n[h] && 0<=y && y<m[h] && s[h][x][y]=='.')
					{
						MIN(curt,t[h][x][y]);
						aa[h]=mp(x,y);
					}
				}
				if(bestt>curt && !vis.count(aa))
					bestt=curt, bestk=k;
			}
			k=bestk;
			assert(k>=0);
			res[len++]=dc[k];
			assert(len<=MAXLEN);
			for(h=0;h<L;h++)
			{
				if(t[h][a[h].X][a[h].Y]==0) continue;
				int x=a[h].X+dx[k];
				int y=a[h].Y+dy[k];
				if(0<=x && x<n[h] && 0<=y && y<m[h] && s[h][x][y]=='.')
				{
					tt+=t[h][x][y]-t[h][a[h].X][a[h].Y];
					a[h]=mp(x,y);
				}
			}
		}
		puts(res);
	}
	return 0;
}
