#ifndef __ALICE_H__
#define __ALICE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* playing module interface */

	int get_n();
	/* initialize the game,
		returns n - the upper bound on the number
			that Alice has in mind
	*/

	int is_divisible_by(int m);
	/* question whether m divides Alice's number
	  input: m > 0
		returns 1 if m divides Alice's number, otherwise 0
	*/

	void guess(int k);
	/* attempts to guess Alice's number;
		should be called only once
	*/

#ifdef __cplusplus
}
#endif

#endif
