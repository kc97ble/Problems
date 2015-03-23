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
#define ROF(i, a, b) for(int i= (a); i>=(b); i--)
#define fi first
#define se second
#define INF 10000000
#define MAX_N 100000
#define MAX_H 100
#define sqr(x) ((x)*(x))
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ii, int> iii;
const int HOME = 0;
const int TEST = 0;
/*--------------------------------------------------------------------------------------------------------------------------------------------*/
int n, k;
int h[MAX_N+10], best[2][MAX_H+1], tempup[MAX_H+1], tempdown[MAX_H+1];
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int main ()
{
    if(HOME)
    {
         finp;
         fout;
    }
    int b;
    scanf("%d%d", &n, &k);
    FOR(i, 0, n-1)
    {
           scanf("%d", &h[i]);
    }
    FOR(i, 0, h[0]) best[0][i] = 9999999;
    best[0][h[0]] = 0;
    FOR(i, h[0]+1, MAX_H) best[0][i] = best[0][h[0]] + sqr(i-h[0]);
    FOR(i, 1, n-1)
    {
           FOR(j, 0, h[i]-1) best[i%2][j] = 9999999;
           FOR(j, 0, MAX_H )
           {
                  tempup[j] = best[(i+1)%2][j] + j*k;
                  tempdown[j] = best[(i+1)%2][j] - j*k;
           }
           FOR(j, 1, MAX_H)
           {
                  if (tempdown[j-1] < tempdown[j] ) tempdown[j] = tempdown[j-1]; 
           }
           ROF(j, MAX_H-1, 0)
           {
                  if (tempup[j+1] < tempup[j] ) tempup[j] = tempup[j+1];
           }
           FOR(j, h[i], MAX_H)
           {
                  b = tempup[j] - j*k;
                  if (tempdown[j] + j*k < b ) b = tempdown[j] +j*k;
                  best[i%2][j]= (j-h[i])*(j-h[i]) + b ;
           }
    }
    int min = INF;
    FOR(i, 0, MAX_H)
    {
           if (best[(n-1)%2][i] < min) min = best[(n-1)%2][i]; 
    }
    printf("%d\n", min);
    return 0;
}
