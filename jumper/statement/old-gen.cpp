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

string convert(int x) {
    stringstream w;
    w << x;
    return w.str();
}

int main() {
    freopen("jumper.data","r",stdin);
    string F = "jumper.in.";
    for (int T = 0; T < 38; T++) {
        string A,B;
        cin >> A >> B;
        vector<string> array;
        string store = "";
        for (int i = 0; i < A.size(); i++)
          if (A[i] == '.' || A[i] == '*') store += A[i]; else if (!store.empty()) {
              array.push_back(store);
              store.clear();
          }

        const char * s = (F + convert(T)).c_str();
        FILE* f = fopen(s,"w");
        fprintf(f,"%d\n", array.size());
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < array[i].size(); j++) fprintf(f,"%c",array[i][j]);
            fprintf(f,"\n");
        }
    }
}
