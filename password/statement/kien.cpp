#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
char a[N], b[N];
int m, n, sa[N];
int Left=0, Right=0;

main() {
	freopen("password.inp", "r", stdin);
	freopen("password.out", "w", stdout);
	
	scanf("%s%s", a+1, b+1);
	m=strlen(a+1), n=strlen(b+1);
	for (int i=1; i<=n; i++)
		if (a[i]==b[i]) Left++;
		else break;
	for (int i=0; i<=n-1; i++)
		if (a[m-i]==b[n-i]) Right++;
		else break;
	for (int i=1; i<=m; i++)
		sa[i] = sa[i-1] + (a[i]-'0');
	//cout << Left << " " << Right << endl;
	
	for (int i=1; i<=n; i++) {
		int Bij = 0;
		for (int j=i; j<=(b[i]=='0' ? i : n); j++) {
			Bij = Bij*10 + (b[j]-'0');
			if (Bij>=1000000) break;
			//printf("b:%d:%d = %d\n", i, j, Bij);
			if (i-1<=Left && n-j<=Right)
			if (sa[m-n+j]-sa[i-1]==Bij) { 
				cout << i << " " << m-n+j << endl; 
				return 0;
			}
		}
	}
	return 102;
}
