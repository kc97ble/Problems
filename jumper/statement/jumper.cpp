// SRM 376

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

string s[60];
int n;
vector<int> outcome[60];
vector<int> bucket[60];
bool mark[60];
bool exist[100];

vector<int> final(string A) {
    memset(exist,false,sizeof(exist));
    for (int i = 0; i < A.size(); i++) if (A[i] == '*') exist[i] = true;
    while (1) {
        bool moveLeft = false,reduce = false;
        for (int i = 3; i < 100; i++) if (exist[i] && !exist[i - 3]) {
            exist[i] = false;
            exist[i - 3] = true;
            moveLeft = true;
        }
        for (int i = 0; i < 100; i++) if (exist[i] && exist[i + 1]) {
            if (i && !exist[i - 1]) {
                exist[i - 1] = true;
                exist[i] = exist[i + 1] = false;
                reduce = true;
            }
            else if (!exist[i + 2]) {
                exist[i + 2] = true;
                exist[i] = exist[i + 1] = false;
                reduce = true;
            }
        }
        if (!moveLeft && !reduce && exist[0] && exist[2]) {
            exist[1] = true;
            reduce = true;
        }
        if (!moveLeft && !reduce) {
            for (int i = 0; i < 3; i++) if (exist[i] && exist[i + 3] && exist[i + 6]) {
                exist[i + 3] = exist[i + 6] = false;
                reduce = true;
                break;
            }
        }
        if (!moveLeft && !reduce) break;
    }
    vector<int> ret;
    for (int i = 0; i < 100; i++) if (exist[i]) ret.push_back(i);
    if (ret.size() < 2) return ret;
    ret.clear();
    ret.push_back(0);
    ret.push_back(3);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) outcome[i] = final(s[i]);

    int num = 0;
    for (int i = 0; i < n; i++) if (!mark[i]) {
        mark[i] = true;
        bucket[num].push_back(i + 1);
        for (int j = i + 1; j < n; j++) if (outcome[j] == outcome[i]) {
            mark[j] = true;
            bucket[num].push_back(j + 1);
        }
        num++;
    }
    printf("%d\n", num);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < bucket[i].size(); j++) printf("%d ", bucket[i][j]);
        printf("\n");
    }
}
