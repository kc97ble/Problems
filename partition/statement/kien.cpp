#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const int N = 123;
int p[N], b[N][N], L;
int n;
#define shl(x, y) ((x) << (y))

class vi : public vector<int> { public:
	vi (int x=0) { assign(1, x); }
	vi& operator = (int x) { assign(1, x); return *this; }
};

string tostring(const vi &a) {
	string s;
	for (int i=a.size()-1; i>=0; i--)
	s += a[i]+'0';
	return s;
}

void fix(vi &a) { 
	for (int i=0; i<a.size()-1; i++) { 
		while (a[i]<0) { a[i]+=10; a[i+1]--; }
		a[i+1]+=a[i]/10; a[i]%=10;
	}
	while (a.size()>=2 && a.back()==0)
	a.pop_back();
}

void operator += (vi &a, const vi &b) {
	a.resize(max(a.size(), b.size())+1); 
	for (int i=0; i<b.size(); i++) a[i] += b[i];
	return fix(a);
}

void operator -= (vi &a, const vi &b) {
	a.resize(max(a.size(), b.size())+1); 
	for (int i=0; i<b.size(); i++) a[i] -= b[i];
	return fix(a);
}

void operator *= (vi &a, int b) {
	for (int i=0; i<a.size(); i++) a[i]*=b;
	do { a.push_back(0); } while (b/=10);
	return fix(a);
}

vi operator + (vi a, const vi &b)
	{ return a+=b, a; }
vi operator * (vi a, int b)
	{ return a*=b, a; }

struct djs {
	int P[N];
	void clear()
		{ for (int i=0; i<N; i++) P[i]=i; }
	bool join(int x, int y)
		{ x=at(x), y=at(y); return x==y ? false : (P[x]=y, true); }
	int at(int x)
		{ return x==P[x] ? x : P[x]=at(P[x]); }
} Label;

vi F[N][N];
bool FF[N][N];

vi f(int n, int k) {
	if (n==0) return 1;
	if (FF[n][k]++) return F[n][k];
	F[n][k] = f(n-1, k)*k + f(n-1, k+1);
	//printf("f(%d, %d) = ", n, k); cout << F[n][k] << endl;
	return F[n][k];
}

vi solve(int B) {
	int Count = n;
	Label.clear();
	for (int i=1; i<=L; i++)
	if (shl(1, i-1) & B)
		for (int j=2; j<=p[i]; j++)
		if (Label.join(b[i][1], b[i][j]))
		Count--;
	Label.clear();
	return f(Count, 0);
}

main() {
	scanf("%d%d", &n, &L);
	for (int i=1; i<=L; i++) {
		scanf("%d", &p[i]);
		for (int j=1; j<=p[i]; j++)
		scanf("%d", &b[i][j]);
	}
	vi Sum = 0;
	for (int i=0; i<(1<<L); i++) {
		if (__builtin_popcount(i)&1)
			Sum -= solve(i);
		else
			Sum += solve(i);
	}
	cout << tostring(Sum) << endl;
}

