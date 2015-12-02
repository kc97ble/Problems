#include"testlib.h"
#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],b[MAX],n;
bool usedA[MAX],usedB[MAX];
void init(void) {
    n=inf.readInt();
    FOR(i,1,n) a[i]=inf.readInt();
    FOR(i,1,n) b[i]=inf.readInt();
}
void check(void) {
    int cnt=0;
    REP(love,n) {
        int x=ouf.readInt(1,n);
        int y=ouf.readInt(1,n);
        if (usedA[x]) quitf(_wa,"Horse #%d of team A has been used before",x);
        if (usedB[y]) quitf(_wa,"Horse #%d of team B has been used before",y);
        usedA[x]=usedB[y]=true;
        if (a[x]>b[y]) cnt++;
        if (a[x]<b[y]) cnt--;
    }
    int exp=ans.readInt();
    if (cnt<exp) quitf(_wa,"Jury has better answer: %d - %d",exp,cnt);
    if (cnt>exp) quitf(_fail,"Jury has worse answer: %d - %d",exp,cnt);
    if (cnt==exp) quitf(_ok,"Answer is %d",exp);
}
int main(int c,char** v) {
    registerTestlibCmd(c,v);
    init();
    check();
    return 0;
}
