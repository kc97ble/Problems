#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <list>
#include <set>
#include <map>

#define FOR(i , a, b)   for(int i = a,_b =b; i <= _b ; i++)
#define FORD(i , a,b)   for(int i = a,_b = b; i >= _b ; i--)
#define REP(i , n)      for(int i = 0,_n = n;  i < _n ; i++)

#define MAX 111111

using namespace std;

typedef vector<int> vi;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef long long ll;

int cnt ;
string binary[MAX];

void recur(int k , int n , int len , string tmp)
{
    if(n == k)
    {
        cnt++;
        binary [cnt] = tmp;
        if(cnt == len - 2)
            return ;
    }
    else
    {
        k++;
        REP(i , 2)
        {
            string a = tmp;
            char ch = i + '0';
            a.push_back(ch);
            recur(k , n , len ,a);
        }
    }
}

int main()
{
    int n , index;
    scanf("%d",&n);
    cnt = 0;
    FOR(i , 2 , 20)
    {
        if(n - (1 << i) - 2 >= 0)
        {
            index = i + 1;
            break;
        }
    }
    
    recur(1 , index , n , "1");
    printf("00\n01\n");
    FOR(i , 1 , n - 2)
    {
        cout << binary[i] << endl;
    }
}

