#include "testlib.h"
using namespace std;

const int N = (int) 1e5;
long long x[N];
long long y[N];
bool visited[N];

int main(int argc, char ** argv) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    for (int i = 0; i < n; ++i) {
        x[i] = inf.readInt();
        y[i] = inf.readInt();
    }
    long long ja = ans.readLong();
    long long pa = ouf.readLong();
    if (pa > ja) quitf(_wa, "Bottle volume - expected " I64 ", received " I64, ja, pa);
    int last = ouf.readInt(1, n) - 1;
    if (last != 0) quitf(_wa, "Route must begin with 1");
    visited[0] = true;
    long long maxEdge = 0;
    while (last != n - 1) {
        int next = ouf.readInt(1, n) - 1;
        if (visited[next]) quitf(_wa, "Oasis #%d has been visited already", next + 1);
        visited[next] = true;
        maxEdge = max(maxEdge, abs(x[last] - x[next]) + abs(y[last] - y[next]));
        last = next;
    }
    if (maxEdge != pa) quitf(_wa, "Bottle volume - promised " I64 ", calculated " I64, pa, maxEdge);
    if (pa < ja) quitf(_fail, "Bottle volume - expected " I64 ", received " I64, ja, pa);
    quitf(_ok, I64, pa);
    return 0;
}
