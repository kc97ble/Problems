#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <complex>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

typedef complex<double> pnt;

struct line{
	double a, b, c;
	line(double x=0, double y=0, double z=0){
		a=x; b=y; c=z;
	}
};

void MAIN(){
	double a, b, c, x, y;
	cout.precision(3);
	while(cin >> a >> b >> c >> x >> y){
		pnt res = pnt(x, y) - (a*x+b*y-c)/(a*a+b*b)*pnt(a, b);
		cout << fixed << res.real()+1e-9 << ' ' << res.imag()+1e-9 << '\n';
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
	//freopen("input.in", "r", stdin);
	ios::sync_with_stdio(false);
	MAIN();
}
