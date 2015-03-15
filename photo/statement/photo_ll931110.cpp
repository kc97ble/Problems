// A solution which I NEVER recommend you to do the same. This is a demo to demonstrate an implementation of SkipList data structure, which you will never use in national contest. Of course, you can read it for fun and learning.

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define maxn 20005
#define MAX_LEVEL 15
using namespace std;

map<int,int> mp;
int store[maxn],n;
int a[maxn][5],pos[maxn][5];
int INF = 1 << 29;

struct node
{
         int level,value;
         node* nextNode[MAX_LEVEL];
         int width[MAX_LEVEL];
         int maxValue[MAX_LEVEL];

         node(int _L,int _V)
         {
             level = _L;  value = _V;
             for (int i = 0; i <= level; i++)
             {
                 width[i] = 1;  nextNode[i] = NULL;  maxValue[i] = value;
             }
         }
};

int randomLevel()
{
    int L = 0;
    while (rand() % 2 < 1 && L + 1 < MAX_LEVEL) L++;
    return L;
}

struct skipList
{
       node* head;

       void init()
       {
            head = new node(MAX_LEVEL - 1,-INF);
       }

        int getValue(int pos) {
            node* A = head;
            for (int i = head->level; i >= 0; i--)
              while (A->level >= i && A->width[i] <= pos) {
                  pos -= A->width[i];
                  A = A->nextNode[i];
              }
            return A->value;
        }

       void insert(int pos,int value)
       {
            node* A = head;
            node* link[MAX_LEVEL];

            int tmp = 0;
            for (int i = head->level; i >= 0; i--)
            {
              while (tmp + A->width[i] < pos)
              {
                tmp += A->width[i];  A = A->nextNode[i];
              }
              link[i] = A;
            }

            node* B = new node(randomLevel(),value);
            for (int i = 0; i <= B->level; i++)
            {
                B->nextNode[i] = link[i]->nextNode[i];
                link[i]->nextNode[i] = B;
            }

            for (int i = B->level + 1; i <= head->level; i++)
            {
                link[i]->width[i]++;
                link[i]->maxValue[i] = max(link[i]->maxValue[i],value);
            }

            link[0]->width[0] = 1;  link[0]->maxValue[0] = link[0]->value;
            for (int i = 1; i <= B->level; i++)
            {
                link[i]->width[i] = 0;  link[i]->maxValue[i] = link[i]->maxValue[i - 1];
                node* C = link[i];
                while (C != B)
                {
                  link[i]->width[i] += C->width[i - 1];
                  link[i]->maxValue[i] = max(link[i]->maxValue[i],C->maxValue[i - 1]);
                  C = C->nextNode[i - 1];
                }
            }

            B->width[0] = 1;  B->maxValue[0] = value;
            for (int i = 1; i <= B->level; i++)
            {
                B->width[i] = 0;  B->maxValue[i] = B->maxValue[i - 1];
                node* C = B;
                while (C != B->nextNode[i])
                {
                  B->width[i] += C->width[i - 1];
                  B->maxValue[i] = max(B->maxValue[i],C->maxValue[i - 1]);
                  C = C->nextNode[i - 1];
                }
            }
        }
} S;

bool order(int u,int v) {
    // return true if u stands before v
    int numSmall = 0,numBig = 0;
    for (int i = 0; i < 5; i++) if (pos[u][i] < pos[v][i]) numSmall++; else numBig++;
    return (numSmall > numBig);
}

int main() {
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);

    scanf("%d", &n);
    for (int j = 0; j < 5; j++)
      for (int i = 1; i <= n; i++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) {
        mp[a[i][0]] = i;
        store[i] = a[i][0];
    }

    for (int j = 0; j < 5; j++)
      for (int i = 1; i <= n; i++) pos[mp[a[i][j]]][j] = i;

    S.init();
    S.insert(1,1);
    for (int i = 2; i <= n; i++) {
        int low = 1,high = i - 1,where = 1;
        while (low <= high) {
            int mid = (low + high)/2;
            int get = S.getValue(mid);
            if (order(i,get)) high = mid - 1; else {
                where = mid + 1;
                low = mid + 1;
            }
        }
        S.insert(where,i);
    }

    // restore array
    int final[maxn];
    node* U = S.head;
    for (int i = 1; i <= n; i++) {
        U = U->nextNode[0];
        final[i] = U->value;
    }
    for (int i = 1; i <= n; i++) printf("%d\n", store[final[i]]);
}
