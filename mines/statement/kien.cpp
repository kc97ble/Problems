#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1003
int m, n, s[N][N], a[N][N], t[N][N];

int evidence(int u) {
	for (int i=2; i<=n; i+=3) {
		if (t[u][i]-a[u][i+1]==0)
			{ a[u][i-1]=a[u][i]=0; return i; }
		if (t[u][i]-a[u][i+1]==2)
			{ a[u][i-1]=a[u][i]=1; return i; }
	}
	return 0;
}

void solve_row(int u) {
	for (int i=3; i<=n; i+=3)
		a[u][i] = t[u][i-1]-t[u][i-2]+a[u][i-3];
	for (int i=n-2; i>=1; i-=3)
		a[u][i] = t[u][i+1]-t[u][i+2]+a[u][i+3];
	if (n%3==0) {
		for (int i=2; i<=n; i+=3)
		a[u][i] = t[u][i]-a[u][i-1]-a[u][i+1];
	} else if (n%3==1) {
		for (int i=1; i<=n; i+=3)
			a[u][i] = t[u][i+1]-a[u][i+1]-a[u][i+2];
		a[u][n] = t[u][n-1]-a[u][n-1]-a[u][n-2];
	} else {
		int i = evidence(u);
		if (!i) { a[u][1]=0; a[u][2]=1; i=2; }
		for (int j=i+2; j<=n; j++)
			a[u][j] = t[u][j-1]-a[u][j-1]-a[u][j-2];
		for (int j=i-2; j>=1; j--)
			a[u][j] = t[u][j+1]-a[u][j+1]-a[u][j+2];
	}
}

void solve() {
	for (int i=3; i<=m; i+=3) {
		for (int j=1; j<=n; j++)
			t[i][j] = s[i-1][j]-s[i-2][j]+t[i-3][j];
		solve_row(i);
	}
	for (int i=m-2; i>=1; i-=3) {
		for (int j=1; j<=n; j++)
			t[i][j] = s[i+1][j]-s[i+2][j]+t[i+3][j];
		solve_row(i);
	}
	if (m%3==1) {
		for (int i=1; i<=m; i+=3) {
			for (int j=1; j<=n; j++)
				t[i][j] = s[i+1][j]-t[i+1][j]-t[i+2][j];
			solve_row(i);
		}
		for (int j=1; j<=n; j++)
			t[m][j] = s[m-1][j]-t[m-1][j]-t[m-2][j];
		solve_row(m);
	} else if (m%3==0) {
		for (int i=2; i<=m; i+=3) {
			for (int j=1; j<=n; j++)
				t[i][j] = s[i][j]-t[i-1][j]-t[i+1][j];
			solve_row(i);
		}
	}
}

main(){
	char S[N];
	scanf("%d%d", &m, &n);
	for (int i=1; i<=m; i++) {
		scanf("%s", S+1);
		for (int j=1; j<=n; j++)
		s[i][j] = S[j]-'0';
	}
	if (m%3==2) {
		swap(m, n);
		for (int i=1; i<=max(m, n); i++)
			for (int j=1; j<i; j++)
			swap(s[i][j], s[j][i]);
		solve();
		swap(m, n);
		for (int i=1; i<=max(m, n); i++)
			for (int j=1; j<i; j++)
			swap(a[i][j], a[j][i]);
	} else {
		solve();
	}
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++)
			S[j]=a[i][j][".X"];
		printf("%s\n", S+1);
	}
}

