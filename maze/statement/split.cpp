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

string argIn = "maze.in.";
string argExpect = "maze.expect.";

string convert(int x) {
    stringstream w;  w << x;
    return w.str();
}

int main() {
    freopen("mazeFull.in","r",stdin);
    int T = 105;
    for (int it = 0; it < T; it++) {
        string A,B;
        cin >> A >> B;
        char ch[15];
        for (int i = 0; i < 15; i++) ch[i] = 0;
        int len = argIn.size();
        for (int i = 0; i < argIn.size(); i++) ch[i] = argIn[i];
        string tmp = convert(it);
        for (int i = 0; i < tmp.size(); i++) {
            ch[len] = tmp[i];
            len++;
        }
        printf("%s\n", ch);
        FILE *f1 = fopen(ch,"w");

        vector<string> s;
        B.clear();
        for (int i = 0; i < A.size(); i++) if (A[i] == ',') {
            s.push_back(B);
            B.clear();
        }
        else B += A[i];
        fprintf(f1,"%d %d\n", s.size(), s[0].size());
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s[0].size(); j++) fprintf(f1,"%c", s[i][j]);
            fprintf(f1,"\n");
        }
        fclose(f1);
    }
}
