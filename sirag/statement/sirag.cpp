
/*
Autor: Catalin-Stefan Tiseanu
Punctaj: 100
Complexitate: O(N)
*/

#include <cstdio>

#define HOLE '*'
#define MAX_N (1<<17)

int N, L, A[MAX_N], T[MAX_N], deque_min[MAX_N];
char w[MAX_N];

int solve() {
  int ql = 1, qr = 0, sol = 0;  
     
  for ( int i = 1; i <= N; i++ ) {
    if ( w[i] != HOLE || i <= L )
      A[i] = i;
     else
      A[i] = A[i-L];

    if ( ( i > L ) && 
      (w[i] == HOLE || w[ A[i-L] ] == HOLE || w[i] == w[ A[i-L] ] ) )
      T[i] = T[i-L] + 1;
    else if ( i > L )
      T[i] = ( i - A[i-L] ) / L;
    else
      T[i] = 1; 
             
    while ( qr >= ql && T[ deque_min[qr] ] >= T[i] )
      --qr;
    deque_min[++qr] = i;
    while ( qr >= ql && i - deque_min[ql] + 1 > L )
      ++ql;
         
    if ( T[ deque_min[ql] ] > sol )
      sol = T[ deque_min[ql] ];                 
  }
     
  return sol * L;   
}

int main() {
  freopen("sirag.in", "r", stdin);
  freopen("sirag.out", "w", stdout);  
  
  int T;
  
  scanf("%d", &T );
  
  for ( ; --T; ) {  
    scanf("%d %d", &N, &L);
    scanf("%s", w + 1);
    printf("%d\n", solve() );
  }
  return 0;    
}
