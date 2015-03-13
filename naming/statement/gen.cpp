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

int main() {
    freopen("naming.data","r",stdin);
    string inp = "naming.in.";
    string exp = "naming.expect.";
    for (int T = 0; T < 132; T++) {
        string A,B;
        cin >> A >> B;
        stringstream w;
        w << T;
        const char* cin = (inp + w.str()).c_str();
        FILE* fi = fopen(cin,"w");
        for (int i = 0; i < A.size(); i++) fprintf(fi,"%c",A[i]);
        fprintf(fi,"\n");
        fclose(fi);
        const char* cex = (exp + w.str()).c_str();
        FILE* fo = fopen(cex,"w");
        for (int i = 0; i < B.size(); i++) fprintf(fo,"%c",B[i]);
        fprintf(fo,"\n");
        fclose(fo);
    }
}
