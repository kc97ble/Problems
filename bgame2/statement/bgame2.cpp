#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Denote XY means X kills Y in this round
 * Define variables: ai = number of rounds with these rules
 * There are 9 types of round
 * Re-variable: A = John, B = Brus, F = Friend
 * a1: AF (A kills F)
 * a2: BF (B kills F)
 * a3: AB,AF
 * a4: BA,BF
 * a5: FA,FB
 * a6: AB,FA
 * a7: BA,FB
 * a8: FA,BF
 * a9: FB,AF
 * Then killA = a4 + a5 + a6 + a7 + a8
 * killB = a3 + a5 + a6 + a7 + a9
 * killF = a1 + a2 + a3 + a4 + a8 + a9
 * Let N equals to the number of rounds, then
 * N = (killA + killB + killF + a1 + a2)/2
 * Enumerate (a1,a2) in (0,0) -> (F,F), check whether they work */

struct TheBoringGameDivOne {
  vector<int> find(int sa,int ka,int sb,int kb,int sf,int kf) {      
    vector<int> ans(2);
    ans[0] = (1 << 20);  ans[1] = -(1 << 20);
    for (int a1 = 0; a1 <= kf; a1++)
      for (int a2 = 0; a1 + a2 <= kf; a2++) {
        int tmp = checkAnswer(sa,sb,sf,ka,kb,kf,a1,a2);
        if (tmp >= 0) {
          ans[0] = min(ans[0],tmp);
          ans[1] = max(ans[1],tmp);
        }
      }  
    if (ans[1] < 0) return vector<int>();
    return ans;
  }
  
  int checkAnswer(int sa,int sb,int sf,int ka,int kb,int kf,int a1,int a2) {	    
    int n = (ka + kb + kf + a1 + a2);
    if (!checkEven(n)) return -1;
    n /= 2;

    /* we need some variables (a1 and a2 are fixed now)
     * t567 = n - kf;
     * a4 + a8 = ka - t567 -> a8 <= ka - t567
     * a3 + a9 = kb - t567 -> a9 <= kb - t567
     * scoreA = a1 - a6 + a9 -> a9 = a6 + (scoreA - a1) = a6 + delta1
     * scoreB = a2 - a7 + a8 -> a8 = a7 + (scoreB - a2) = a7 + delta2
     * So min6 = max(0,-delta1) <= a6 <= kb - t567 - delta1 = max6
     * min7 = max(0,-delta2) <= a7 <= ka - 567 - delta2 = max7
     * Check whether min6 <= max6 and min7 <= max7
     * scoreF = 2 * a5 + a6 + a7 + a8 + a9
     * scoreF = 2(a5 + a6 + a7) + delta1 + delta2 = 2 * t567 + delta1 + delta2 (check this condition)
     * Finally we need to check a5: a5 = t567 - a6 - a7 <= t567 - min6 - min7 to see if a5 >= 0
     * Update answer n is tests are passed */
    
    int t567 = n - kf;
    int delta1 = sa - a1,delta2 = sb - a2;
    int min6 = max(0,-delta1),max6 = kb - t567 - delta1;
    int min7 = max(0,-delta2),max7 = ka - t567 - delta2;
    if (t567 < 0 || max6 < min6 || max7 < min7) return -1;
    
    int delta3 = sf - delta1 - delta2;
    if (!checkEven(delta3)) return -1;
    delta3 /= 2;
    if (delta3 != t567) return -1;
    if (delta3 - min6 - min7 < 0) return -1;
    return n;
  }
  
  bool checkEven(int x) {
    return (x >= 0 && x % 2 == 0);
  }
};

