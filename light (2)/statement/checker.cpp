#include"testlib.h"
#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int m,n,k;
bool mark[MAX][MAX];
bool usedRow[MAX],usedCol[MAX];
int costRow[MAX],costCol[MAX];
void init(void) {
    m=inf.readInt();
    n=inf.readInt();
    k=inf.readInt();
    FOR(i,1,m) costRow[i]=inf.readInt();
    FOR(i,1,n) costCol[i]=inf.readInt();
    REP(love,k) {
        int x=inf.readInt(1,m,"row");
        int y=inf.readInt(1,n,"col");
        mark[x][y]=true;
    }
}
int checkAnswer(InStream &stream) {
    memset(usedRow,0,sizeof usedRow);
    memset(usedCol,0,sizeof usedCol);
    int expCost=stream.readInt();
    int nRow=stream.readInt();
    int nCol=stream.readInt();
    int sum=0;
    REP(love,nRow) {
        int x=stream.readInt(1,m,"row");
        usedRow[x]=true;
        sum+=costRow[x];
    }
    REP(love,nCol) {
        int y=stream.readInt(1,n,"col");
        usedCol[y]=true;
        sum+=costCol[y];
    }
    if (sum!=expCost) stream.quitf(_wa,"Printed cost (%d) doesn't equal to method's cost (%d)",expCost,sum);
    FOR(i,1,m) FOR(j,1,n) if (mark[i][j] && !usedRow[i] && !usedCol[j])
        stream.quitf(_wa,"Cell (%d,%d) hasn't been covered",i,j);
    return (sum);
}
void process(void) {
    int exp=checkAnswer(ans);
    int res=checkAnswer(ouf);
    if (res>exp) quitf(_wa,"Jury has better answer (%d<%d)",exp,res);
    if (exp==res) quitf(_ok,"Optimal answer is %d",res);
    if (res<exp) quitf(_fail,"Jury has worse answer(%d>%d)",exp,res);
}
int main(int c,char **v) {
    registerTestlibCmd(c,v);
    init();
    process();
    return 0;
}
