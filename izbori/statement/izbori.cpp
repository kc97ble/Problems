#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define INF 10001000
using namespace std;

int v,n,m;
int qualify;
int fin;
int a[102],ret[102];
double tmp[102],seat[102];
int f[102][202],c[102][202];

void get1()
{
     int rem = v;
     for (int i = 1; i <= n; i++) rem -= a[i];
     for (int i = 1; i <= n; i++)
     {
         a[i] += rem;
         for (int j = 1; j <= n; j++) tmp[j] = a[j];
         memset(seat,0,sizeof(seat));
         for (int j = 0; j < m; j++)
         {
             int pos = -1;  double ratio = -1.0;
             for (int k = 1; k <= n; k++) 
               if (a[k] >= qualify && ratio < (tmp[k]) / (seat[k] + 1) )
               {
                  ratio = (tmp[k]/(seat[k] + 1));  pos = k;
              };
             seat[pos]++;
         };
         ret[i] = seat[i];
         a[i] -= rem;
     };
};

bool ok(int pos,int num)
{
     for (int i = 1; i <= n; i++) if (i != pos)
     {
         c[i][0] = a[i];
         for (int j = 1; j <= m - num; j++)
         { 
             c[i][j] = (int) ceil(j * a[pos] / (num + 1));            
             if (i > pos && c[i][j] * (num + 1) == a[pos] * j) c[i][j]++;
             c[i][j] = max(c[i][j],qualify);
             c[i][j] = max(c[i][j],a[i]);
             c[i][j] = min(c[i][j],INF);
         };
     };
     
     for (int i = 0; i <= n; i++)
       for (int j = 0; j <= m - num; j++) f[i][j] = INF;
     f[0][0] = 0;
     
     for (int i = 1; i < pos; i++)
       for (int j = 0; j <= m - num; j++)
         for (int k = 0; k <= j; k++) f[i][j] = min(f[i][j],f[i - 1][k] + c[i][j - k]);         
     for (int j = 0; j <= m - num; j++) f[pos][j] = f[pos - 1][j];
     for (int i = pos + 1; i <= n; i++)
       for (int j = 0; j <= m - num; j++)
         for (int k = 0; k <= j; k++) f[i][j] = min(f[i][j],f[i - 1][k] + c[i][j - k]);
         
     if (f[n][m - num] <= v - a[pos])
     {
        fin = num; return true;
     };
     return false;
};

void get2()
{
     for (int i = 1; i <= n; i++) if (a[i] < qualify) ret[i] = 0; else
     {
         int inf = 0,sup = m; fin = 0;
         while (inf <= sup)
         {
               int med = (inf + sup)/2; // med = 0;
               if (ok(i,med)) sup = med - 1; else inf = med + 1;
         };
         ret[i] = fin;
     };
};

int main()
{
    scanf("%d %d %d", &v, &n, &m);
    qualify = (int) ceil(v/20);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    get1();
    for (int i = 1; i <= n; i++) printf("%d ", ret[i]);
    printf("\n");
    get2();
    for (int i = 1; i <= n; i++) printf("%d ", ret[i]);
};
