#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<set>
#define oo 1000000000
#define base 1000000007
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
//Buffer reading
int INP,AM;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
if(!*inp) { \
    if (feof(stdin)) memset(BUF, 0, sizeof BUF); else fread(BUF,1,BUFSIZE,stdin); \
    inp=BUF; \
} \
INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
AM=0;\
GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
if (INP=='-') {AM=1;GETCHAR(INP);} \
j=INP-'0'; GETCHAR(INP); \
while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
if (AM) j=-j;\
}
//End of buffer reading
                            /*                           END OF TEMPLATE                            */
// VOI 2013
// IOI 2014

int m,Log[10005];
int Minc=oo,Minx=0,Miny=0;
vector<string> X;
void init()
{
    Log[1]=0;
    for(int i=2; i<=10000; i++)
    {
        Log[i]=Log[i-1];
        if(i==(1<<(Log[i-1]+1))) Log[i]++;
    }
}

void branch(string s,int cnt,int n)
{
    if(cnt==n)
    {
        X.push_back(s);
        return;
    }
    s[cnt]='0'; branch(s,cnt+1,n);
    s[cnt]='1'; branch(s,cnt+1,n);
}

int main()
{
    //freopen("encoding.inp","r",stdin);
    //freopen("encoding.out","w",stdout);
    int i,j,x,y;
    init();
    scanf("%d",&m);
    if(m==5)
    {
        printf("00\n01\n10\n110\n111\n");
        return 0;
    }
    for(x=0; x<=13; x++)
    {
        int n=m-(1<<x);
        if(n>=0)
        {
            y=Log[n-1]+1;
            if((1<<x)*(x+1)+n*(y+1)<Minc)
            {
                Minc=(1<<x)*(x+1)+n*(y+1);
                Minx=x; Miny=y;
            }
        }
    }
    string s(Minx+1,char());
    s[0]='0';
    branch(s,1,Minx+1);
    s.assign(Miny+1,char());
    s[0]='1';
    branch(s,1,Miny+1);
    for(i=0; i<m; i++) cout<<X[i]<<endl;
    return 0;
}
