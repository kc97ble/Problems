#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n, Sum=0;
char a[1003];

main(){
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++) {
		scanf("%s", a+1);
		int b = 0;
		for (int j=1; j<=n; j++)
			if (a[j]=='.') Sum+=b;
			else { b^=2; Sum++; }
	}
	cout << Sum/2 << endl;
}
