//Code by Patcas Csaba
//Time complexity:
//Space complexity:
//Method:
//Implementation time: 1 hour + 18:05

#include <vector>
#include <string> 
#include <set> 
#include <map> 
#include <queue> 
#include <bitset> 
#include <stack>
#include <list>

#include <numeric> 
#include <algorithm> 

#include <cstdio>
#include <fstream>
#include <iostream> 
#include <sstream> 
#include <iomanip>

#include <cctype>
#include <cmath> 
#include <ctime>
#include <cassert>

using namespace std;

#define LL long long
#define PII pair <int, int>
#define VB vector <bool>
#define VI vector <int>
#define VD vector <double>
#define VS vector <string>
#define VPII vector <pair <int, int> >
#define VVI vector < VI >
#define VVB vector < VB >

#define FORN(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORI(it, X) for(__typeof((X).begin()) it = (X).begin(); it !=(X).end(); ++it) 
#define REPEAT do{ 
#define UNTIL(x) }while(!(x)); 

#define SZ size()
#define BG begin() 
#define EN end() 
#define CL clear()
#define X first
#define Y second
#define RS resize
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()

#define IN_FILE "cuiburi.in"
#define OUT_FILE "cuiburi.out"
#define ZERO 0.0000000000001

ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);

struct TRect
{
	int x1, y1, x2, y2;
};

struct TCirc
{
	int x, y, r;
};


int n, n1, n2;
vector <TRect> rectangles;
vector <TCirc> circles;
VVB g;
VI dp, order, pos;
VB was;
VVI g2;
stack <int> ss;

inline double Dist(int x1, int y1, int x2, int y2)
{
	return sqrt(double(x1 - x2)* (x1 - x2) + (y1 - y2)* (y1 - y2));
}

void BuildGraph()
{
	n1 = rectangles.SZ, n2 = circles.SZ;
	g.RS(n + 1, VB(n + 1));
	FORN(i, n1)
		FORN(j, n1)
			if (i != j &&
				rectangles[i].x1 <= rectangles[j].x1 &&
				rectangles[i].y1 <= rectangles[j].y1 &&
				rectangles[i].x2 >= rectangles[j].x2 &&
				rectangles[i].y2 >= rectangles[j].y2) g[i + 1][j + 1] = true;
	FORN(i, n1)
		FORN(j, n2)
		{
			if (circles[j].x <= rectangles[i].x1 ||
				circles[j].x >= rectangles[i].x2 ||
				circles[j].y <= rectangles[i].y1 ||
				circles[j].y >= rectangles[i].y2) continue;
			if (circles[j].x - rectangles[i].x1 < circles[j].r ||
				circles[j].y - rectangles[i].y1 < circles[j].r ||
				rectangles[i].x2 - circles[j].x < circles[j].r ||
				rectangles[i].y2 - circles[j].y < circles[j].r) continue;
			g[i + 1][j + n1 + 1] = true;
		}
	FORN(i, n2)
		FORN(j, n1)
		{
			if (Dist(circles[i].x, circles[i].y, rectangles[j].x1, rectangles[j].y1) > circles[i].r - ZERO ||
				Dist(circles[i].x, circles[i].y, rectangles[j].x2, rectangles[j].y1) > circles[i].r - ZERO ||
				Dist(circles[i].x, circles[i].y, rectangles[j].x1, rectangles[j].y2) > circles[i].r - ZERO ||
				Dist(circles[i].x, circles[i].y, rectangles[j].x2, rectangles[j].y2) > circles[i].r - ZERO) continue;
			g[i + n1 + 1][j + 1] = true;
		}
   FORN(i, n2)
	   FORN(j, n2)
		if (i != j &&
			Dist(circles[i].x, circles[i].y, circles[j].x, circles[j].y) + circles[j].r < circles[i].r + ZERO) 
				g[i + n1 + 1][j + n1 + 1] = true;
}

void Df(int node)
{
	if (was[node]) return;
	was[node] = true;
	FORN(i, g2[node].SZ) Df(g2[node][i]);
	ss.push(node);
}

int Solve()
{
	int ans = 0;
	g2.RS(n + 1);
	FOR(i, 1, n)
		FOR(j, 1, n)
			if (g[i][j]) g2[i].PB(j);

	was.RS(n + 1);
	FOR(i, 1, n)
		if (!was[i]) Df(i);
	order.RS(n + 1), pos.RS(n + 1);
	FOR(i, 1, n)
	{
		int aux = ss.top();
		order[i] = aux;
		pos[aux] = i;
		ss.pop();
	}
	dp.RS(n + 1);
	for(int i = n; i >= 1; --i)
	{
		dp[i] = 1;
		int node = order[i];
		FORN(j, g2[node].SZ)
		{
			int aux = g2[node][j];
			if (pos[aux] > i) dp[i] = max(dp[i], dp[pos[aux]] + 1);
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	//Read data
	fin >> n;
	FORN(i, n)
	{
		int tip;
		fin >> tip;
		if (tip)
		{
			TCirc aux;
			fin >> aux.x >> aux.y >> aux.r;
			circles.PB(aux);
		}
		else
		{
			TRect aux;
			fin >> aux.x1 >> aux.y1 >> aux.x2 >> aux.y2;
			rectangles.PB(aux);
		}
	}
	fin.close();

	//Solve
	BuildGraph();

	//Write data
	fout << Solve();
	fout.close();

	return 0;
}