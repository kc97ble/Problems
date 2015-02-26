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
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

long long f[21][11][20][2][2];
// f(digit,last_digit,#last,sm,nz)
// #last = K will be ok condition

long long number(long long A,int K) {
  if (A <= 0) return 0;
  vector<int> digit;
  long long tmp = A;
  while (tmp) {
    digit.push_back(tmp % 10);
    tmp /= 10;
  }
  memset(f,0,sizeof(f));
  f[digit.size()][0][0][0][0] = 1;
  for (int d = digit.size(); d > 0; d--)
    for (int last = 0; last < 10; last++)
      for (int num = 0; num <= K; num++)
        for (int sm = 0; sm < 2; sm++)
	  for (int nz = 0; nz < 2; nz++) if (f[d][last][num][sm][nz])
	    for (int next = 0; next < 10; next++) {
	      if (!sm && digit[d - 1] < next) continue;
	      int _sm = sm || (digit[d - 1] > next);
	      int _nz = nz || (next > 0);
	      // special processing for _nz = 0
	      if (!_nz) {
	        f[d - 1][0][0][1][0] = 1;
		continue;
	      }

	      int _last = next;
	      int _num = num;
	      if (_num < K) _num = (last == next) ? min(K,num + 1) : 1;
	      f[d - 1][_last][_num][_sm][_nz] += f[d][last][num][sm][nz];
	    }
  long long ret = 0;
  for (int sm = 0; sm < 2; sm++)
    for (int last = 0; last < 10; last++)
      ret += f[0][last][K][sm][1];
  return ret;
}

int main() {
  long long A,B;
  int K;

  cin >> A >> B >> K;
  cout << number(B,K) - number(A - 1,K) << endl;
}
