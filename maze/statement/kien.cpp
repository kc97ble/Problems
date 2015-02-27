#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
#define each(i,a) (__typeof(a.begin()) i=a.begin(); i!=a.end(); i++)
typedef pair<int, int> ii;
typedef pair<int, ii> triple;
#define X first
#define Y second

#define N 52
const int oo = 23092309;

int m, n;
char a[N][N];
int D1[N][N], D2[N][N], D[N][N];
vector<ii> List[256];

int rx[]={-1,0,1,0};
int ry[]={0,1,0,-1};

bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }

void dijkstra(int d[N][N]) {
	priority_queue<triple> qu;
	f1(i,m) f1(j,n) if (a[i][j]!='#')
	qu.push(triple(-d[i][j], ii(i, j)));

	while (qu.size()) {
		triple Top=qu.top(); qu.pop();
		int du=-Top.X, x=Top.Y.X, y=Top.Y.Y;
		if (d[x][y]!=du) continue;

		f0(i,4) {
			int xx=x+rx[i], yy=y+ry[i];
			if (a[xx][yy]!='#' && a[xx][yy]!=0)
			if (minimize(d[xx][yy], d[x][y]+1))
			qu.push(triple(-d[xx][yy], ii(xx, yy)));
		}
	}
}

main(){
	scanf("%d%d", &m, &n);
	f1(i,m) scanf("%s", a[i]+1);
	f1(i,m) f1(j,n) List[a[i][j]].push_back(ii(i,j));

	long Sum = 0, Count = 0;
	for each(it, List['R'])
	for each(jt, List['F']) {
		f1(i,m) f1(j,n) D1[i][j]=D2[i][j]=oo;
		D1[it->X][it->Y]=0; dijkstra(D1);
		D2[jt->X][jt->Y]=0; dijkstra(D2);
		f1(i,m) f1(j,n) D[i][j]=D1[i][j]+D2[i][j]; dijkstra(D);

		for each(kt, List['L']) {
			int X = D[kt->X][kt->Y];
			if (X<oo) { Sum += X; Count++; }
			else { cout << "none" << endl; return 0; }
		}
	}
	long GCD=__gcd(Sum, Count);
	Sum/=GCD, Count/=GCD;
	cout << Sum << "/" << Count << endl;
}
