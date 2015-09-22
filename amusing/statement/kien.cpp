#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
char nn[20], kk[20];
long F[20][2][2][2];
int FF[20][2][2][2], t;
#define C u][LessN][GreaterN][LessK

long f(int u, bool LessN, bool GreaterN, bool LessK) {
	if (nn[u]==0) return !GreaterN;
	if (FF[C]!=t) FF[C]=t; else return F[C];
	long Sum = (u!=0);
	for (int i=(u==0 ? 1 : 0); i<=9; i++)
	if (LessK || kk[u] && i<=kk[u]-'0')
	Sum += f(u+1,
		LessN || !GreaterN && i<nn[u]-'0',
		GreaterN || !LessN && i>nn[u]-'0',
		LessK || kk[u] && i<kk[u]-'0');
	return F[C] = Sum;
}

long f(long n) {
	t++;
	sprintf(nn, "%lld", n);
	long fx = f(0, 0, 0, 0);
	//printf("f(%lld) = %lld\n", n, fx);
	return fx;
}

main() {
	int m, k; scanf("%d%d", &m, &k);
	sprintf(kk, "%d", k);
	long ll=k, rr=123123123123123LL, mm=(ll+rr)/2;
	while (ll!=rr) {
		if (f(mm)>=m) rr=mm; else ll=mm+1;
		mm=(ll+rr)/2;
	}
	if (f(mm)!=m) cout << 0 << endl;
	else cout << mm << endl;
}

