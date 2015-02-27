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

const int MAXH = 132000;

pair <long long, vector <int> > psum [MAXH], qsum [MAXH];

struct TheLuckyNumbersLevelTwo
{
    vector <int> find (vector <int> numbers)
    {
        vector <long long> all;

        for (int len = 1; len <= 11; len++)
        {
            long long four = 0, seven = 0;

            for (int i = 0; i < len; i++)
            {
                four = four * 10 + 4;
                seven = seven * 10 + 7;
            }

            all.push_back (four);
            all.push_back (seven);
        }

        int n = numbers.size ();
        int p = n / 2, q = n - p;
        int pp = 1 << p, qq = 1 << q;

        for (int m = 0; m < pp; m++)
        {
            for (int i = 0; i < p; i++)
                if (m & 1 << i)
                {
                    psum [m].first += numbers [i];
                    psum [m].second.push_back (numbers [i]);
                }

            sort (psum [m].second.begin (), psum [m].second.end ());
        }

        for (int m = 0; m < qq; m++)
        {
            for (int i = 0; i < q; i++)
                if (m & 1 << i)
                {
                    qsum [m].first += numbers [i + p];
                    qsum [m].second.push_back (numbers [i + p]);
                }

            sort (qsum [m].second.begin (), qsum [m].second.end ());
        }

        sort (psum, psum + pp);
        sort (qsum, qsum + qq);
        vector <int> best;

        sort (all.rbegin (), all.rend ());

        for (int j = 0; j < (int) all.size (); j++)
        {
            for (int i = 0; i < pp; i++)
            {
                int pos = lower_bound (qsum, qsum + qq, make_pair (all [j] - psum [i].first, vector <int> ())) - qsum;

                if (pos >= 0 && pos < qq && psum [i].first + qsum [pos].first == all [j])
                {
                    vector <int> now = psum [i].second;

                    for (int k = 0; k < (int) qsum [pos].second.size (); k++)
                        now.push_back (qsum [pos].second [k]);

                    sort (now.begin (), now.end ());

                    if (best.empty () || now < best)
                        best = now;
                }
            }

            if (!best.empty ())
                break;
        }

        return best;
    }
};
