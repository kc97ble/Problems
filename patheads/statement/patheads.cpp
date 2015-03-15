#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define fi first
#define se second
#define MAX 1000005
#define INF 1000000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int a[MAX],p[MAX],u[MAX];
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int main()
{
    int n,i,j,max=0;
    memset(p,0,sizeof(p));
    memset(u,0,sizeof(u));
    scanf("%d", &n);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);p[a[i]]++;if(a[i] > max) max=a[i];}
    u[1]=p[1];
    for(i=2;i<=max;i++)
    {
        for(j=1;j<=1+(i/2);j++)
        if(i % j == 0)  u[i]+=p[j];
        u[i]+=p[i];
    }
    for(i=1;i<=n;i++) printf("%d\n", u[a[i]]-1);
    return 0;
}

