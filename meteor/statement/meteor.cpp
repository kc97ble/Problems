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

#define MAX 1005
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
int a[MAX][MAX];
int trace[MAX];
int n,t;
//------------------------------------------------------------------------------
queue<ii> q;
int b[MAX][MAX];
void bfs()
{
    ii k;
    int x,y;
    t=-1;
    b[0][0]=1;
    q.push(ii(0,0));
    while(!q.empty())
    {
        k=q.front();q.pop();   
        x=k.first;y=k.second;
        if(a[x][y] == 0) {t=b[x][y]-1;break;}
        if((a[x+1][y] > b[x][y]+1 || a[x+1][y] == 0) && (b[x+1][y] == 0) && (x+1 >= 0) && (y >= 0)) {b[x+1][y]=b[x][y]+1;q.push(ii(x+1,y));}
        if((a[x-1][y] > b[x][y]+1 || a[x-1][y] == 0) && (b[x-1][y] == 0) && (x-1 >= 0) && (y >= 0)) {b[x-1][y]=b[x][y]+1;q.push(ii(x-1,y));}
        if((a[x][y+1] > b[x][y]+1 || a[x][y+1] == 0) && (b[x][y+1] == 0) && (x >= 0) && (y+1 >= 0)) {b[x][y+1]=b[x][y]+1;q.push(ii(x,y+1));}
        if((a[x][y-1] > b[x][y]+1 || a[x][y-1] == 0) && (b[x][y-1] == 0) && (x >= 0) && (y-1 >= 0)) {b[x][y-1]=b[x][y]+1;q.push(ii(x,y-1));}
    }
}
//------------------------------------------------------------------------------
int main()
{
    int i,x,y,d;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d", &n);
    for(i=1;i<=n;i++) 
    {
        scanf("%d %d %d", &x, &y, &d);
        if(a[x][y] == 0) a[x][y]=d+1;
        if((a[x+1][y] == 0)&& (x+1 >= 0) && (y >= 0)) a[x+1][y]=d+1;
        if((a[x-1][y] == 0)&& (x-1 >= 0) && (y >= 0)) a[x-1][y]=d+1;
        if((a[x][y+1] == 0)&& (x >= 0) && (y+1 >= 0)) a[x][y+1]=d+1;
        if((a[x][y-1] == 0)&& (x >= 0) && (y-1 >= 0)) a[x][y-1]=d+1;
    }
    bfs();
    printf("%d\n", t);
    return 0;
}
