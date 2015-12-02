#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define maxn 1000005
using namespace std;

vector<int> bucket[26];
int n;
string s;

int main()
{
  //  freopen("diff.in","r",stdin);

    scanf("%d", &n);  cin >> s;
    for (int i = 0; i < n; i++) bucket[s[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++) bucket[i].push_back(n + 2);

    int ret = 0;
    for (int i = 0; i < 26; i++) if (bucket[i].size() > 1)
      for (int j = i + 1; j < 26; j++) if (bucket[j].size() > 1)
      {
          bool existPlus = false,existMinus = false;
          int sumPlus = 0,sumMinus = 0;
          bool leadPlus = false,leadMinus = false;

          for (int fi = 0,fj = 0; ; )
          {
              if (fi == bucket[i].size() - 1 && fj == bucket[j].size() - 1) break;
              if (bucket[i][fi] < bucket[j][fj])
              {
                  sumPlus++;
                  if (existMinus) ret = max(ret,sumPlus - leadMinus);
                  sumMinus++;
                  if (existMinus) ret = max(ret,abs(sumMinus));
                  if (sumMinus > 0)
                  {
                      sumMinus = 0;  leadPlus = true;
                  }
                  else leadPlus = false;
                  existPlus = true;
                  fi++;
              }
              else
              {
                  sumPlus--;
                  if (existPlus) ret = max(ret,abs(sumPlus));
                  if (sumPlus < 0)
                  {
                      sumPlus = 0;  leadMinus = true;
                  }
                  else leadMinus = false;
                  sumMinus--;
                  if (existPlus) ret = max(ret,abs(sumMinus + leadPlus));
                  existMinus = true;
                  fj++;
              }
          }
      }
    printf("%d\n", ret);
}
