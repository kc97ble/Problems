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
using namespace std;

struct rec
{
    pair<int,int> v;  int pos;
} a[1010];

bool cmp(rec A,rec B)
{
    return A.v < B.v;
}

string s[1010];
int m,n;
int order[1010];

int main()
{
//    freopen("znan.in","r",stdin);
//    freopen("znan.ou","w",stdout);
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) cin >> s[i];
    memset(order,0,sizeof(order));
    for (int i = m - 1; i; i--)
    {
        for (int j = 0; j < n; j++)
        {
            a[j].v.first = order[j];  a[j].v.second = s[i][j];  a[j].pos = j;
        }
        sort(a,a + n,cmp);
        int cnt = -1;
        for (int j = 0; j < n; j++)
        {
            if (!j || a[j].v > a[j - 1].v) cnt++;
            order[a[j].pos] = cnt;
        }
        if (cnt >= n - 1)
        {
            printf("%d\n", i);  return 0;
        }
    }
    printf("0\n");
}
