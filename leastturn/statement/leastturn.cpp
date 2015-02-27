#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 100000000
#define MAX 1005
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;
ii start,target;
int grid[MAX][MAX],n,m;
int dist[MAX][MAX][10];
long long X0,Y0,A,B,C,D,P;
void Dijkstra()
{
     int i,j;
     for(i=0; i<n; i++)
              for(j=0; j<n; j++) dist[i][j][1]=dist[i][j][2]=INF;
     dist[start.first][start.second][1]=dist[start.first][start.second][2]=0;
     priority_queue<iiii,vector<iiii>,greater<iiii> > q; q.push(iiii(ii(0,1),start)); q.push(iiii(ii(0,2),start));
     while(!q.empty())
     {
                  iiii x=q.top(); q.pop();
                  int d=x.first.first,dir=x.first.second,cx=x.second.first,cy=x.second.second;
                  for(i=1; i<=4; i++)
                  {
                           int a=cx,b=cy;
                           if(i==1) a++; if(i==2) a--;
                           if(i==3) b++; if(i==4) b--;
                           if(a>=0 && b>=0 && a<n && b<n && grid[a][b])
                           {
                                   if(i<=2) // dir=1
                                   {
                                            if(dir==1)
                                            {
                                            if(dist[a][b][1]>dist[cx][cy][1])
                                            {
                                                      dist[a][b][1]=dist[cx][cy][1];
                                                      q.push(iiii(ii(dist[a][b][1],1),ii(a,b)));
                                            }
                                            }
                                            if(dir==2)
                                            {
                                            if(dist[a][b][1]>dist[cx][cy][2]+1)
                                            {
                                                      dist[a][b][1]=dist[cx][cy][2]+1;
                                                      q.push(iiii(ii(dist[a][b][1],1),ii(a,b)));
                                            }
                                            }
                                   }
                                   else //dir=2
                                   {
                                            if(dir==1)
                                            {
                                            if(dist[a][b][2]>dist[cx][cy][1]+1)
                                            {
                                                      dist[a][b][2]=dist[cx][cy][1]+1;
                                                      q.push(iiii(ii(dist[a][b][1],2),ii(a,b)));
                                            }
                                            }
                                            if(dir==2)
                                            {
                                            if(dist[a][b][2]>dist[cx][cy][2])
                                            {
                                                      dist[a][b][2]=dist[cx][cy][2];
                                                      q.push(iiii(ii(dist[a][b][2],2),ii(a,b)));
                                            }
                                            }
                                   }
                           }
                  }
     }
     int k=min(dist[target.first][target.second][1],dist[target.first][target.second][2]);
     if(k==INF) printf("-1");
     else printf("%d",k);
}
void create_matrix()
{
     int i;
     long long cc1,cc2;
     long long x,y,a,b;
     cc1=x=X0%P;
     cc2=y=Y0%P;
     a=x%n; b=y%n;
     if((a!=0 || b!=0) && (a!=n-1 || b!=n-1)) grid[a][b]=0;
     for(i=1; i<=m; i++)
     {
                  x=((x*A)%P+B)%P;
                  y=((y*C)%P+D)%P;
                  if(x==cc1 && y==cc2) return;
                  a=x%n; b=y%n;
                  if((a!=0 || b!=0) && (a!=n-1 || b!=n-1)) grid[a][b]=0;
     }
}
int main()
{
    //freopen("leastturn.inp","r",stdin);
    //freopen("leastturn.out","w",stdout);
    int i,j,k;
    cin>>n>>X0>>A>>B>>Y0>>C>>D>>P>>m;
    A%=P; B%=P;C%=P; D%=P;
    for(i=0; i<n; i++)
             for(j=0; j<n; j++) grid[i][j]=1;
    create_matrix();
    start=ii(0,0);
    target=ii(n-1,n-1);
    Dijkstra();
    return 0;
}
