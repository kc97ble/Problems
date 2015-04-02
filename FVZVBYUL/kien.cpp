#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

main(){
	long A, B;
	while ((cin >> A >> B) && (A!=0 || B!=0)) {
		if (A==B) cout << A << endl;
		else {
			long Max = max(A, B);
			for (long i=1; i<B; i=i*2+1)
			if ((B&~i)>A && (B&i+1))
			Max = max(Max, B|i);
			cout << Max << endl;
		}
	}
}
