#include<cstdio>
#include<iostream>
#define MAX 100005 
#define INF 10000000
#define f first
#define s second
using namespace std;

typedef pair<int,int> ii;
int a[MAX],c[MAX],n;
ii b[MAX];
//------------------------------------------------------------------------------
void init()
{
	int i;
	b[0].f=b[0].s=0;
	b[n+1].f=b[n+1].s=0;
	c[0]=c[n+1]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i] == 2) b[i].f=b[i-1].f+1;
		else b[i].f=b[i-1].f;
		if(a[n-i+1] == 1) b[n-i+1].s=b[n-i+2].s+1;
		else b[n-i+1].s=b[n-i+2].s;
	}
}
//------------------------------------------------------------------------------
int main()
{
	int i,min;
	min=INF;
	scanf("%d", &n);
	for(i=1;i<=n;i++) scanf("%d", &a[i]);
	init();
	for(i=1;i<=n;i++)
	{
		c[i]=b[i].f+b[i].s-1;
		if(min > c[i]) min=c[i];
	}
	printf("%d\n", min);
	return 0;
}
