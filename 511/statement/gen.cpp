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

string convert(int i) {
    stringstream w;
    w << i;
    return w.str();
}

int toint(string s) {
    int x;
    stringstream w;  w << s; w >> x;
    return x;
}

int main() {
    freopen("511.data","r",stdin);
    string inp = "511.in.";
    string exp = "511.expect.";
    for (int it = 0; it < 217; it++) {
        printf("%d\n", it);
        string A,B;
        cin >> A >> B;
        A += ',';
        vector<int> v;
        string store = "";
        for (int i = 0; i < A.size(); i++) if (A[i] == ',') {
            v.push_back(toint(store));
            store.clear();
        }
        else store += A[i];

        string I = convert(it);
        const char* Ai = (inp + I).c_str();
        FILE* fi = fopen(Ai,"w");
        fprintf(fi,"%d\n", (int) v.size());
        for (int i = 0; i < v.size(); i++) fprintf(fi,"%d ", v[i]);
        fprintf(fi,"\n");
        const char* Bi = (exp + I).c_str();
        fclose(fi);
        FILE* fe = fopen(Bi,"w");
        for (int i = 0; i < B.size(); i++) fprintf(fe,"%c",B[i]);
        fprintf(fe,"\n");
        fclose(fe);
    }
}
