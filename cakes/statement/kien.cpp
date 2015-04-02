#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int M = 1000000007;
//#define return(x) return printf("f(%d, %d, %d, %d, %d, %d) = %lld\n", n, A, B, C, Just+0, End+0, x), x
int FF[52][52][52][3][3];
bool F[52][52][52][3][3];

int f(int n, int A, int B, int C, char Just, char End) {
	if (n==0) return (Just==End);
	#define THIS A][B][C][Just][End
	if (F[THIS]++) return FF[THIS];
	long Sum = 0;
	if (A && Just!=0) Sum += f(n-1, A-1, B, C, 0, End);
	if (B && Just!=1) Sum += f(n-1, A, B-1, C, 1, End);
	if (C && Just!=2) Sum += f(n-1, A, B, C-1, 2, End);
	return (FF[THIS] = Sum % M);
}

main(){
	char s[123]; scanf("%s", s);
	int c[3]={0,0,0}, n=strlen(s);
	for (int i=0; s[i]; i++)
		c[s[i]-65]++;
	long Sum = 0;
	for (int i=0; i<3; i++)
		Sum += f(n, c[0], c[1], c[2], i, i);
	cout << Sum % M << endl;
}

