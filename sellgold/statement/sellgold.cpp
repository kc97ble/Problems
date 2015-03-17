#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

string convert(int x) {
  stringstream w;
  w << x;  return w.str();
}

vector<string> parse(string s) {
  string u = "";
  vector<string> v;
  for (int i = 0; i < s.size(); i++)
    if ('0' <= s[i] && s[i] <= '0') u += s[i]; else if (!u.empty()) {
      v.push_back(u);
      u.clear();
    }
  return v;
}

int main() {
}
