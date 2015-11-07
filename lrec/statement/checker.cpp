#include"testlib.h"
#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
bool usedRow[MAX][MAX],usedCol[MAX][MAX];
int m,n,q;
void init(void) {
    m=inf.readInt();
    n=inf.readInt();
    q=inf.readInt();
    FOR(i,1,m) FOR(j,1,n) {
        int t=inf.readInt();
        usedRow[i][t]=usedCol[j][t]=true;
    }
}
void process(void) {
    FOR(i,m+1,m+q) {
        FOR(j,1,n) {
            int t=ouf.readInt(1,n,format("a[%d,%d]",i,j).c_str());
            if (usedRow[i][t]) quitf(_wa,"Number %d at row %d appears twice",t,i);
            else usedRow[i][t]=true;
            if (usedCol[j][t]) quitf(_wa,"Number %d at col %d appears twice",t,j);
            else usedCol[j][t]=true;
        }
    }
    quitf(_ok,"%d correct row(s)",q);
}
int main(int c,char** v) {
    registerTestlibCmd(c,v);
    init();
    process();
    return 0;
}
