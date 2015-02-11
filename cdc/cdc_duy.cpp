#include<stdio.h>
#include<math.h>
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
double a,b,c,x,y;
main(){
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    while(scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&x,&y)!=EOF){
        double div = sqrt(a*a + b*b);
        a/=div;
        b/=div;
        c/=div;
        double h = a*x + b*y - c;
        x-=(h*a);
        y-=(h*b);
        printf("%.3lf %.3lf\n",x,y);
    }
   // freopen("test.inp","r",stdin);

}

