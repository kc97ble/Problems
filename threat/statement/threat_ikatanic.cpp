## Contest: DEC10
## Program: letter.c
## Competitor: ivan.kata1
 1: OK [0.01 sec]
 2: OK [0.00 sec]
 3: OK [0.01 sec]
 4: OK [0.00 sec]
 5: OK [0.02 sec]
 6: OK [0.02 sec]
 7: OK [0.03 sec]
 8: OK [0.04 sec]
 9: OK [0.08 sec]
10: OK [0.15 sec]
------------------------------------------------------------------------
/*
  ID: ivan.kata1
  PROG: letter
  LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 100005;

char A[MAXN], B[MAXN];
int G[MAXN];
int x[20][50005];
int n, m, L, j;

struct suffix {
  int i;
  friend bool operator < ( const suffix &a, const suffix &b ) {
    if( L == 0 ) return A[a.i] < A[b.i];
    if( x[j][a.i] != x[j][b.i] ) return x[j][a.i] < x[j][b.i];
    return x[j][ a.i+L ] < x[j][ b.i+L ];
  }
 
  friend bool operator != ( const suffix &a, const suffix &b ) { return a < b || b < a; }
};
 
suffix a[MAXN];
         
void suffixArray() {
  for( int i = 0; i < n; ++i )
    a[i].i = i;
   
  L = 0, j = -1;
  int change = 1;
  while( change ) {
    change = 0;
    sort( a, a + n );
   
    int cnt = 0;
    for( int i = 0; i < n; ++i )
      if( !i || a[i] != a[ i-1 ] ) x[ j+1 ][ a[i].i ] = ++cnt; else
	x[ j+1 ][ a[i].i ] = cnt, change = 1;
   
    L <<= 1;
    if( L == 0 ) L = 1;
    j++;
  } while( change );
}
   
char ss[100];

int main( void ) {
  freopen( "letter.in", "r", stdin );
  freopen( "letter.out", "w", stdout );

  scanf( "%d %d", &n, &m );
  int p = 0;
  while( p < n ) {
    scanf( "%s", ss );
    int l = strlen( ss );
    for( int i = 0; i < l; ++i ) A[p++] = ss[i];
  }

  p = 0;  
  while( p < m ) {
    scanf( "%s", ss );
    int l = strlen( ss );
    for( int i = 0; i < l; ++i ) B[p++] = ss[i];
  }
  
  suffixArray();

  int i = 0, ans = 0;
  while( i < m ) {
    
    int L = 0, R = n-1;
    for( int j = 0; i < m; ++j ) {
      //   printf( "\n%d %d %d\n", j, L, R );
      // for( int x = L; x <= R; ++x ) {
      //	for( int y = a[x].i; y < n; ++y ) putchar( A[y] );
      //	putchar( '\n' );
      //  }
      
      int lo = L, hi = R;
      while( lo < hi ) {
	int mid = ( lo+hi )/2;
	if( A[ a[mid].i+j ] < B[i] ) lo = mid+1; else
	  hi = mid;
      }
      if( lo > R || A[ a[lo].i+j ] != B[i] ) break;
      L = lo;
     
      lo = L, hi = R;
      while( lo < hi ) {
	int mid = ( lo+hi+1 )/2;
	if( A[ a[mid].i+j ] > B[i] ) hi = mid-1; else
	  lo = mid;
      }
      if( hi < L || A[ a[lo].i+j ] != B[i] ) break;

      R = lo;
      if( L > R ) break;
      ++i;
    }
    ans++;
    //  printf( "%d %d\n", i, ans );
  }
  
  printf( "%d\n", ans );
  return 0;
}
