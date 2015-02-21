#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define fi "gather.inp"
#define fo "gather.out"
#define nmax 100000+5
using namespace std;
typedef long long ll;
typedef pair<int,int> II;
typedef vector<II> VII;
const ll INF=ll(1e18);
//VARIABLES
int n,a[nmax],d[nmax],Trace[nmax];
VII c[nmax];
ll S,res=INF;
//FUNCTION PROTOTYPES

void Init();
void Process();

//MAIN
int main()
{
//       freopen(fi,"r",stdin);
//       freopen(fo,"w",stdout);
       Init();
       Process();
       return 0;
}

//FUNCTIONS AND PROCEDURES
void Add(int p, int q, int r)
{
	c[p].push_back(II(q,r));
}
void Init()
{
	int p,q,r;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<n;++i)
	{
		scanf("%d%d%d",&p,&q,&r);
		Add(p,q,r);
		Add(q,p,r);
	}
}
void DFS(int i)
{
	VII::iterator it;
	d[i]=a[i];
	for (it=c[i].begin();it!=c[i].end();++it)
	if (Trace[it->first]==0)
	{
		Trace[it->first]=i;
		DFS(it->first);
		d[i]+=d[it->first];
		S+=ll(d[it->first])*ll(it->second);
	}
}
void Cal(int i)
{
	VII::iterator it;
//	cout << i << " " << S << endl;
	res=min(res,S);
	for (it=c[i].begin();it!=c[i].end();++it)
	if (it->first!=Trace[i])
	{
		S+=ll(d[1]-2*d[it->first])*ll(it->second);
		Cal(it->first);
		S-=ll(d[1]-2*d[it->first])*ll(it->second);
	}
}
void Process()
{
	Trace[1]=-1;
	DFS(1);
	Cal(1);
	cout << res << endl;
}
