#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<math.h>
#define X first
#define Y second
using namespace std;
typedef pair<double,double> p;
typedef pair<p,double> line;
line makeline(p a,p b)
{
	line x;
	x.X.X=-(a.Y-b.Y);
	x.X.Y=a.X-b.X;
	x.Y=(x.X.X*a.X+x.X.Y*a.Y);
	return x;
}
p giao(line a,line b)
{
	double a1,a2,b1,b2,c1,c2;
	a1=a.X.X;
	b1=a.X.Y;
	c1=a.Y;
	a2=b.X.X;
	b2=b.X.Y;
	c2=b.Y;
	return p((c1*b2-c2*b1)/(a1*b2-a2*b1),(a1*c2-a2*c1)/(a1*b2-a2*b1));
}
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);
	p a,b,c,d,e;
	line n,m;
	while(cin>>a.X>>a.Y>>b.X>>b.Y>>c.X>>c.Y>>d.X>>d.Y)
	{
	n=makeline(a,b);
	m=makeline(c,d);
	e=giao(n,m);
	printf("%.3lf %.3lf\n",e.X,e.Y);
	}
	
	
}

