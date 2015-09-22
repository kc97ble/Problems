#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=100005, oo=0x3c3c3c3c;
int n, k, a[N];

int f(int x) {
    int Last=-oo, Count=0;
    for (int i=1; i<=n; i++)
    if (a[i]-Last>=x) {
       Count++;
       Last=a[i];
    }
    return Count;
}

main() {
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    int ll=0, rr=oo, mm=(ll+rr)/2;
    while (ll<rr) {
        if (f(mm)>=k) ll=mm; else rr=mm-1;
        mm=(ll+rr+1)/2;
    }
    cout << mm << endl;
}

