#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
#define fi "encoding.inp"
#define fo "encoding.out"
#define nmax
#define INF 1000000000
using namespace std;
typedef deque<string> DS;
//VARIABLES
int n,t;
DS deq[2];
DS::iterator it;
//MAIN
int main()
{
//       freopen(fi,"r",stdin);
//       freopen(fo,"w",stdout);
       scanf("%d",&n);
       deq[0].push_back("0");
       deq[0].push_back("1");
       for (int i=3;i<=n;++i)
       {
		if (deq[t].empty()) t=1-t;
		deq[1-t].push_front(deq[t].back()+"1");
		deq[1-t].push_front(deq[t].back()+"0");
		deq[t].pop_back();
	}
	for (it=deq[t].begin();it!=deq[t].end();++it) printf("%s\n",it->c_str());
	for (it=deq[1-t].begin();it!=deq[1-t].end();++it) printf("%s\n",it->c_str());
       return 0;
}
