#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

#ifdef __GNUC__
#define int64 long long
#else /* MSVC, say */
#define int64 __int64
#endif

class CardRemover {
public:
  int dist(string a, string b) {
    int res = 0;
    if ((a[0]==b[0])||(a[0]==b[1])||(a[0]==b[2])) res++;
    if ((a[1]==b[0])||(a[1]==b[1])||(a[1]==b[2])) res++;
    if ((a[2]==b[0])||(a[2]==b[1])||(a[2]==b[2])) res++;
    return res;
  }

    int calculate(vector <string> cards) {
    int n = cards.size();
        bool can[51][51];
    memset(can, 0, sizeof(bool));
    int i,j,k,l;
    for (i=0; i < n; i++)
      can[i][i+1] = true;
    for (l=2; l < n; l++)
      for (i=0; i+l<n; i++) {
        can[i][i+l] = false;
        for (j=i+1; j < i+l; j++)
          if ((dist(cards[i], cards[i+l]) >= 2) && (can[i][j]) && (can[j][i+l]))
            can[i][i+l] = true;
      }
    int f[51];
    f[0] = 1;
    for (i=1; i<n; i++) {
      f[i] = f[i-1]+1;
      for (j=0; j < i; j++)
        if ((can[j][i]) && (f[j]+1 < f[i])) f[i] = f[j]+1;
    }
    return n -  f[n-1];
    }

};


// Powered by FileEdit
// Powered by CodeProcessor