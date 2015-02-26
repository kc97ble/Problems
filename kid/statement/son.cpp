#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> ii;
map <int,int> par,d;
set <ii> se;
set <ii>::iterator it;
int anc(int u)
{
	if (par[u]==u) return u;
	else return par[u]=anc(par[u]);
}
void join(int u,int v){	par[anc(u)]=anc(v); }

int main()
{
	int n,m,s,u,v;
	for(;;){
	scanf("%d%d",&n,&m);
	if (n==0 and m==0) return 0;
	s=0;
	se.clear();
	while(m--)
	{
		scanf("%d%d",&u,&v);
		par[u]=u;
		par[v]=v;
		if (u>v) swap(u,v);
		se.insert(ii(u,v));
		d[u]=0;
		d[v]=0;
	}
	bool q=false;
	for(it=se.begin();it!=se.end();it++)
	{
		u=it->first;
		v=it->second;
		if (d[u]==0) s++;
		if (d[v]==0) s++;
		d[v]+=1;
		d[u]+=1;
		if (d[u]>=3 or d[v]>=3) {printf("N\n");q=true;break;}
		if (anc(u)==anc(v) and s<n) {printf("N\n");q=true;break;}
		join(u,v);
	}
	if (q==false) printf("Y\n");
	}
}
