/*---------------------------------------------------------------------------------------------------------------------------------------*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <limits>
#include <string>
#include <locale>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define finp freopen("lol.txt", "r", stdin)
#define fout freopen("lolout.txt", "w", stdout)
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define ROF(i, a, b) for(int a= (a); i>=(b); i--)
#define fi first
#define se second
#define INF 10000000
#define sqr(x) ((x)*(x))
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ii, int> iii;
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
int n, m;
int w[10000],d[10000];
int f[10000][13000];
void input()
{
     scanf("%d%d", &n, &m);
     FOR(i, 1, n) scanf("%d%d", &w[i], &d[i]);
}
void process()
{
     FOR(i, 1, n) 
     {
            f[i][0]=0;
     }
     FOR (i, 1, n)
         FOR (j, 0, m)
         {
             f[i][j]=f[i-1][j];
             if (w[i] <= j && f[i][j]<d[i]+f[i-1][j-w[i]])f[i][j]=d[i]+f[i-1][j-w[i]];
         }  
     printf("%d", f[n][m]);
}
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int main ()
{
    //finp;
    //fout;
    input();
    process();
    return 0;
}
