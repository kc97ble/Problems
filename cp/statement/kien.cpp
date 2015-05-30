#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N=123, M=10000;
char a[N]; int n;
bool ok[N][N]; //

typedef vector<int> vi;

void fix(vi &a) {
	for (int i=0; i+1<a.size(); i++) if (a[i]>=M) 
		{ a[i+1]+=a[i]/M; a[i]%=M; }
	while (a.size()>=2 && a.back()==0) 
		a.pop_back();
}

vi operator + (const vi &a, int x) {
	vi b(a); b.push_back(0); b[0]+=x;
	return fix(b), b;
}

vi operator * (const vi &a, const vi &b) {
	vi c(a.size()+b.size());
	for (int i=0; i<a.size(); i++)
	for (int j=0; j<b.size(); j++)
	c[i+j] += a[i]*b[j];
	return fix(c), c;
}

bool operator <= (const vi &a, const vi &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i=a.size()-1; i>=0; i--)
	if (a[i]!=b[i]) return a[i] < b[i];
	return true;
}

void solve(int L) {
	vi Sqrt=vi(1, 0), Current=vi(1, a[L]-'0');
	for (int i=L; i<=n; i+=2) {
		while ((Sqrt+1)*(Sqrt+1) <= Current) Sqrt=Sqrt+1;
		//printf("sqrt(%d, %d) = %d\n", L, i, Sqrt[0]);
		ok[L][i] = (Sqrt*Sqrt==Current);
		Sqrt = Sqrt * vi(1, 10);
		Current = Current*vi(1, 100) + (a[i+1]-'0')*10 + (a[i+2]-'0');
	}
	Sqrt=vi(1, 0), Current=vi(1, (a[L]-'0')*10 + (a[L+1]-'0'));
	for (int i=L+1; i<=n; i+=2) {
		while ((Sqrt+1)*(Sqrt+1) <= Current) Sqrt=Sqrt+1;
		ok[L][i] = (Sqrt*Sqrt==Current);
		Sqrt = Sqrt*vi(1, 10);
		Current = Current*vi(1, 100) + (a[i-1]-'0')*10 + (a[i]-'0');
	}
	/*for (int i=L; i<=n; i++)
	if (ok[L][i]) printf("%d:%d ", L, i);
	cout << endl;*/
}

int FF[N], t;
long F[N];

long f(int n) {
	if (n==0) return 1;
	if (FF[n]!=t) FF[n]=t; else return F[n];
	long Sum = 0;
	for (int i=1; i<=n; i++)
	if (a[n-i+1]!='0' && ok[n-i+1][n])
	Sum += f(n-i);
	return F[n] = Sum;
}

main() {
	scanf("%d", &t);
	do {
		scanf("%s", a+1); n=strlen(a+1);
		for (int i=1; i<=n; i++) solve(i);
		cout << f(n) << endl;
		memset(ok, 0, sizeof ok);
	} while (--t);
}
