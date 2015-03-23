// 50% score
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int main()
{
//    freopen("elections.in", "r", stdin);
//    freopen("elections.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    assert(1 <= n && n <= int(300000));
    assert(1 <= k && k <= int(100000));

    vector<bool> num(n + 1, true);
    vector<int> b;
    int x;
    for (int i = 0; i < k; ++i)
    {
        cin >> x;
        assert(1 <= x && x <= n);
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    vector<int> a;
    a.push_back(b[0]);
    for (size_t i = 1; i < b.size(); ++i)
    {
        int temp = b[i];
        for (size_t j = 0; j < i; ++j)
        {
            if (temp % b[j] == 0) temp /= b[0];
            if (temp == 1) break;
        }
        if (temp != 1) a.push_back(b[i]);
    } 
    for (size_t i = 0; i < a.size(); ++i)
        for (int j = a[i]; j <= n; j += a[i])
            num[j] = false;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += num[i] ? 1 : 0;
    cout << ans;
}
