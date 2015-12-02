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
    for (int i = 0; i < 100; i++) {
        printf("ren mecho.0%d%d.in mecho.in.0%d%d\n", i/10, i % 10, i/10, i % 10);
        printf("ren mecho.0%d%d.sol mecho.expect.0%d%d\n", i/10, i % 10, i/10, i % 10);
    }
}
