#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define c u][less][more
char A[10],B[10];
int x;
int G[10][2][2];
int F[10][2][2][2];
int GG[10][2][2];
int FF[10][2][2][2];
int t;
int g(int u,bool less,bool more)
{
	int i,r=0;
	if (A[u]==0) return 1;
	if (GG[c]==t) return G[c];
	else GG[c]=t;
	for(i='0';i<='9';i++)
	{
		if (more or i>=A[u])
		if (less or B[u]>=i)
		r+=g(u+1,less or (B[u]-i),more or (i-A[u]));
	}
	return G[c]=r;
}
int f(int u,bool less,bool more,bool one)
{
	int i,r=0;
	if (A[u]==0) return 0;
	if (FF[c][one]==t) return F[c][one] ;
	else FF[c][one]=t;
	for(i='0';i<='9';i++)
	{
		if (more or i>=A[u])
		if (less or B[u]>=i)
		{
			r+=f(u+1,less or B[u]-i,more or i-A[u],i!='0' or one);
			if (i==x and (x!='0' or one)) r+=g(u+1,less or (B[u]-i),more or (i-A[u]));
		}
	}
	return F[c][one]=r;
}
int main()
{
	int a,b;

	for(;;)
	{
		scanf("%d%d",&a,&b);
		if (a==0 and b==0) return 0;
		sprintf(A,"%09d",a);
		sprintf(B,"%09d",b);
		for(x='0';x<='9';x++)
		{
			printf("%d ",f(0,0,0,0));
			++t;
		}
		printf("\n");

	}


}
