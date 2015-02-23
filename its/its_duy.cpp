#include<stdio.h>
using namespace std;
struct point{
    double x,y;
    void read(){
        scanf("%lf %lf",&x,&y);
    }
};
struct line{
    double a,b,c;
    void make_line(point A,point B){
        double u = B.x - A.x;
        double v = B.y - A.y;
        a = -v;
        b =  u;
        c = a*A.x + b*A.y;
    }
};
point cut(line X,line Y){
    point p;
    double D = X.a*Y.b - X.b*Y.a;
    double Dx = X.c*Y.b - X.b*Y.c;
    double Dy = X.a*Y.c - X.c*Y.a;
    p.x = Dx/D;
    p.y = Dy/D;
    return p;
}
point A,B,C,D;
main(){
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    while(scanf("%lf %lf",&A.x,&A.y)!=EOF){
        B.read();
        C.read();
        D.read();
        line s1,s2;
        s1.make_line(A,B);
        s2.make_line(C,D);
        printf("%.3lf %.3lf\n",cut(s1,s2));
    }
}

