#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#define MAX 100005
using namespace std;
deque<int> dq;
int n,k,p;
int sv[MAX];
//------------------------------------------------------------------------------
void quicksort(int l,int r)
{
     if(l>=r) return;
     int i=l;
     int j=r;
     int x=sv[(l+r)/2];
     while(i<=j)
     {
                while(sv[i]<x) i++;
                while(sv[j]>x) j--;
                if(i<=j)
                {
                        int temp=sv[i];
                        sv[i]=sv[j];
                        sv[j]=temp;
                        i++;j--;
                }
     }
     quicksort(l,j);
     quicksort(i,r);
}
//------------------------------------------------------------------------------
int main()
{
    int i,d,cnt,m;
    scanf("%d %d %d", &n , &k, &p);
    d=0;cnt=0;
    for(i=1;i<=k;i++){dq.push_back(i);}
    while(!dq.empty())
    {
        d++;
        if(d%3 == 0){sv[++cnt]=dq.front();}
        dq.pop_front();
        for(i=1;i<=p;i++){m=dq.front();dq.pop_front();dq.push_back(m);}
    }
    quicksort(1,cnt);
    for(i=1;i<=n;i++)printf("%d\n", sv[i]);
    return 0;
}
