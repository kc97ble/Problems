#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxN=100000+10;
typedef long long llint;
typedef pair<int,int> II;
typedef pair<llint,int> LI;
#define PB push_back
#define MP make_pair
#define fs first
#define sd second
#define FORE(it,c) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
#define FORR(it,c) for(typeof(c.rbegin())it=c.rbegin();it!=c.rend();it++)

int n,c[maxN],tr[maxN];
vector<II> a[maxN];
LI f[maxN],fe[maxN];
llint res;

void add(LI &a,LI b,int c){
    a.fs+=b.fs+1LL*b.sd*c;
    a.sd+=b.sd;
}

void visit(int u){
    FORE (it,a[u]) if (tr[it->fs]!=0){
        *it=a[u].back(); a[u].pop_back(); break;
    }
    LI F=MP(0,0);
    FORE (it,a[u]){
        tr[it->fs]=u;
        visit(it->fs);
        fe[it->fs]=F;
        add(F,f[it->fs],it->sd);
    }
    f[u]=F; f[u].sd+=c[u];
    F=MP(0,0);
    FORR (it,a[u]){
        fe[it->fs].fs+=F.fs;
        fe[it->fs].sd+=F.sd;
        add(F,f[it->fs],it->sd);
    }    
}

void revisit(int u,LI F){
    //printf("visit %d:%lld,%d;%lld,%d\n",u,f[u].fs,f[u].sd,fe[u].fs,fe[u].sd);
    res=min(res,f[u].fs+F.fs);    
    LI G;
    FORE (it,a[u]){
        G=MP(F.fs+fe[it->fs].fs,F.sd+fe[it->fs].sd+c[u]);
        G.fs+=1LL*G.sd*it->sd;
        revisit(it->fs,G);
    }
}

int main(){
    //freopen("gather.inp","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    int u,v,c;
    for (int i=0;i<n-1;i++){
        scanf("%d%d%d",&u,&v,&c);
        a[u].PB(MP(v,c)); a[v].PB(MP(u,c));
    }
    memset(tr,0,sizeof tr); tr[1]=-1; fe[1]=MP(0,0);
    visit(1);
    res=f[1].fs;
    revisit(1,MP(0,0));
    printf("%lld\n",res);
    return 0;
}
