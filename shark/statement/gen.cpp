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

vector<int> convert(string s) {
    vector<int> opt;
    string store = "";
    for (int i = 0; i < s.size(); i++) if ('0' <= s[i] && s[i] <= '9') store += s[i]; else if (!store.empty()) {
        stringstream w;
        w << store;
        int x;
        w >> x;
        opt.push_back(x);
        store.clear();
    }
    return opt;
}

int main() {
    freopen("shark.data","r",stdin);
    string inp = "shark.in.";
    string exp = "shark.expect.";
    for (int it = 0; it < 72; it++) {
        string A[3],B;
        cin >> A[0] >> A[1] >> A[2] >> B;
        vector<int> C[3];
        for (int i = 0; i < 3; i++) C[i] = convert(A[i]);

        stringstream w;
        w << it;
        const char* cin = (inp + w.str()).c_str();
        FILE* fi = fopen(cin,"w");
        fprintf(fi,"%d\n", C[0].size());
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < C[i].size(); j++) fprintf(fi,"%d ", C[i][j]);
            fprintf(fi,"\n");
        }
        fclose(fi);
        const char* cex = (exp + w.str()).c_str();
        FILE* fe = fopen(cex,"w");
        for (int i = 0; i < B.size(); i++) fprintf(fe,"%c",B[i]);
        fprintf(fe,"\n");
        fclose(fe);
    }
}
