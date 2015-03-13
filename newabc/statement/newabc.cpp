#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> words(N);
    vector<vector<bool> > order(26, vector<bool>(26));
    vector<bool> used(26);
    vector<int> deg(26);
    bool is_unknown = false;

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
        for (size_t j = 0; j < words[i].size(); j++)
            used[words[i][j] - 'a'] = true;
    }
    for (int i = 0; i + 1 < N; i++)
    {
        const string &wa = words[i];
        const string &wb = words[i + 1];
        size_t p = 0;
        while (p < wa.size() && p < wb.size() && wa[p] == wb[p])
            p++;
        if (p == wb.size())
        {
            if (p < wa.size())
                goto impossible;
        }
        else if (p != wa.size())
        {
            int la = wa[p] - 'a';
            int lb = wb[p] - 'a';
            order[la][lb] = true;
        }
    }

    for (int y = 0; y < 26; y++)
        for (int x = 0; x < 26; x++)
            if (order[x][y])
                for (int z = 0; z < 26; z++)
                    if (order[y][z])
                        order[x][z] = true;

    for (int x = 0; x < 26; x++)
        if (used[x])
            for (int y = x + 1; y < 26; y++)
                if (used[y])
                {
                    if (order[x][y] && order[y][x])
                        goto impossible;
                    else if (!order[x][y] && !order[y][x])
                        is_unknown = true;
                    else if (order[x][y])
                        deg[x]++;
                    else
                        deg[y]++;
                }
    if (is_unknown)
        goto unknown;

    for (int i = accumulate(used.begin(), used.end(), 0) - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
            if (used[j] && deg[j] == i)
                cout << (char) ('a' + j);
    }
    cout << '\n';
    return 0;

impossible:
    cout << "!\n";
    return 0;

unknown:
    cout << "?\n";
    return 0;
}
