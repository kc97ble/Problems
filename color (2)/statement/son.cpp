#include<cstdio>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<map>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,m;
int base=1000000007;
int F[301][301][301];
bool g[301][301][301];
int f(int i,int d,int k)
{
	if (i==n+1) if (d==0 and k==0) return 1;
	else return 0;
	if (k<0 or d<0 or d>m) return 0;
	if (g[i][d][k]++) return F[i][d][k];
	if (d==0) return F[i][d][k]=(0LL+f(i+1,d,k-1)+f(i+1,d+1,k-1)+f(i+1,d-1,k))%base;
	if (d==m) return F[i][d][k]=(f(i+1,d,k)+f(i+1,d-1,k))%base;
	return F[i][d][k]=(0LL+f(i+1,d,k)+f(i+1,d,k-1)+f(i+1,d+1,k-1)+f(i+1,d-1,k))%base;
}
int main()
{
	int k;
	cin>>n>>m>>k;
	long long s=1;
	for(int i=1;i<=k;i++) s=(1ll*s*i)%base;
	cout<<(s*f(1,0,k))%base;


}
