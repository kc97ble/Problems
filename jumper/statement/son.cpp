#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;
int m;
int k[60][60][60];
void bfs(int a,int b,int c)
{
	if (a>50 or b>50 or c>50) return ;
	if (a<0 or b<0 or c<0) return ;
	if (k[a][b][c]!=0) return;
	k[a][b][c]=1;
	bfs(a-1,b-1,c+1);
	bfs(a+1,b-1,c-1);
	bfs(a-1,b+1,c-1);
	
	bfs(a-1,b+1,c+1);
	bfs(a+1,b-1,c+1);
	bfs(a+1,b+1,c-1);
}

int main()
{
	int i,x,y,z,a,b,c,n;
	char s[60];
	gets(s+1);
	a=b=c=x=y=z=0;
	for(i=1;s[i];i++) 
	{  
		if (i%3==0 and s[i]=='*') a++; 
		if (i%3==1 and s[i]=='*') b++; 
		if (i%3==2 and s[i]=='*') c++; 
	}
	scanf("%d%*c",&n);
	bfs(a,b,c);
	m=0;
	while(n--)
	{
		x=y=z=0;
		gets(s+1);
		for(i=1;s[i];i++) 
		{  
			if (i%3==0 and s[i]=='*') x++; 
			if (i%3==1 and s[i]=='*') y++; 
			if (i%3==2 and s[i]=='*') z++; 
		}
		if (k[x][y][z]) m++;
	}
	printf("%d",m);
}


