#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
typedef vector<int> vi;
const int N=234, M=123456789;

vi operator * (const vi &a, const vi &b) {
	vi c(N);
	for (int i=0; i<N; i++)
	c[i] = a[i]+b[i];
	return c;
}

vi operator / (const vi &a, const vi &b) {
	vi c(N);
	for (int i=0; i<N; i++)
	c[i] = a[i]-b[i];
	return c;
}

vi __gcd(const vi &a, const vi &b) {
	vi c(N);
	for (int i=0; i<N; i++)
	c[i] = min(a[i], b[i]);
	return c;
}

vi Int[N];

vi parse() {
	int a; scanf("%d", &a);
	if (a==-1) return Int[1];
	int b; scanf("%d", &b);
	vi A = parse();
	vi B = parse();
	vi G = __gcd(B*Int[b], A*Int[a]);
	return A*B*Int[a+b]/G;
}

ostream& operator << (ostream& cout, const vi &T) {
	for (int i=0; i<T.size(); i++)
	if (T[i]) printf("%d^%d ", i, T[i]);
	return cout;
}

long power(long a, long k, long m) {
	long P = 1;
	while (k) {
		if (k&1) P=P*a%m;
		a=a*a%m, k/=2;
	}
	return P;
}

main() {
	Int[1]=vi(N);
	for (int i=2; i<N; i++) {
		if (Int[i].size()==0) {
			Int[i]=vi(N);
			Int[i][i]++;
		}
		for (int j=2; j<=i; j++) if (i*j<N)
		Int[i*j] = Int[i] * Int[j];
	}
	//for (int i=1; i<N; i++)
	//cout << Int[i] << endl;
	scanf("%*d");
	vi Result = parse();
	long P = 1;
	for (int i=0; i<N; i++)
	if (Result[i]) P = P * power(i, Result[i], M) % M;
	cout << P << endl;
}

