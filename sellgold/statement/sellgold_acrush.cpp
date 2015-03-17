#line 4 "SellingGold.cpp"

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <complex>
#include <list>
#include <functional>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#define two(X) (1<<(X))
#define contain(S,X) ((S&two(X))>0)
#define MP(A,B) make_pair(A,B)
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
template<class T> inline T sqr(const T &x) { return x*x; }
template<class T> inline void checkmin(T &a,const T &b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a,const T &b) { if (b>a) a=b; }
template<class T> string toString(const T &n) { ostringstream sout; sout<<n; sout.flush(); return sout.str(); }
const double pi=acos(-1.0);
const double eps=1e-11;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> ipair;
template<class T> void out(const vector<T> &a) { cout<<"{"; for (int i=0;i<SIZE(a);i++) { if (i>0) cout<<","; cout<<a[i];} cout<<"}"<<endl; }

int n,a[60],b[60];
int f[30+5][30*500+5];

class SellingGold
{
public:
  double minimalSum(vector <int> gold, vector <int> price)
  {
    n=SIZE(gold);
    for (int i=0;i<n;i++) a[i]=gold[i],b[i]=price[i];
    memset(f,255,sizeof(f));
    f[0][0]=0;
    int m=n/2;
    for (int i=0;i<n;i++)
      for (int d=m;d>=1;d--) for (int k=d*500;k>=a[i];k--)
        if (f[d-1][k-a[i]]>=0)
          checkmax(f[d][k],f[d-1][k-a[i]]+b[i]);
    double R=1e100;
    int sa=0,sb=0;
    for (int i=0;i<n;i++) sa+=a[i],sb+=b[i];
    for (int k=0;k<=sa;k++) if (k>=sa-k && f[m][k]>=0)
      checkmin(R,(double)f[m][k]/(double)k+(double)(sb-f[m][k])/(double)(sa-k));
    return R;
  }
};


// Powered by FileEdit