#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 400005, M = 1000000000;
int n1, n2, n, d[N];
char a1[N], a2[N], a[N];
int F[N], S[N];

bool minimize(int &a, int b)
	{ if (a>b) a=b; else return false; return true; }
bool maximize(int &a, int b)
	{ if (a<b) a=b; else return false; return true; }

namespace suffix_array {
	
	int sa[N], ra[N], rb[N], lcp[N], G;
	
	bool cmp(int x, int y) {
		if (ra[x]!=ra[y]) return ra[x]<ra[y];
		return ra[x+G] < ra[y+G];
	}

	void execute(char a[], int n) {
		for (int i=1; i<=n; i++)
		{ sa[i]=i; ra[i]=a[i]; }
		
		for (G=1; G==1 || ra[sa[n]]!=n; G*=2) {
			sort(sa+1, sa+n+1, cmp);
			for (int i=1; i<=n; i++)
			rb[sa[i]] = rb[sa[i-1]] + cmp(sa[i-1], sa[i]);
			for (int i=1; i<=n; i++)
			ra[i]=rb[i];
		}
		
		int k=0;
		for (int i=1; i<=n; i++) {
			int j = sa[ra[i]+1];
			while (a[i+k]==a[j+k]) k++;
			lcp[ra[i]] = k;
			if (k) k--;
		}
	}

}

void l_r() {
	using namespace suffix_array;
	int Min = 0;
	for (int i=1; i<=n; i++) {
		if (sa[i]>n1) 
			Min=lcp[i];
		else { 
			maximize(d[sa[i]], Min);
			minimize(Min, lcp[i]);
		}
	}
}

void r_l() {
	using namespace suffix_array;
	int Min = 0;
	for (int i=n; i>=1; i--) {
		if (sa[i]>n1) 
			Min = 0x3c3c3c3c;
		else {
			minimize(Min, lcp[i]);
			maximize(d[sa[i]], Min);
		}
	}
}

main() {
	scanf("%s%s", a1, a2);
	n1=strlen(a1);
	n2=strlen(a2);
	
	strcat(a+1, a1);
	strcat(a+1, a2);
	n=n1+n2;
	
	using namespace suffix_array;
	execute(a, n);
	//for (int i=1; i<=n; i++) printf("%s ", a+sa[i]); printf("sa\n");
	//for (int i=1; i<=n; i++) printf("%d ", lcp[i]); printf("lcp\n");
	
	l_r();
	r_l();
	//for (int i=1; i<=n1; i++) printf("%d ", d[i]); printf("\n");
	
	S[n1+1] = F[n1+1] = 1;
	for (int i=n1; i>=1; i--) {
		//F[i] = F[i+1 .. i+d[i]];
		F[i] = (S[i+1] - S[i+d[i]+1] + M) % M;
		S[i] = (S[i+1] + F[i]) % M;
	}
	cout << F[1] << endl;
}

