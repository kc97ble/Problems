#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-10+2e-11;
pair<double,double> range[MAX];
pair<double,int> point[MAX*2];
int numSta[MAX*2],posSta[MAX],posEnd[MAX];
int n,rad;
void init(void) {
    scanf("%d%d",&n,&rad);
    FOR(i,1,n) {
        int x,y;
        scanf("%d%d",&x,&y);
        double dis=sqrt(1LL*x*x+1LL*y*y);
        double delta=acos(rad/dis);
        double angle=atan2(y,x);
        range[i]=make_pair(angle-delta,angle+delta);
        if (angle+eps<delta) {
            range[i].fi+=2*PI;
            range[i].se+=2*PI;
        }
    }
}
bool CompPoint(const pair<double,int> &a,const pair<double,int> &b) {
    if (a.fi+eps<b.fi) return (true);
    if (b.fi+eps<a.fi) return (false);
    return (a.se<b.se);
}
void process(void) {
    FOR(i,1,n) {
        point[i]=make_pair(range[i].fi,i);
        point[i+n]=make_pair(range[i].se,-i);
    }
    sort(point+1,point+2*n+1,CompPoint);
    FOR(i,1,2*n) numSta[i]=numSta[i-1]+(point[i].se>0);
    FOR(i,1,2*n) {
        if (point[i].se>0) posSta[point[i].se]=i;
        else posEnd[-point[i].se]=i;
    }
    long long res=0;
    FOR(i,1,n) res+=numSta[posEnd[i]]-numSta[posSta[i]];
    vector<double> bigEnd;
    FOR(i,1,n) if (range[i].se>=2*PI-eps) bigEnd.push_back(range[i].se);
    sort(ALL(bigEnd));
    int id=1;
    int tmp=0;
    FORE(it,bigEnd) {
        while (id<=2*n && point[id].fi+eps<*it-2*PI) {
            if (point[id].se>0) tmp++;
            id++;
        }
        res+=tmp;
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}
