// Implementare Simoiu Robert, 100 pct, traducere Pascal -> C++
#include <cstdio>

const char FIN[] = "flori.in";
const char FOU[] = "flori.out";
const int MAX = 4005;
const int oo = 0x3f3f3f3f;

int s[MAX], a[MAX], lung[MAX], succ[MAX];
int lungmin, l, k, n, m, i, j, pozmax, p;
short x;

int main()
{
    freopen(FIN,"r",stdin);
    freopen(FOU,"w",stdout);
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &x), a[i - j + m] += x;
    l = m + n - 1;
    k = 2 * l - 1;
    for (i = l + 1; i <= k; i++)
       a[i] = a[2 * l - i];
    succ[k] = k + 1;
    s[k] = a[k];
    lung[k] = 1;
    for (i = k - 1; i > 0; i--)
    {
        s[i] = a[i], succ[i] = k + 1, lung[i] = 1;
        for (j = i + 1; j <= k; j++)
           if (a[i] < a[j] || (a[i] == a[j] && (j <= l || i > l)))
               if (s[i] < s[j] + a[i])
                   s[i] = s[j] + a[i], succ[i] = j, lung[i] = lung[j] + 1;
               else if (s[i] == s[j] + a[i] && lung[i] > lung[j] + 1)
                       lung[i] = lung[j] + 1, succ[i] = j;
    }

    pozmax = 1, lungmin = oo;
    for (i = 2; i <= k; i++)
       if (s[pozmax] < s[i] || s[pozmax] == s[i] && lungmin > lung[i])
           pozmax = i;

    printf("%d x\n", s[pozmax]);
    printf("%d x\n", lung[pozmax]);

    p = pozmax;

    while ( p != k + 1 )
    {
        if (p <= l) printf("%d ",p);
        else printf("%d ",2 * l - p);
        p = succ[p];
    }
    return 0;
}
