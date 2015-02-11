#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,i,j;
long long K,pa,sum;
int a[200000];
int main(){
//    freopen("ljutnja.in","r",stdin);
//    freopen("ljutnja.out","w",stdout);
    cin>>K>>n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        K-=a[i];
    }
    K=-K;
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        
        if(sum + (long long)(n-i)*a[i] >= K)
        {
            for(j=0;j<i;j++)
                pa+=(long long)a[j]*a[j];
            for(j=i;j<n;j++)
            {
                pa+=(long long)((K-sum)/(n-j)) * ((K-sum)/(n-j));
                sum+=(K-sum)/(n-j);
            }
            cout<<pa;
            return 0;
        }
        sum += a[i];
    }
    return 0;
}
