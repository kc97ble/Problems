#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    #define int long long
    #define size_t unsigned long long
    freopen("sumsquare.in", "r", stdin);
    freopen("sumsquare.out", "w", stdout);
    int ch;
    cin >> ch;
    vector<int> ans, ans2;
    vector<int> sq;
    for (int i = 0; i < ch + 1; i++)
        sq.push_back(i * i);
    
    int sum_1 = 0, sum_2 = 0; 
    int sq_1 = 0, sq_2 = 0;
    while (ch > 12)
    {
        ch--;
        if (sq_1 > sq_2)
        {
            sq_2 += sq[ch];
            sum_2 += ch;
            ans.push_back(ch);
        }
        else
        {
            sq_1 += sq[ch];
            sum_1 += ch;
        }
    }
    for (size_t n = 0; n < (((size_t)1) << ch); ++n)
    {
        ans2.clear();
        int sum1 = sum_1, sum2 = sum_2; 
        int sq1 = sq_1, sq2 = sq_2;
        for (int i = 0; i < ch; i++)
        {
            if (n & (((size_t)1) << i)) 
            {
                sum1 += i;
                sq1 += sq[i];
            }
            else
            {
                sum2 += i;
                sq2 += sq[i];
                ans2.push_back(i);
            }
        }
        if (sum1 == sum2 && sq1 == sq2)
        {
            cout << "YES\n";
            for (size_t i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            for (size_t i = 0; i < ans2.size(); i++)
                cout << ans2[i] << " ";

            cout << endl;
            return 0;
        }
    }
    cout << "NO\n";
}
