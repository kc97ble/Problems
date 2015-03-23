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

string argIn = "travel.in.";
string argOut = "travel.expect.";
int LI = 13,LO = 17;

vector<int> turn(string alpha) {
    vector<int> v;
    istringstream is(alpha);
    for (int x; is >> x; ) v.push_back(x);
    return v;
}

int main() {
    freopen("travelFull.in","r",stdin);

    char cs1[20];
    for (int i = 0; i < 20; i++) cs1[i] = 0;
    for (int i = 0; i < argIn.size(); i++) cs1[i] = argIn[i];
    for (int i = LI - 3; i < LI; i++) cs1[i] = '0';

    char cs2[20];
    for (int i = 0; i < 20; i++) cs2[i] = 0;
    for (int i = 0; i < argOut.size(); i++) cs2[i] = argOut[i];
    for (int i = LO - 3; i < LO; i++) cs2[i] = '0';
//    for (int i = 0; i < LO; i++) {
  //      cs2[i] = '0';
   // }

    int T = 129;
    for (int it = 0; it < T; it++) {
        FILE* f1 = fopen(cs1,"w");
        FILE* f2 = fopen(cs2,"w");
        int phase = 0;
        string A[3];
        while (1) {
            char ch;
            scanf("%c", &ch);
            if (ch == ',') ch = ' ';
            if (ch == '}') phase++;
            if (phase == 3) break;
            if (ch != '{' && ch != '}') A[phase] += ch;
        }
        string B;
        cin >> B;
        for (int i = 0; i < B.size(); i++) fprintf(f2,"%c",B[i]);
        fprintf(f2,"\n");

        vector<int> C[3];
        for (int i = 0; i < 3; i++) C[i] = turn(A[i]);
        fprintf(f1,"%d %d\n", (int) C[0].size(), (int) C[2].size()/3);
        for (int i = 0; i < (int) C[0].size(); i++) fprintf(f1,"%d ", C[0][i]);
        fprintf(f1,"\n");
        fprintf(f1,"%d\n", C[1][0]);
        for (int i = 0; i < (int) C[2].size(); i += 3) fprintf(f1,"%d %d %d\n", C[2][i], C[2][i + 1], C[2][i + 2]);
        fclose(f1);
        fclose(f2);

        cs1[LI - 1]++;
        for (int i = LI - 1; i >= 0; i--) if (cs1[i] > '9') {
            cs1[i - 1]++;
            cs1[i] = '0';
        }
        else break;
        cs2[LO - 1]++;
        for (int i = LO - 1; i >= 0; i--) if (cs2[i] > '9') {
            cs2[i - 1]++;
            cs2[i] = '0';
        }
        else break;
    }
}
