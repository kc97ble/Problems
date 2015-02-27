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
    freopen("batch.bat","w",stdout);
    char ch[3];
    ch[0] = ch[1] = ch[2] = '0';
    for (int i = 0; i < 100; i++) {
        //printf("ren maze.in.%d maze.in.%c%c%c\n", i, ch[0],ch[1],ch[2]);
        //printf("ren maze.expect.%d maze.expect.%c%c%c\n", i, ch[0],ch[1],ch[2]);
        printf("del maze.in.%d\n", i);
        ch[2]++;
        for (int i = 2; i >= 0; i--) if (ch[i] > '9') {
            ch[i - 1]++;
            ch[i] = '0';
        }
    }
}
