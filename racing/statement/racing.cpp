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

char a[MAX];
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main()
{
	int i,n,m,u,f,d;
	int t[MAX];
	t[0]=0;
	scanf("%d %d %d %d %d", &n, &m, &u, &f, &d);
	t[m+1]=INF;
	for(i=1;i<=m;i++)
	{
		getchar();
		scanf("%c", &a[i]);
		if(a[i] == 'u'){t[i]=t[i-1]+u+d;}
		if(a[i] == 'f'){t[i]=t[i-1]+f*2;}
		if(a[i] == 'd'){t[i]=t[i-1]+u+d;}
	}
	for(i=1;i<=m+1;i++)
	{
		if(t[i] > n) {printf("%d\n", i-1);break;}
	}
	return 0;
}
