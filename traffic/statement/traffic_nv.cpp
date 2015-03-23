#include <cstdio>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int main()
{
    freopen("trafficjam.in", "r", stdin);
    freopen("trafficjam.out", "w", stdout);
    int n, r, g;
    cin >> n >> g >> r; 
    assert(1 <= n && n <= 1000);
    assert(1 <= g && g <= int(1e9));
    assert(1 <= r && r <= int(1e9));
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        assert(0 <= a[i] && a[i] <= int(1e9));
    }
    int i = 0;
    long long ans = 0;
    while (i < n)
    {
        int tek = g;
        while (i < n && a[i] <= tek)
        {
            ans += a[i];
            tek -= a[i];
            i++;
        }
        if (i != n) ans += (tek + r);
    }
    cout << ans << endl;
}
