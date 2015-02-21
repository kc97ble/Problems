#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<set>
#define oo 1000000000
#define base 1000000007
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
//Buffer reading
int INP,AM;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
if(!*inp) { \
    if (feof(stdin)) memset(BUF, 0, sizeof BUF); else fread(BUF,1,BUFSIZE,stdin); \
    inp=BUF; \
} \
INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
AM=0;\
GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
if (INP=='-') {AM=1;GETCHAR(INP);} \
j=INP-'0'; GETCHAR(INP); \
while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
if (AM) j=-j;\
}
//End of buffer reading
                            /*                           END OF TEMPLATE                            */
// VOI 2013
// IOI 2014

vector<vii> G;
vi par,child,up;
vector<ll> f,g;
int c[100005],V;
long long ans;
void Set()
{
    G.assign(V,vii());
    par.assign(V,-1);
    child.assign(V,0);
    up.assign(V,0);
    f.assign(V,0);
    g.assign(V,0);
}

void dfs(int u)
{
    child[u]=c[u];
    for(int i=0; i<G[u].size(); i++)
    {
        ii v=G[u][i];
        if(v.first!=par[u])
        {
            par[v.first]=u;
            up[v.first]=v.second;
            dfs(v.first);
            child[u]+=child[v.first];
            f[u]+=f[v.first]+ll(child[v.first]*v.second);
        }
    }
}

void cal(int u)
{
    if(u!=0)
    {
        int v=par[u];
        g[u]=f[u]+g[v]-f[u]-ll(child[u]*up[u])+ll((child[0]-child[u])*up[u]);
    }
    for(int i=0; i<G[u].size(); i++)
    {
        ii v=G[u][i];
        if(v.first!=par[u]) cal(v.first);
    }
}

int main()
{
    //freopen("gather.inp","r",stdin);
    //freopen("gather.out","w",stdout);
    int i,a,b,w;
    scanf("%d",&V);
    Set();
    for(i=0; i<V; i++) scanf("%d",&c[i]);
    for(i=1; i<V; i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        a--; b--;
        G[a].push_back(ii(b,w));
        G[b].push_back(ii(a,w));
    }
    dfs(0);
    g[0]=f[0];
    cal(0);
    ans=g[0];
    for(i=0; i<V; i++) ans=min(ans,g[i]);
    cout<<ans;
    return 0;
}
