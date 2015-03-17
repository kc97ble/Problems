#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#define mod 10003
using namespace std;

int dp[102][52][52][52];
int m,n,K;

int rec(int K,int row,int n0,int n1) {
    if (K < 0 || n0 < 0 || n1 < 0) return 0;
    if (row == 0) return (K == 0);
    int &ans = dp[K][row][n0][n1];
    if (ans >= 0) return ans;

    ans = rec(K,row - 1,n0,n1);  // no rooks avail
    // 1 rook
    ans = (ans + n0 * rec(K - 1,row - 1,n0 - 1,n1 + 1)) % mod; // 0-square
    ans = (ans + n1 * rec(K - 1,row - 1,n0,n1 - 1)) % mod; // 1-square
    // 2 rooks
    ans = (ans + n0 * (n0 - 1)/2 * rec(K - 2,row - 1,n0 - 2,n1 + 2)) % mod;  // two 0-square
    ans = (ans + n0 * n1 * rec(K - 2,row - 1,n0 - 1,n1)) % mod;  // one 0-square and one 1-square
    ans = (ans + n1 * (n1 - 1)/2 * rec(K - 2,row - 1,n0,n1 - 2)) % mod;  // two 1-square
    return ans;
}

int main() {
    freopen("rooks.in","r",stdin);
    freopen("rooks.out","w",stdout);
    scanf("%d %d %d", &m, &n, &K);
    if (K > 2 * min(m,n)) {
        printf("0\n");
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n", rec(K,m,n,0));
}

