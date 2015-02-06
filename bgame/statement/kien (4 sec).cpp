#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

const bool SELLING = false;
const bool BUYING = true;
const int oo = 0x3c3c3c3c;

int n, T, R, d, e;
int Value[502][5], Max[5];
bool FF[2][5][21][21][21][21][21];
int F[2][5][21][21][21][21][21];
#define C u.Stage][u.Day][u.a[0]][u.a[1]][u.a[2]][u.a[3]][u.a[4]

struct state {
	bool Stage;
	int Day, a[5];
	
	bool any() const
		{ f0(i,5) if (a[i]) return true; return false; }	
	state previous_stage() const
		{ state u=*this; if (u.Stage^=1) u.Day--; return u; }
	state next_stage() const
		{ state u=*this; if ((u.Stage^=1) == (BUYING^1)) u.Day++; return u; }
	state before_sell(int k) const 
		{ state u=*this; u.a[k]++; return u; }	
	state before_buy(int k) const
		{ state u=*this; u.a[k]--; return u; }
};

int f(const state &u) {
	if (u.Day==0 && u.Stage==SELLING)
		return u.any() ? -oo : T;
	if (FF[C]++) return F[C];

	int Max = f(u.previous_stage());
	if (u.Stage == SELLING) {
		f0(i,n) if (u.a[i] < ::Max[i])
		Max = max(Max, f(u.before_sell(i))+Value[u.Day][i]-e);
	} else { // buying
		f0(i,n) if (u.a[i] > 0)
		Max = max(Max, f(u.before_buy(i))-Value[u.Day][i]-d);
	}
	return F[C] = (Max<0 ? -oo : Max);
}

int greedy(int Remain, int u, int Day) {
	int Old = Value[Day][u];
	int New = Value[Day+1][u];
	if (u==n-1) {
		if (Old>=New) return Remain;
		int Buy = min(Remain/Old, Max[u]);
		return Remain + Buy*(New-Old);
	}
	int Best = Remain;
	for (int i=0; i<=Max[u]; i++) {
		if (i*Value[Day][u]<=Remain)
		Best = max(Best, greedy(Remain-i*Old, u+1, Day)+i*New);
	}
	return Best;
}

main(){
	scanf("%d%d%d%d%d", &n, &T, &R, &d, &e);
	f0(i,n) scanf("%d", &Max[i]);
	f0(i,R) f0(j,n) scanf("%d", &Value[i][j]);
	if (R<=5) {
		state T = state();
		T.Stage = BUYING;
		T.Day = R-1;
		cout << f(T) << "\n";
	} else {
		f0(i,R-1) T = greedy(T, 0, i);
		cout << T << "\n";
	}
}
