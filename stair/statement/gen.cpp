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
    freopen("stair.data","r",stdin);
    string inp = "stair.in.";
    string exp = "stair.expect.";
    for (int T = 0; T < 65; T++) {
        int A,B,C;
        scanf("%d %d %d", &A, &B, &C);

        stringstream w;
        w << T;
        const char* cin = (inp + w.str()).c_str();
        FILE* fi = fopen(cin,"w");
        fprintf(fi,"%d %d\n", A, B);
        fclose(fi);
        const char* cex = (exp + w.str()).c_str();
        FILE* fe = fopen(cex,"w");
        fprintf(fe,"%d\n", C);
        fclose(fe);
    }
}
