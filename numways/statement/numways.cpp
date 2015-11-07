#include<cstdio>
#include<vector>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define IN(x,y) (((x)-1)*n+(y))
#define OUT(x,y) (IN(x,y)+m*n)
using namespace std;
const int INF=(int)1e9+7;
class DinicFlow {
private:
    vector<int> dist,head,q,work;
    vector<int> point,capa,flow,next;
    int n,m;
public:
    DinicFlow() {
        n=0;m=0;
    }
    DinicFlow(int n) {
        this->n=n;m=0;
        dist.assign(n+7,0);
        head.assign(n+7,-1);
        q.assign(n+7,0);
        work.assign(n+7,0);
    }
    void addEdge(int u,int v,int c1,int c2) {
        //printf("Add %d %d %d %d\n",u,v,c1,c2);
        point.push_back(v);capa.push_back(c1);flow.push_back(0);next.push_back(head[u]);head[u]=m++;
        point.push_back(u);capa.push_back(c2);flow.push_back(0);next.push_back(head[v]);head[v]=m++;
    }
    bool bfs(int s,int t) {
        FOR(i,1,n) dist[i]=-1;
        int sz=0;
        q[sz++]=s;dist[s]=0;
        for (int x=0;x<sz;x=x+1) {
            int u=q[x];
            for (int i=head[u];i>=0;i=next[i])
                if (dist[point[i]]<0 && flow[i]<capa[i]) {
                    dist[point[i]]=dist[u]+1;
                    q[sz++]=point[i];
                }
        }
        return (dist[t]>=0);
    }
    int dfs(int s,int t,int f) {
        if (s==t) return (f);
        for (int &i=work[s];i>=0;i=next[i])
            if (dist[point[i]]==dist[s]+1 && flow[i]<capa[i]) {
                int d=dfs(point[i],t,min(f,capa[i]-flow[i]));
                if (d>0) {
                    flow[i]+=d;
                    flow[i^1]-=d;
                    return (d);
                }
            }
        return (0);
    }
    int maxFlow(int s,int t) {
        int totflow=0;
        while (bfs(s,t)) {
            FOR(i,1,n) work[i]=head[i];
            while (true) {
                int d=dfs(s,t,INF);
                if (d<=0) break;
                totflow+=d;
            }
        }
        return (totflow);
    }
};
int m,n;
void process(void) {
    scanf("%d%d",&m,&n);
    DinicFlow df(2*m*n+2);
    int src=2*m*n+1;
    int snk=2*m*n+2;
    FOR(j,1,n-1) FOR(i,1,m) {
        int t;
        scanf("%d",&t);
        REP(love,t) {
            int k;
            scanf("%d",&k);
            df.addEdge(OUT(i,j),IN(k,j+1),INF,0);
        }
    }
    FOR(i,1,m) FOR(j,1,n) df.addEdge(IN(i,j),OUT(i,j),1,0);
    FOR(i,1,m) df.addEdge(src,IN(i,1),INF,0);
    FOR(i,1,m) df.addEdge(OUT(i,n),snk,INF,0);
    printf("%d\n",df.maxFlow(src,snk));
}
int main(void) {
#ifndef SKY
    freopen("numways.inp","r",stdin);
    freopen("numways.out","w",stdout);
#endif // SKY
    process();
    return 0;
}
