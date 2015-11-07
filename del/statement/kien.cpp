#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N=1003;
int n, F[123][123];
char Char[N], s[N][123], P[123];

bool ok(char a[], char b[]) {
	int m=strlen(a+1), n=strlen(b+1);
	for (int i=0; i<=m; i++)
	for (int j=0; j<=n; j++)
	if (i==0 && j==0) 
		F[i][j]=true;
	else if (b[j]=='?') 
		F[i][j] = i!=0 && F[i-1][j-1];
	else if (b[j]=='*')
		F[i][j] = i!=0 && F[i-1][j] || F[i][j-1];
	else
		F[i][j] = a[i]==b[j] && F[i-1][j-1];
	return F[m][n];
}

main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	scanf(" %c%s", &Char[i], s[i]+1);
	scanf("%s", P+1);
	
	bool Failed = false;
	for (int i=1; i<=n; i++)
	if (ok(s[i], P) != (Char[i]=='-'))
	{ Failed=true; break; }
	puts(Failed ? "0" : "1");
}

