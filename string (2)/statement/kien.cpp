#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

void operator += (vi &a, const vi &b) {
	a.resize(max(a.size(), b.size())+1);
	for (int i=0; i<b.size(); i++)
	a[i] += b[i];
	
	for (int i=0; i+1<a.size(); i++)
	{ a[i+1]+=a[i]/10; a[i]%=10; }
	while (a.size()>=2 && a.back()==0) 
	a.pop_back();
}

string to_string(const vi &a) { 
	string s;
	for (int i=a.size()-1; i>=0; i--)
	s += a[i]+'0';
	return s;
}

int m, k, L, Next[123][123];
char a[123];
vi F[123][123][123];

vi f(int u, int m, int k) {
	if (m==0 || k<0) return k==0 ? vi(1, 1) : vi(1, 0);
	if (F[u][m][k].size()) return F[u][m][k];
	vi Sum(1, 0);
	for (int i='a'; i<='z'; i++)
	Sum += f(Next[u][i], m-1, k-(Next[u][i]==L));
	//printf("f(%d, %d, %d) = %d\n", u, m, k, Sum);
	return F[u][m][k] = Sum;
}

main() {
	freopen("string.inp", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%s", a); L=strlen(a);
	scanf("%d%d", &m, &k);
	
	for (int i=0; i<=L; i++) 
	for (char k='a'; k<='z'; k++) {
		for (int j=i+1; j>=1; j--)
		if (string(a, a+j)==string(a+i-(j-1), a+i)+k)
		{ Next[i][k]=j; break; }
	}
	
	cout << to_string(f(0, m, k)) << endl;
}
