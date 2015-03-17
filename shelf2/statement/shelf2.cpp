#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
//#include<conio.h>
#define MAX 1<<30
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)

int C[100];
int cow(int n,int m)
{
	int d[n+1][m+1];
	fo(i,0,n)
		fo(j,0,m)
			if(!i||!j) d[i][j]=m;
			else d[i][j]=(j>=C[i-1])? d[i-1][j-C[i-1]]-C[i-1]:d[i-1][j];
	
	return d[n][m];
}

int main()
{
	//freopen("abc.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	fo(i,0,n-1) scanf("%d",&C[i]);
	printf("%d",cow(n,m));
	//getch();
    return 0;
}

