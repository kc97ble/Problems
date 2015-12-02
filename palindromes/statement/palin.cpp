//#pragma comment(linker, "/STACK:16777216")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#define mod 55788242953LL
using namespace std;

int n,k;
string s;
int f[2000010];
long long hash[2000010];
map<long long,int> mp;

void KMP_function()
{
    f[0] = -1;
    for (int i = 1; i < k; i++)
    {
        int j = f[i - 1];
        for (; ;)
        {
            if (s[i] == s[j + 1])
            {
                f[i] = j + 1;  break;
            }
            else if (j < 0)
            {
                f[i] = -1;  break;
            }
            else j = f[j];
        }
    }
}

int find_position()
{
    if (f[k - 1] < 0) return k;
    int r1 = f[k - 1],r2 = k - 1 - r1;
    if (r1 + 1 < r2) return k;
    if (r1 + 1 == r2) return r2;
    if ( (r1 + 1) % r2 == 0 ) return r2; else return k;
}

int main()
{
//    freopen("palin.in","r",stdin);
//    freopen("palin.ou","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);  cin >> s;
        KMP_function();
        int pos = find_position();
        hash[i] = 0;
        for (int j = 0; j < pos; j++) hash[i] = (hash[i] * 26LL + s[j] - 'a') % mod;
        mp[hash[i]]++;
    }
    long long ret = 0;
    for (int i = 0; i < n; i++) ret += mp[hash[i]];
    cout << ret << endl;
}
