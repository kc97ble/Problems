#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n, Next[32][1003], Count[1003];
char a[1003][1003], b[102][32];

bool contain(char a[]) {
	int u=0;
	for (int i=0; a[i]; i++) {
		u=Next[a[i]][u]+1;
		if (u==0) return false;
	}
	return true;
}

void ease(char a[])
	{ for (int i=0; a[i]&=31; i++); }

void prepare(char a[]) {
	int n = strlen(a);
	for (int k=1; k<=31; k++) {
		Next[k][n] = -1;
		for (int i=n-1; i>=0; i--)
		Next[k][i] = (a[i]==k ? i : Next[k][i+1]);
	}
}

main(){
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++)
		{ scanf("%s", a[i]); ease(a[i]); }
	for (int i=1; i<=n; i++)
		{ scanf("%s", b[i]); ease(b[i]); }
	for (int i=1; i<=m; i++) {
		prepare(a[i]);
		for (int j=1; j<=n; j++)
		Count[i] += contain(b[j]);
	}
	for (int i=1; i<=m; i++)
		printf("%d\n", Count[i]);
}

