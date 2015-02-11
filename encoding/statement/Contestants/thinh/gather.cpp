#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <list>
#include <set>
#include <map>

#define FOR(i , a, b)   for(int i = a,_b =b; i <= _b ; i++)
#define FORD(i , a,b)   for(int i = a,_b = b; i >= _b ; i--)
#define REP(i , n)      for(int i = 0,_n = n;  i < _n ; i++)

#define MAX 111111

using namespace std;

typedef vector<int> vi;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef long long ll;

ll f[MAX],g[MAX],child[MAX],c[MAX],p[MAX],total,d[MAX];
int cal;
bool mark[MAX];
int V , in[MAX], out[MAX];
vector<vii> adj;


void dfs(int u)
{
    in[u] = cal++;
    mark[u] = true;
    REP(i , adj[u].size())
    {
        ii v = adj[u][i];
        if(!mark[v.first])
        {
            dfs(v.first);
            child[u] += child[v.first];
            f[u] += f[v.first] + (ll)child[v.first] * v.second; 
        }
    }
    out[u] = cal ++ ;
}

void bfs(int s)
{
    memset(d , -1 ,  sizeof(d));
    memset(g , 0 ,  sizeof(g));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    p[s] = c[s];
    while(!q.empty())
    {
        int u = q.front() ; q.pop();
        REP(i , adj[u].size())
        {
            ii v = adj[u][i];
            if(d [v.first] == -1)
            {
                d[v.first] = d[u] + (ll)v.second;
                p[v.first] = p[u] + c[v.first];
                g[v.first] = g[u] + d[v.first];
                q.push(v.first);
            }
         }
    }
}    

bool in_tree(int u , int v)
{
    return(in[u] <= in[v] && out[v] <= out[u]);
}

void process()
{
    memset(mark , 0 , sizeof(mark));
    FOR(i , 1 , V)
    {
        child[i] = c[i];
        f[i] = 0;
    }
    cal = 0;
    dfs(1);
    bfs(1);
    ll res = f[1];
    
    FOR(i , 2 , V)
    {
        int ances;
        int len;
        REP(j , adj[1].size())
        {
            ii v = adj[1][j];
            if(in_tree(v.first , i))
            {
                ances = v.first;
                len = v.second;
                break;
            }
        }
        
        ll tmp = f[ances];
        tmp += (ll)(total - child[ances]) * d[i];
        
        ll root = p[i];
        root = root * d[i] - g[i];
        res = min(res , tmp + root);
   }
   cout << res << endl; 
}

int main()
{
    int u , v,w;
    total = 0;
    scanf("%d",&V);
    adj.assign(V + 1 , vii());
    FOR(i ,1 , V)
    {
        scanf("%d",&c[i]);
        total += (ll)c[i];
    }
    FOR(i , 1 , V - 1)
    {
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(ii (v , w));
        adj[v].push_back(ii (u , w));
    }
    process();
}
