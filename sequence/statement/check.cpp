#include <cstdio>
#include "testlib.h"
using namespace std;

typedef long long llong;

const int N = 111111;

llong A[N];
llong S[N];

int n, k;

llong readVal(InStream& in)
{
    llong val = in.readLong();
    vector<int> P;
    P.push_back(0);
    P.push_back(n);
    for (int i = 0; i < k; i++)
        P.push_back(in.readInt(1, n - 1));
    sort(P.begin(), P.end());
    for (int i = 0; i < k + 1; i++)
        if (P[i] == P[i + 1])
            in.quitf(_wa, "position %d occurs twice in split scheme", P[i]);
    llong curs = 0;
    llong rval = 0;
    for (int i = 0; i + 1 < P.size(); i++)
        rval += (S[P[i + 1]] - S[P[i]]) * S[P[i]], curs += S[P[i + 1]] - S[P[i]];
    if (rval != val)
        in.quitf(_wa, "declared answer doesn't correspond to the split scheme: declared = %s, real = %s", vtos(val).c_str(), vtos(rval).c_str());
    return val;
}

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readInt(), k = inf.readInt();
    for (int i = 0; i < n; i++)
        A[i] = inf.readLong(), S[i + 1] = S[i] + A[i];
    llong ouf_val = readVal(ouf);
    llong ans_val = readVal(ans);
    if (ouf_val < ans_val)
        quitf(_wa, "contestant didn't find the optimal answer: %s < %s", vtos(ouf_val).c_str(), vtos(ans_val).c_str());
    else if (ouf_val == ans_val)
        quitf(_ok, "contestant found the optimal answer: %s == %s", vtos(ouf_val).c_str(), vtos(ans_val).c_str());
    else // (ouf_val > ans_val)
        quitf(_fail, "0_o contestant found better answer than ours! %s > %s", vtos(ouf_val).c_str(), vtos(ans_val).c_str());
    return 0;
}


