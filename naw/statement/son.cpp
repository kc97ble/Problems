#include<cstdio>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<map>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
char s[5100];
int n;
int base=1000000000;
int F[5100][5100];
bool G[5100][5100];
int f(int i,int d)
{
	if (d<0) return 0;
	if (i==n+1) return 1;
	if (G[i][d]++) return F[i][d];
        long Sum = 0;
	if (s[i]=='-')
           if (d%2==0) Sum=f(i,d-2)+f(i+1,d+1);
	   else Sum=f(i,d-3)+f(i+1,d);
        else
          if (d%2==1)
            Sum=f(i,d-2)+f(i+1,d+1);
	  else if (d)
            Sum=f(i,d-3)+f(i+1,d);
          else Sum=0;
        return F[i][d]=Sum%base;
}
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		scanf(" %c",&s[i]);
	cout<<f(2,0);


}
