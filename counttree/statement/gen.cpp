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
    freopen("counttree.data","r",stdin);
    string F = "counttree.in.";
    for (int i = 0; i < 60; i++) {
        string A,B;
        cin >> A >> B;
        string W = F + convert(i);
        const char * s = W.c_str();

        vector<string> array;
        string store = "";
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 'Y' || A[i] == 'N') store += A[i]; else if (!store.empty()) {
                array.push_back(store);
                store.clear();
            }
        }

        FILE* f = fopen(s,"w");
        fprintf(f,"%d\n", (int) array.size());
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < array[i].size(); j++) fprintf(f,"%c",array[i][j]);
            fprintf(f,"\n");
        }
        fclose(f);
    }
}
