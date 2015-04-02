#include <stdio.h>

void show(int n, int k) {
	for (int i=k-1; i>=0; i--)
	putchar(n&(1<<i) ? '1' : '0');
	printf("\n");
}

main(){
	int n; scanf("%d", &n);
	int k=32-__builtin_clz(n)-1;
	//cout << k << endl;
	int b = n-(1<<k);
	int a = n-2*b;
	for (int i=0; i<a; i++) show(i, k);
	for (int i=0; i<2*b; i++) show(i+2*a, k+1);
}
