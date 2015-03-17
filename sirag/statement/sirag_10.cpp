
/*
Autor: Catalin-Stefan Tiseanu
Punctaj: 10
Complexitate: O(N) [ doar pentru L = 1 ]
*/

#include <cstdio>

#define HOLE '*'
#define MAX_N 1<<20

int N, L, A[MAX_N], T[MAX_N];
char w[MAX_N];

int solve() {
     int ql = 1, qr = 0, sol = 0;  
     
     T[0] = 0;
     A[0] = 0;
     
     for ( int i = 1; i <= N; i++ ) {
         if ( w[i] != HOLE )
            A[i] = i;
         else
            A[i] = A[i-1];

         if ( i > 1 && (w[i] == HOLE || w[ A[i-1] ] == HOLE || w[i] == w[ A[i-1] ]) )
            T[i] = T[i-1] + 1;
         else if ( i > 1 )
            T[i] = i - A[i-1];
         else
            T[i] = 1;               
         
         if ( T[i] > sol )
           sol = T[i];
     } 
     
     return sol;   
}

int main() {
  freopen("sirag.in", "r", stdin);
  freopen("sirag.out", "w", stdout);  
  
  int T;
  
  scanf("%d", &T );
  
  for ( ; T--; ) {  
    scanf("%d %d", &N, &L);
    scanf("%s", w + 1);
    printf("%d\n", solve() );
  }
  
  return 0;    
}
