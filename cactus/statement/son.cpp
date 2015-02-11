#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
vector <int> a[5100];
bool ddd[5100];
int par[5100];
int h[5100];
int Max=0;

int max(int a,int b) {return a>b?a:b;}
void dfs(int u)
{
	int i,v;
	for(i=0;v=a[u][i];i++)
	{
		if (v!=par[u]) 
			if (ddd[v]) Max=max(Max,h[u]-h[v]+1);
			else 
			{
				h[v]=h[u]+1;
				par[v]=u;
				ddd[v]=1;
				dfs(v);
			}
	}
}


int main()
{
	int n,m,u,v,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		Max=0;
		for(i=1;i<=n;i++) {a[i].clear();par[i]=0;h[i]=0;ddd[i]=0;}
		while(m--)
		{
			scanf("%d%d",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(i=1;i<=n;i++) a[i].push_back(0);
		ddd[1]=1;
		h[1]=1;
		dfs(1);
		printf("%d\n",Max);
	}
}

