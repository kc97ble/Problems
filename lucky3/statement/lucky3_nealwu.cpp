    #include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXD = 20;

int D, dig [MAXD];
long long findp [MAXD][2][28];

long long finish (int pos, int match, int rem)
{
    if (pos == D)
        return (rem % 4 == 0 || rem % 7 == 0) ? 1 : 0;

    long long &sol = findp [pos][match][rem];

    if (sol != -1)
        return sol;

    sol = 0;

    if (match == 1)
    {
        for (int d = 0; d <= dig [pos]; d++)
        {
            int nmatch = d == dig [pos] ? 1 : 0;
            int nrem = (rem * 10 + d) % 28;
            sol += finish (pos + 1, nmatch, nrem);
        }
    }
    else
    {
        for (int d = 0; d < 10; d++)
        {
            int nmatch = 0;
            int nrem = (rem * 10 + d) % 28;
            sol += finish (pos + 1, nmatch, nrem);
        }
    }

    return sol;
}

vector <long long> sdp [MAXD][2][2][28];

vector <long long> vecsolve (int pos, int match, int zero, int rem)
{
    if (pos == D)
        return vector <long long> (10, 0);

    if (!sdp [pos][match][zero][rem].empty ())
        return sdp [pos][match][zero][rem];

    sdp [pos][match][zero][rem].resize (10, 0);

    if (match == 1)
    {
        for (int d = 0; d <= dig [pos]; d++)
        {
            int nmatch = d == dig [pos] ? 1 : 0;
            int nzero = (zero == 1 && d == 0) ? 1 : 0;
            int nrem = (rem * 10 + d) % 28;

            if (nzero == 0)
                sdp [pos][match][zero][rem] [d] += finish (pos + 1, nmatch, nrem);

            vector <long long> next = vecsolve (pos + 1, nmatch, nzero, nrem);

            for (int i = 0; i < 10; i++)
                sdp [pos][match][zero][rem] [i] += next [i];
        }
    }
    else
    {
        for (int d = 0; d < 10; d++)
        {
            int nmatch = 0;
            int nzero = (zero == 1 && d == 0) ? 1 : 0;
            int nrem = (rem * 10 + d) % 28;

            if (nzero == 0)
                sdp [pos][match][zero][rem] [d] += finish (pos + 1, nmatch, nrem);

            vector <long long> next = vecsolve (pos + 1, nmatch, nzero, nrem);

            for (int i = 0; i < 10; i++)
                sdp [pos][match][zero][rem] [i] += next [i];
        }
    }

    return sdp [pos][match][zero][rem];
}

vector <long long> calc (long long n)
{
    if (n == 0)
        return vector <long long> (10, 0);

    D = 0;

    while (n > 0)
    {
        dig [D++] = n % 10;
        n /= 10;
    }

    reverse (dig, dig + D);
    memset (findp, -1, sizeof (findp));

    for (int i = 0; i < MAXD; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 28; l++)
                    sdp [i][j][k][l].clear ();

    return vecsolve (0, 1, 1, 0);
}

struct TheLuckyNumbersLevelThree
{
    vector <long long> find (long long a, long long b)
    {
        vector <long long> av = calc (a - 1), bv = calc (b);

        for (int i = 0; i < 10; i++)
            bv [i] -= av [i];

        return bv;
    }
};



// Powered by FileEdit
// Powered by moj 4.13 [modified TZTester]
// Powered by CodeProcessor