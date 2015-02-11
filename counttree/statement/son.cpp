#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int k;
vector <int> a[60];
long long F[60][60];
int FF[60][60];
long long g(int u,int p);
long long f(int u,int i,int x,int p)
{
	
	if (x>k) return 0;
	if (a[u][i]==0) return 1;
	if (a[u][i]==p) return f(u,i+1,x,p);
	int v=a[u][i];
	
	if (FF[v][x]==k+1) return F[v][x];
	else FF[v][x]=k+1;
	long long r=f(v,0,1,u)*f(u,i+1,x+1,p)+g(v,u)*f(u,i+1,x,p);
	return F[v][x]=r;
}
long long G[60];
int GG[60];
long long g(int u,int p)
{
	
	if (GG[u]==k+1) return G[u];
	else GG[u]=k+1;
	int i,v;
	long long r=1;
	for(i=0;v=a[u][i];i++)
		if (v!=p) r*=f(v,0,0,u)+g(v,u);
	return G[u]=r;
}
		


int main()
{
	int n,i,j;
	char c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++) 
	{
		scanf(" %c",&c);
		if (c=='Y') a[i].push_back(j);
	}
	for(i=1;i<=n;i++) a[i].push_back(0);
	for(i=0;i<n;i++)
	{
		k=i;
		printf("%lld\n",f(1,0,0,0)+g(1,0));
	}
	
	
}
