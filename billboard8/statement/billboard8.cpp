#include<iostream>
#include<sstream>
#include<algorithm>
#include<queue>
#include <string>
#include <vector>
#include<stack>
#include<map>
#include<math.h>
#include<set>
using namespace std;
class LightedPanels {
  public:
  int minTouch(vector <string> b) {
    int n=b.size();
    int m=b[0].length();
    int kil=1<<(m+n-1);
    int res=100;
    int i,j,k;
    for(int ind=0;ind<kil;ind++)
    {
      int pot=0;
      vector<string> tb=b;
      int tmp=ind;
      for(k=0;k<m;k++)
      {
        if(tmp%2)
        {
          pot++;
          for(i=0;i<2;i++)
          for(j=k-1;j<=k+1;j++)
          if(j>=0 && j<m && i<n)
          {
            if(tb[i][j]=='*')tb[i][j]='.';
            else tb[i][j]='*';
          }
        }
        tmp/=2;
      }
      for(k=1;k<n;k++)
      {
        if(tmp%2)
        {
          pot++;
          for(i=k-1;i<=k+1;i++)
          for(j=0;j<2;j++)
          if(i>=0 && j<m && i<n)
          {
            if(tb[i][j]=='*')tb[i][j]='.';
            else tb[i][j]='*';
          }
        }
        tmp/=2;
      }
      for(j=1;j<m;j++)
      for(i=1;i<n;i++)
      {
        if(tb[i-1][j-1]=='*')continue;
        pot++;
        for(int ii=i-1;ii<=i+1;ii++)
        for(int jj=j-1;jj<=j+1;jj++)
        if(ii<n && jj<m)
        {
          if(tb[ii][jj]=='*')tb[ii][jj]='.';
          else tb[ii][jj]='*';
        }
      }
      bool f=true;
      for(i=0;i<n;i++)
      for(j=0;j<m;j++)
      if(tb[i][j]=='.')
      {
        f=false;
        break;
      }
      if(f && pot<res)res=pot;
    }
    if(res==100)return -1;
    return res;
  }
};