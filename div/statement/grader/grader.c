
/* Alice's module playing the evil strategy */

#ifdef __cplusplus
extern "C" {
#endif

#include "alice.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

static int n = 0;

static int l1, l2;

static int questions_number, questions_limit;

static char possible[MAX_N + 1];

static int i;

static void endgame(int result)
{
  printf("\n%s\n", result ? "OK" : "WRONG");
  exit(0);
}

int get_n()
{
  if (n == 0) {
	int unused __attribute__((unused));
    unused= scanf("%d %d %d %d", &n, &l1, &l2, &questions_limit);
    questions_number = 0;
    for(i = l1; i <= l2; i++)
      possible[i] = 1;
  }
  printf("get_n() = %d\n", n);
  return n;
}

int is_divisible_by(int m)
{
  int ans = 1;
  printf("is_divisible_by(%d) ", m);
  if (n == 0) {
    printf("ERROR: "
	   "Function `is_divisible_by' was called before function `get_n'");
    endgame(0);
  }
  if (m <= 0) {
    printf("ERROR: Function `is_divisible_by' was called with negative m");
    endgame(0);
  }
  if (m > n) {
    printf("ERROR: Function `is_divisible_by' was called with m > n");
    endgame(0);
  }
  questions_number++;
  if (questions_number > questions_limit) {
    for(i = l1; i <= l2; i++)
      if (possible[i])
	break;
    l1 = l2 = i;
  }
  /* we try to answer NO if only it is possible */
  if (m > 1) {
    for (i = l1; i <= l2; i++)
	      if (possible[i] && i % m != 0) {
		ans = 0;
		break;
	      }
    if (ans == 0) {
	      for(i = l2 - l2 % m; i >= l1; i -= m)
		possible[i] = 0;
    }
    else { /* ans == 1 */
	      for(i = l1; i <= l2; i++)
		if (i % m != 0)
		  possible[i] = 0;
    }
  }
  printf("= %d\n", ans);
  return ans;
}

void guess(int k)
{
  int alice_k = k;

  printf("guess(%d)", k);

  if (n == 0) {
    printf(" ERROR: Function `guess' was called before function `get_n'");
    endgame(0);
  }

  for(i = l1; i <= l2; i++)
    if (possible[i] && i != k) {
      alice_k = i;
      break;
    }

  printf("\nAlice's secret number is %d\n", alice_k);

  if (questions_number > questions_limit) {
    printf("FAIL: Program asked %d questions. Questions limit "
	   "%d was exceeded.", questions_number, questions_limit);
    endgame(0);
  }

  if (alice_k != k) {
    printf("FAIL: Alice's secret number is missed after asking %d questions",
	   questions_number);
    endgame(0);
  }

  printf("SUCCESS: Alice's secret number guessed successively after asking "
	 "%d questions", questions_number);
  endgame(1);
}

#ifdef __cplusplus
}
#endif
