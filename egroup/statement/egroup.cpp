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

#define MAX 1000005
#define INF 10000000
using namespace std;
int a[MAX],m[MAX];
int n;
//------------------------------------------------------------------------------
int be(int a,int b)
{
    if(a <= b) return a;
    return b;
}
int inc()
{
    int i,j,jmax,max=0;
    a[0]=0;a[n+1]=INF;
    m[n+1]=1;
    for(i=n;i>=0;i--)
    {
        jmax=n+1;
        for(j=i+1;j<=n+1;j++)
        if((a[j] >= a[i]) && (m[j] > m[jmax])) jmax=j;
        m[i]=m[jmax]+1;
    }
    for(i=1;i<=n;i++){if(max < m[i]-1) max=m[i]-1;}
    return max;
}
int dec()
{
    int i,j,jmax,max=0;
    a[0]=0;a[n+1]=INF;
    m[n+1]=1;
    for(i=0;i<=n;i++)
    {
        jmax=n+1;
        for(j=i+1;j>=0;j--)
        if((a[j] >= a[i]) && (m[j] > m[jmax])) jmax=j;
        m[i]=m[jmax]+1;
    }
    for(i=1;i<=n;i++){if(max < m[i]-1) max=m[i]-1;}
    return max;
}
//------------------------------------------------------------------------------
int main()
{
    int i,x,y;
    scanf("%d", &n);
    for(i=1;i<=n;i++) scanf("%d", &a[i]);
    printf("%d\n", be(n-inc(),n-dec()));
    return 0;
}
