/* Random from Gassa */
/* Updated by Burunduk1 and Burunduk3 */

/** please notice all changed in this log **
 * 2009-08-15 - rndLong() was added
 * 2010-11-29 - asserts are added, comments are modified [Burunduk1]
 * 2010-11-29 - rndLong is fixed, R(ll, ll) is added [Burunduk1]
 ****/

#ifndef __random_h__
#define __random_h__

#include <cmath>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>

/***
 * Declarations
 ***/

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;

int nextrand();             // random in [0..MBIG)
void initrand( int seed );  // initialize random
double rndDouble();         // random in [0..1)
int rndInt( int k );        // random in [0..k)
ll rndLong( ll k );         // random in [0..k) version for "long long"
int R( int A, int B );      // random in [A..B]
ll Time();                  // returns number of tics since processor was turned on
template <typename Type>
void randomShuffle( Type start, Type finish ); // shuffles an array like std::random_shuffle, but using our random

/***
 * Definitions
 ***/

const int MBIG = (int)1e9, MSEED = 161803398;
const double FAC = 1.0 / MBIG;

int inext, inextp;
int ra [56];

int nextrand() // Random in [0..MBIG)
{
  int j;
  if (++inext == 56)
    inext = 1;
  if (++inextp == 56)
    inextp = 1;
  j = ra[inext] - ra[inextp];
  if (j < 0)
    j += MBIG;
  ra[inext] = j;
  return j;
}

void initrand(int seed)
{
  int i, j, k, l;
  seed = seed * seed + seed * 239017 + 13;
  l = MSEED - seed;
  l %= MBIG;
  if (l < 0)
    l += MBIG;
  ra[55] = l;
  k = 1;
  for (i = 1, j = 0; i <= 54; i++)
  {
    j += 21;
    if (j > 55)
      j -= 55;
    ra[j] = k;
    k = l - k;
    if (k < 0)
      k += MBIG;
    l = ra[j];
  }
  for (k = 1; k <= 4; k++)
    for (i = 1, j = 31; i <= 55; i++, j >= 55 ? j = 1 : j++)
    {
      ra[i] -= ra[j];
      if (ra[i] < 0)
        ra[i] += MBIG;
    }
  inext = 0;
  inextp = 31;
}

double rndDouble() // Random in [0..1)
{
  return nextrand () * FAC;
}

int rndInt(int k) // Random in [0..k)
{
  assert(1 <= k);
  return (int)(rndDouble () * k);
}

ll rndLong( ll k ) // Random in [0..x)
{
  assert(1 <= k);
  return (ll)((rndDouble () * FAC + rndDouble()) * k);
}

int R( int A, int B )
{
  assert(A <= B && (uint)B - A < (1LL << 31) - 1);
  return A + rndInt(B - A + 1);
}

ll R( ll A, ll B )
{
  assert(A <= B && (ull)B - A < (1ULL << 63) - 1);
  return A + rndLong(B - A + 1);
}

ll Time()
{
#ifdef __GNUC__
  ll res;
  asm volatile ("rdtsc" : "=A" (res));
  return res;
#else
  int low, hi;
  __asm
  {
    rdtsc
    mov low, eax
    mov hi, edx
  }
  return ((ll)hi << 32) | low;
#endif
}

template <typename Type>
void randomShuffle( Type start, Type finish )
{
  for (int i = 0; start + i != finish; i++)
  {
    int j = R(0, i);
    std::swap(*(start + i), *(start + j));
  }
}

#endif // __random_h__
