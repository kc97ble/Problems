#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int n, w, a[N], b[N], c[N];

int f1() {
	int Sum = 0;
	for (int i=1; i<=n; i++) {
		int B=0, C=0;
		for (int j=1; j<=n; j++)
			if (b[j]==a[i]) B++;
		for (int j=1; j<=n; j++)
			if (c[j]==a[i]) C++;
		Sum += B*C;
	}
	return Sum;
}

int f2(int a[], int b[], int c[]) {
	int Sum = 0;
	for (int i=1; i<=n; i++) {
		int B=0, C=0;
		for (int j=1; j<=n; j++)
			if (b[j]==a[i]) B++;
		for (int j=1; j<=n; j++)
			if (c[j]<a[i]*2) C++;
		Sum += B*C;
	}
	return Sum;
}

main(){
	int T; cin >> T;
	while (T--) {
		scanf("%d%d", &n, &w);
		for (int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		for (int i=1; i<=n; i++)
			scanf("%d", &b[i]);
		for (int i=1; i<=n; i++)
			scanf("%d", &c[i]);

		if (w==1)
			cout << f1() << endl;
		else if (w==2)
			cout << f2(a, b, c) + f2(b, c, a) + f2(c, a, b) - 2*f1() << endl;
		else {
			sort(a+1, a+n+1);
			sort(b+1, b+n+1);
			sort(c+1, c+n+1);
			int Sum = 0;
			for (int i=1; i<=n; i++) {
				int L=n+1, R=0;
				for (int j=1; j<=n; j++) {
					while (R+1<=n && c[R+1]<a[i]+b[j]) R++;
					while (L-1>=0 && c[L-1]>abs(a[i]-b[j])) L--;
					while (L<=n && c[L]<=abs(a[i]-b[j])) L++;
					if (L<=R) Sum += R-L+1;
				}
			}
			cout << Sum << endl;
		}
	}
}

