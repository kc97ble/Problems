#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#define fi first
#define nd second
#define mp make_pair
using namespace std;
int N;
multiset<int> SET;
vector<pair<int,int> > job;
void input(){
    scanf("%d\n",&N);
    int a,b;
    job.push_back(mp(0,0));
    for(int i=0;i<N;i++){
        scanf("%d %d\n",&a,&b);
        job.push_back(mp(a,b));
    }
    sort(job.begin(),job.end());
}
void solve(){
    int pre;
    int i=N,j;
    long long ans=0;
    while(i>=1){
        j=i;
        while (job[i].fi==job[j-1].fi) j--;
        for(int k=j;k<=i;k++) SET.insert(-job[k].nd);
        for(int k=1;k<=min(job[i].fi-job[j-1].fi,int(SET.size()));k++) {
            ans+=(-(*SET.begin()));
            SET.erase(SET.begin());
            if (SET.size()==0) break;
        }
        i=j-1;
        //cout<<ans<<endl;
    }
    cout<<ans;
}
int main(){
//    freopen("job.inp","r",stdin);freopen("job.out","w",stdout);
    input();
    solve();
}
