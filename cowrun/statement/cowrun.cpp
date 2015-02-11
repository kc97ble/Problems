#include<cmath>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 100005 
#define INF 1000000
using namespace std;

int a[MAX],q[505][10005];
int n,m;
//------------------------------------------------------------------------------
void Try()
{
	int i,j,t;
	memset(q,0,sizeof(q));
	for(j=m;j>=0;j--)
	{
	for(i=0;i<=n;i++)
	{	
		for(t=1;t<n;t++){q[j-t][i+t]=max(q[j][t]+a[i+t],q[j-t][i+t]);}
		if(j == m) q[m][i+1]=max(q[m][i],q[m][i+1]);
		q[m][i+(m-j)]=max(q[j][i],q[m][i+(m-j)]);
	}
	}
}
//------------------------------------------------------------------------------
int main()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++) scanf("%d", &a[i]);
	Try();
	printf("%d\n", q[m][n]);
	return 0;
}

