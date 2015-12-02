#include"testlib.h"
#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
struct Rectangle {
    int x1,y1,x2,y2;
    Rectangle() {
        x1=y1=x2=y2=0;
    }
    Rectangle(int _x1,int _y1,int _x2,int _y2) {
        x1=_x1;y1=_y1;x2=_x2;y2=_y2;
    }
    void input(void) {
        x1=inf.readInt();
        y1=inf.readInt();
        x2=inf.readInt();
        y2=inf.readInt();
        if (x1>x2) swap(x1,x2);
        if (y1>y2) swap(y1,y2);
    }
    bool intersect(const Rectangle &r) const {
        return (max(x1,r.x1)<=min(x2,r.x2) && max(y1,r.y1)<=min(y2,r.y2));
    }
};
int n,m,s;
Rectangle rec[MAX];
void init(void) {
    n=inf.readInt();
    m=inf.readInt();
    s=inf.readInt();
    FOR(i,1,m) rec[i].input();
}
void process(void) {
    int res=ouf.readInt();
    int exp=ans.readInt();
    int cnt=0;
    int x=ouf.readInt();
    int y=ouf.readInt();
    if (x<1 || y<1 || x+s-1>n || y+s-1>n) quitf(_wa,"The stamp is outside the table");
    Rectangle stamp(x,y,x+s-1,y+s-1);
    FOR(i,1,m) if (rec[i].intersect(stamp)) cnt++;
    if (cnt!=res) quitf(_wa,"Result doesn't correspond to the chosen stamp");
    if (cnt<exp) quitf(_wa,"Jury has better answer: %d - %d",cnt,exp);
    if (cnt>exp) quitf(_fail,"Jury has worse answer: %d - %d",cnt,exp);
    if (cnt==exp) quitf(_ok,"Best result is %d",cnt);
}
int main(int c,char** v) {
    registerTestlibCmd(c,v);
    init();
    process();
    return 0;
}
